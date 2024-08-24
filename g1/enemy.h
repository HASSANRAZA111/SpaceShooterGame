#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
using namespace sf;
using namespace std;

class Enemy {
public:
	Sprite sprite;
	Texture texture;
	float positionX;
	float positionY;
	float speed;
	int score;
	bool isAlive;
	float directionX;
	float directionY;
	float timeSinceLastMove;
	sf::Time timeInterval;
	float timeSinceLastBomb;
	Bomb* bomb;

	Enemy() {}

	Enemy(const std::string& texturePath, float x, float y, float speed, int score)
		: positionX(x), positionY(y), speed(speed), score(score), directionX(0.20f), directionY(0.0f),
		timeSinceLastMove(0.0f), timeInterval(sf::seconds(1.0f)), timeSinceLastBomb(0.0f),
		bomb(nullptr) {
		texture.loadFromFile(texturePath);
		sprite.setTexture(texture);
		sprite.setPosition(positionX, positionY);
		isAlive = true;

	}

	virtual void move(float deltaTime) {                  //virtual function because dropbomb logic 
		positionX += directionX * speed * deltaTime;      //and time till next bomb drop is different
		positionY += directionY * speed * deltaTime;
		sprite.setPosition(positionX, positionY);

		timeSinceLastMove += deltaTime;
		timeSinceLastBomb += deltaTime;

		if (timeSinceLastMove >= 40.0f) {
			timeSinceLastMove = 0.0f;

			directionX = -directionX;
			positionY += 1;

			dropBomb();
		}
	}

	virtual void dropBomb() = 0; // pure virtual function for bomb dropping logic
};

class Invader : public Enemy {
public:
	sf::Clock clock1;

	Invader(const std::string& texturePath, float x, float y, float speed, int score)
		: Enemy(texturePath, x, y, speed, score), clock1() {}



	void dropBomb() override {
		sf::Time elapsed = clock1.getElapsedTime();

		if (elapsed >= timeInterval) {
			clock1.restart();

			int random = rand() % 4 + 1;
			if (isAlive)
			{
				// Drop a bomb with a probability of random * 10%
				if (rand() % 100 < random * 10 && bomb == nullptr) {
					bomb = new Bomb("img/bomb.png", positionX + sprite.getGlobalBounds().width / 2,
						positionY + sprite.getGlobalBounds().height / 2 + 10,
						200.0f);
				}
			}
		}
	}
};

class AlphaInvader : public Invader {
public:
	AlphaInvader(float x, float y)
		: Invader("img/enemy_1.png", x, y, 10.0f, 10) {
		timeInterval = sf::seconds(5.0f);
	}
};

class BetaInvader : public Invader {
public:
	BetaInvader(float x, float y)
		: Invader("img/enemy_2.png", x, y, 25.0f, 20) {
		timeInterval = sf::seconds(3.0f);
	}
	void move(float deltaTime) {
		positionX += directionX * speed * deltaTime;
		positionY += directionY * speed * deltaTime;
		sprite.setPosition(positionX, positionY);

		timeSinceLastMove += deltaTime;
		timeSinceLastBomb += deltaTime;

		if (timeSinceLastMove >= 30.0f) {
			timeSinceLastMove = 0.0f;

			directionX = -directionX;

			dropBomb();
		}
	}
};

class GammaInvader : public Invader {
public:
	GammaInvader(float x, float y)
		: Invader("img/enemy_3.png", x, y, 35.0f, 30) {
		timeInterval = sf::seconds(2.0f);
	}
	void move(float deltaTime) {
		positionX += directionX * speed * deltaTime;
		positionY += directionY * speed * deltaTime;
		sprite.setPosition(positionX, positionY);

		timeSinceLastMove += deltaTime;
		timeSinceLastBomb += deltaTime;

		if (timeSinceLastMove >= 10.0f) {
			timeSinceLastMove = 0.0f;

			directionX = -directionX;

			dropBomb();
		}
	}
};

class Monster : public Enemy {
public:
	sf::Clock mclock;
	int beamCount;
	bool isOnScreen;
	bool isFiring;
	Texture fireTexture;
	Sprite fireSprites[10000];
	int fireCount = 0;
	float fireTimer = 0.0;
	float fireInterval = 0.6; // time between fire
	float fireSpeed = 0.1; // beam speed
	int i = 1;
	float timeSinceStartedFiring;
	Monster(float x, float y)
		: Enemy("img/monster1.png", x, y, 3.0f, 10), beamCount(0), isOnScreen(false), isFiring(false), timeSinceStartedFiring(0.0f) {
		directionX = 10.0f;
		directionY = 0.0f;
	}

