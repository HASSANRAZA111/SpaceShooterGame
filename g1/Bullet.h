#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
using namespace sf;

class Bullet
{
public:
	Texture fireTexture;
	Sprite fireSprites[1000];
	string fireDirections[1000];
	int fireCount = 0;
	float fireTimer = 0.0;
	float fireInterval = 0.6; // each fjre tkme
	float fireSpeed = 2; // pixel speed
	Clock clock;
	string direction; //direction of fire
	int i = 1;

	void fire(float time, Sprite sprite, string direction) {
		string filename;
		fireTimer += time;
		if (fireTimer >= fireInterval) {
			fireTimer = 0;
			if (i < 8)
				filename = "img/PNG/Effects/fire0" + to_string(i) + ".png";

			fireTexture.loadFromFile(filename);
			fireSprites[fireCount].setTexture(fireTexture);

			//inital pos
			float posX = sprite.getPosition().x;
			float posY = sprite.getPosition().y;

			posX += sprite.getGlobalBounds().width / 2 - 6;
			posY += (sprite.getGlobalBounds().height / 2) - 50;

			fireSprites[fireCount].setPosition(posX, posY);

			//from game.h dirctions will come

			fireDirections[fireCount] = direction;

			i++;
			if (i >= 8)
				i = 1;
			fireCount++;
		}
	}

	float fireTimes[1000];

	void firePowerUp(float time, Sprite sprite, float fireInterval) {
		string filename;
		string directions[7] = { "u", "l", "r", "ul", "ur", "dl", "dr" };

		fireTimer += time;
		if (fireTimer >= fireInterval) {
			fireTimer = 0;
			if (i < 8)
				filename = "img/PNG/Effects/fire0" + to_string(i) + ".png";

			fireTexture.loadFromFile(filename);

			for (int j = 0; j < 7; j++) {
				fireSprites[fireCount].setTexture(fireTexture);

				float posX = sprite.getPosition().x;
				float posY = sprite.getPosition().y;

				posX += sprite.getGlobalBounds().width / 2 - 6;
				posY += (sprite.getGlobalBounds().height / 2) - 50;

				fireSprites[fireCount].setPosition(posX, posY);
				fireDirections[fireCount] = directions[j];
				fireCount++;
			}

			i++;
			if (i >= 8)
				i = 1;
		}
	}


	void firemovePowerUp(float fireSpeed) {
		for (int i = 0; i < fireCount; i++) {
			float posX = fireSprites[i].getPosition().x;
			float posY = fireSprites[i].getPosition().y;

			string dir = fireDirections[i];

			if (dir == "u") posY -= fireSpeed;
			else if (dir == "d") posY += fireSpeed;
			else if (dir == "l") posX -= fireSpeed;
			else if (dir == "r") posX += fireSpeed;
			else if (dir == "ul") { posX -= fireSpeed; posY -= fireSpeed; }
			else if (dir == "ur") { posX += fireSpeed; posY -= fireSpeed; }
			else if (dir == "dl") { posX -= fireSpeed; posY += fireSpeed; }
			else if (dir == "dr") { posX += fireSpeed; posY += fireSpeed; }

			fireSprites[i].setPosition(posX, posY);
		}
	}


	void fireAddEffect(float time, Sprite sprite, string direction, float fireInterval = 0.0) {
		string filename;
		fireTimer += time;
		if (fireTimer >= fireInterval) {
			fireTimer = 0;
			if (i < 8)
				filename = "img/PNG/Effects/fire0" + to_string(i) + ".png";

			fireTexture.loadFromFile(filename);
			fireSprites[fireCount].setTexture(fireTexture);

			//initial pos
			float posX = sprite.getPosition().x;
			float posY = sprite.getPosition().y;

			posX += sprite.getGlobalBounds().width / 2 - 6;
			posY += (sprite.getGlobalBounds().height / 2) - 50;

			fireSprites[fireCount].setPosition(posX, posY);
			//from game.h

			fireDirections[fireCount] = direction;

			i++;
			if (i >= 8)
				i = 1;
			fireCount++;
		}
	}



	void firemove()
	{
		int j = 0;
		for (int i = 0; i < fireCount; i++) {
			float posX = fireSprites[i].getPosition().x;
			float posY = fireSprites[i].getPosition().y;
			string dir = fireDirections[i];

			if (dir == "u") posY -= fireSpeed;
			else if (dir == "d") posY += fireSpeed;
			else if (dir == "l") posX -= fireSpeed;
			else if (dir == "r") posX += fireSpeed;
			else if (dir == "ul") { posX -= fireSpeed; posY -= fireSpeed; }
			else if (dir == "ur") { posX += fireSpeed; posY -= fireSpeed; }
			else if (dir == "dl") { posX -= fireSpeed; posY += fireSpeed; }
			else if (dir == "dr") { posX += fireSpeed; posY += fireSpeed; }

			fireSprites[i].setPosition(posX, posY);

			if (posX > 0 && posX < 780 && posY > 0 && posY < 780) {
				fireSprites[j] = fireSprites[i];
				fireDirections[j] = fireDirections[i];
				j++;
			}
		}
		fireCount = j;
	}


};