	void move(float deltaTime) override {
		if (isOnScreen) {
			if (!isFiring || timeSinceStartedFiring >= 4.0f) {
				positionX += directionX * speed * deltaTime;
				positionY += directionY * speed * deltaTime;
				sprite.setPosition(positionX, positionY);

				timeSinceLastMove += deltaTime;

				if (positionX < 0 || positionX > 500) {
					timeSinceLastMove = 0.0f;
					directionX = -directionX;
				}
			}
			else {
				timeSinceStartedFiring += deltaTime;
			}

			sf::Time elapsed = mclock.getElapsedTime();


			//drop bomb beam after 6 seconds

			if (elapsed.asSeconds() >= 6.0f) {
				dropBomb();
				mclock.restart();
			}

			//move for 4 secs
			if (timeSinceStartedFiring >= 4.0f) {
				isFiring = false;
				timeSinceStartedFiring = 0.0f;
			}
		}
	}


	void dropBomb() override {
		string filename;
		fireTimer += 0.6f;
		if (fireTimer >= fireInterval) {
			fireTimer = 0;
			fireCount = 0;

			for (int i = 1; i < 100; i++) {
				filename = "img/enemy_laser.png";
				fireTexture.loadFromFile(filename);
				fireSprites[fireCount].setTexture(fireTexture);

				float posX = sprite.getPosition().x;
				float posY = sprite.getPosition().y;

				posX += sprite.getGlobalBounds().width / 2 - 13;
				posY += (sprite.getGlobalBounds().height / 2) + 70;

				fireSprites[fireCount].setPosition(posX, posY);

				fireCount++;
			}
		}
		isFiring = !isFiring;
		timeSinceStartedFiring = 0.0f;
	}



	void firemove() {
		int j = 0;
		for (int i = 0; i < fireCount; i++) {
			float posX = fireSprites[i].getPosition().x;
			float posY = fireSprites[i].getPosition().y;

			posY += fireSpeed * (i + 1) * mclock.getElapsedTime().asSeconds();

			fireSprites[i].setPosition(posX, posY);

			if (posX > 0 && posX < 780 && posY > 0 && posY < 780) {
				fireSprites[j] = fireSprites[i];
				j++;
			}
		}
		fireCount = j;
	}
};

class Dragon : public Enemy {
public:
	sf::Clock dClock;
	bool isOnScreen;
	bool isFiring;
	Texture fireTexture;
	Sprite fireSprites[10000];
	int fireCount;
	float fireTimer = 0.0;
	float fireInterval = 0.6; // time betwwen fire
	float fireSpeed = 1; // beam speed
	int i = 1;
	float timeSinceStartedFiring;
	Player* player;

	Dragon(float x, float y, Player* player)
		: Enemy("img/dragon.png", x, y, 3.0f, 10), fireCount(0), isOnScreen(false), isFiring(false), timeSinceStartedFiring(0.0f), player(player) {
		directionX = 10.0f;
		directionY = 0.0f;
		fireTexture.loadFromFile("img/enemy_laser.png");
	}

	void dropBomb() override {
		fireTimer += 0.6f;
		if (fireTimer >= fireInterval) {
			fireTimer = 0;

			//initial pos
			float posX = sprite.getPosition().x;
			float posY = sprite.getPosition().y;

			posX += sprite.getGlobalBounds().width / 2 + 20;
			posY += (sprite.getGlobalBounds().height / 2) + 100;

			//follow direction
			float directionX = 0.0f;
			float directionY = 1.0f;
			float playerPosX = player->sprite.getPosition().x;
			float playerPosY = player->sprite.getPosition().y;
			float dragonPosX = sprite.getPosition().x;
			float dragonPosY = sprite.getPosition().y;
			float diffX = playerPosX - dragonPosX;
			float diffY = playerPosY - dragonPosY;
			directionX = diffX / sqrt(diffX * diffX + diffY * diffY);
			directionY = diffY / sqrt(diffX * diffX + diffY * diffY);

			for (int i = 1; i < 100; i++) {
				fireSprites[fireCount].setTexture(fireTexture);
				fireSprites[fireCount].setPosition(posX, posY);
				fireSprites[fireCount].setRotation(atan2(directionY, directionX) * (180 / 3.14));
				fireCount++;
			}
		}
		isFiring = !isFiring;
		timeSinceStartedFiring = 0.0f;
	}

	//function to fire in direction of player
	void firemove() {
		int j = 0;
		for (int i = 0; i < fireCount; i++) {
			float posX = fireSprites[i].getPosition().x;
			float posY = fireSprites[i].getPosition().y;

			// direction in rotation of fire
			float rotation = fireSprites[i].getRotation() * (3.14 / 180);
			float directionX = cos(rotation);
			float directionY = sin(rotation);

			posX += directionX * fireSpeed * dClock.getElapsedTime().asSeconds();
			posY += directionY * fireSpeed * dClock.getElapsedTime().asSeconds();

			fireSprites[i].setPosition(posX, posY);

			if (posX > 0 && posX < 780 && posY > 0 && posY < 780) {
				fireSprites[j] = fireSprites[i];
				j++;
			}
		}
		fireCount = j;
	}
};
