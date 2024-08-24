#include <cmath>
using namespace std;

class Level {
public:
	static const int MAX_ENEMIES = 200;
	Enemy* enemies[MAX_ENEMIES];
	int enemyCount;
	int phase;
	bool showEnemies;

	Level() {
		enemyCount = 0;
		phase = 1;
		showEnemies = true;
	}

	void removeEnemy(int index) {
		if (index >= 0 && index < enemyCount) {
			enemies[index]->isAlive = false;
		}
	}

	void updateEnemies(float deltaTime) {
		bool reverseDirection = false;
		if (enemyCount > 0) {
			Enemy* firstEnemy = enemies[0];
			if (firstEnemy->positionX < 50 || firstEnemy->positionX > 750) {
				reverseDirection = true;
			}
		}

		for (int i = 0; i < enemyCount; i++) {
			enemies[i]->move(deltaTime);

			if (reverseDirection) {
				enemies[i]->directionX = -enemies[i]->directionX;
				enemies[i]->positionY += 50;
			}
		}
	}

	void addEnemy(Enemy* enemy) {
		if (enemyCount < MAX_ENEMIES) {
			enemies[enemyCount++] = enemy;
		}
	}

	virtual void nextPhase() = 0; // pure virtual fuction
};


//level 1
class Level1 : public Level {
public:
	Level1() {
		createLevel1();
	}

	void createLevel1() {
		int spacing = 90; // gap
		//Left side vertical enemies
		for (int i = 0; i < 4; i++) {
			addEnemy(new AlphaInvader(50, 50 + i * spacing));
		}

		//toop horizonntal enemies
		for (int i = 0; i < 5; i++) {
			addEnemy(new AlphaInvader(50 + (i + 1) * spacing, 50));
		}

		//bottom hhorizontal enemies
		for (int i = 0; i < 5; i++) {
			addEnemy(new AlphaInvader(50 + (i + 1) * spacing, 50 + 3 * spacing));
		}

		//rihhgt side vertical enemies
		for (int i = 0; i < 4; i++) {
			addEnemy(new AlphaInvader(50 + 6 * spacing, 50 + i * spacing));
		}


	}


	void nextPhase() override {
		phase++;
		if (phase == 2) {
			//triangle shape
			float spacing = 55.0f; // New spacing variable

			//Top sprite
			addEnemy(new AlphaInvader(350, 50));

			//Left side sprites
			for (int i = 1; i <= 5; i++) {
				addEnemy(new AlphaInvader(350 - i * spacing, 50 + i * spacing));
			}

			//Right side sprites
			for (int i = 1; i <= 5; i++) {
				addEnemy(new AlphaInvader(350 + i * spacing, 50 + i * spacing));
			}

			//bBottom sprites
			for (int i = -2; i <= 3; i++) {
				addEnemy(new AlphaInvader(310 + i * 80, 50 + 5 * 60));
			}
		}

		else if (phase == 3)
		{
			//cross sign shape
			for (int i = 0; i < 6; i++) {
				addEnemy(new AlphaInvader(115 + i * 80, 50 + i * 40));
				addEnemy(new AlphaInvader(115 + i * 80, 290 - i * 40));
			}
			addEnemy(new AlphaInvader(580, 300));
			addEnemy(new AlphaInvader(580, 45));
		}
	}


};


//level 2
class Level2 : public Level {
public:
	Level2() {
		createLevel2();
	}

	void createLevel2()
	{
		int numEnemies = 16; //boundary
		float radius = 200;

		for (int i = 0; i < numEnemies; i++) {
			float angle = 2 * 3.14159265 * i / numEnemies;
			float x = 350 + radius * cos(angle);
			float y = 225 + radius * sin(angle);
			addEnemy(new BetaInvader(x, y));
		}

	}

	void nextPhase() override
	{
		phase++;
		if (phase == 2) {
			int spacing = 55; //gap
			int offset = 35; // more gap

			// diamond shape enemies
			int diamondHeight = 5;
			int diamondWidth = 10;
			int centerX = diamondWidth / 2;

			for (int i = 0; i < diamondHeight; i++) {
				addEnemy(new BetaInvader(50 + (centerX - i) * spacing, 50 + i * spacing - 40));
				addEnemy(new BetaInvader(50 + (centerX + i) * spacing, 50 + i * spacing - 40));
			}

			for (int i = diamondHeight - 2; i >= 0; i--) {
				addEnemy(new BetaInvader(50 + (centerX - i) * spacing, 50 + (diamondHeight * 2 - i - 1) * spacing - offset - 40));
				addEnemy(new BetaInvader(50 + (centerX + i) * spacing, 50 + (diamondHeight * 2 - i - 1) * spacing - offset - 40));
			}
		}

		else if (phase == 3)
		{
			int n = 7; // heart size
			float spacing = 69.0f; // gap

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i == 0 && (j >= n / 5 && j <= n / 2 - n / 5) || i == 0 && (j >= n / 2 + n / 5 && j <= (n - 1) - n / 5))
						addEnemy(new BetaInvader(50 + j * spacing, 50 + i * spacing));
					else if (i > 0 && i <= n / 5 && (j == n / 5 - i || j == n / 2 + n / 5 - i || j == n / 2 - n / 5 + i || j == (n - 1) - n / 5 + i))
						addEnemy(new BetaInvader(50 + j * spacing, 50 + i * spacing));
					else if ((i > n / 5 && i <= n / 2) && (j == 0 || j == n - 1))
						addEnemy(new BetaInvader(50 + j * spacing, 50 + i * spacing));
					else if (i > n / 2 && (j == i - n / 2 || j == (n - 1) - (i - n / 2)))
						addEnemy(new BetaInvader(50 + j * spacing, 50 + i * spacing));
				}
			}
		}
	}


};


//level 3
class Level3 : public Level {
public:
	Level3() {
		createLevel3();
	}

	void createLevel3() {
		int spacing = 90; // gap between enemyy
		int rows = 2;
		int columns = 6;

		//filled
		for (int i = 0; i <= rows; i++) {
			for (int j = 0; j <= columns; j++) {
				addEnemy(new GammaInvader(50 + j * spacing, 50 + i * spacing));
			}
		}

	}

	void nextPhase() override
	{
		phase++;
		if (phase == 2) {
			//triangle shape
			float spacing = 55.0f; // New spacing variable

			//Top sprite
			addEnemy(new GammaInvader(350, 50));

			//Left side sprites
			for (int i = 1; i <= 5; i++) {
				addEnemy(new GammaInvader(350 - i * spacing, 50 + i * spacing));

				// Filling the inner area of tringle
				for (int j = 1; j < i; j++) {
					addEnemy(new GammaInvader(350 - i * spacing + j * spacing + 25, 50 + i * spacing));
				}
			}

			//Right side sprites
			for (int i = 1; i <= 5; i++) {
				addEnemy(new GammaInvader(350 + i * spacing, 50 + i * spacing));

				// Filling the inner area of the triangle
				for (int j = 1; j < i; j++) {
					addEnemy(new GammaInvader(350 + i * spacing - j * spacing, 50 + i * spacing));
				}
			}
		}

		else if (phase == 3)
		{
			//cross sign shape
			for (int i = 0; i < 6; i++) {
				addEnemy(new GammaInvader(115 + i * 80, 50 + i * 40));
				addEnemy(new GammaInvader(115 + i * 80, 290 - i * 40));
			}
			addEnemy(new GammaInvader(580, 300));
			addEnemy(new GammaInvader(580, 45));
		}
		else if (phase == 4)
		{
			int numEnemies = 15; //boundary
			float maxRadius = 200;
			for (float radius = 100; radius <= maxRadius; radius += 90) {
				for (int i = 0; i < numEnemies; i++) {
					float angle = 2 * 3.14159265 * i / numEnemies;
					float x = 350 + radius * cos(angle);
					float y = 225 + radius * sin(angle);
					addEnemy(new GammaInvader(x, y));
				}
			}

		}

		else if (phase == 5)
		{

			int spacing = 55; // gap
			int offset = 35;

			// Diamond shape enemies
			int diamondHeight = 4;
			int diamondWidth = 9;
			int centerX = diamondWidth / 2;

			for (int i = 0; i < diamondHeight; i++) {
				for (int j = centerX - i; j <= centerX + i; j++) {
					addEnemy(new GammaInvader(50 + j * spacing, 50 + i * spacing - 40));
				}
			}

			for (int i = diamondHeight - 2; i >= 0; i--) {

				for (int j = centerX - i; j <= centerX + i; j++) {
					addEnemy(new GammaInvader(50 + j * spacing, 50 + (diamondHeight * 2 - i - 1) * spacing - offset - 40));
				}
			}

		}

		else if (phase == 6)
		{
			int n = 7; // heart sizee in colomn
			float spacing = 69.0f; // gap

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i == 0 && (j >= n / 5 && j <= n / 2 - n / 5) || i == 0 && (j >= n / 2 + n / 5 && j <= (n - 1) - n / 5))
						addEnemy(new GammaInvader(50 + j * spacing, 50 + i * spacing));
					else if (i > 0 && i <= n / 5 && (j >= n / 5 - i && j <= n / 2 + n / 5 - i || j >= n / 2 - n / 5 + i && j <= (n - 1) - n / 5 + i))
						addEnemy(new GammaInvader(50 + j * spacing, 50 + i * spacing));
					else if ((i > n / 5 && i <= n / 2) && (j >= 0 && j <= i - n / 5 || j >= (n - 1) - (i - n / 5) && j <= n - 1))
						addEnemy(new GammaInvader(50 + j * spacing, 50 + i * spacing));
					else if (i > n / 2 && (j >= i - n / 2 && j <= (n - 1) - (i - n / 2)))
						addEnemy(new GammaInvader(50 + j * spacing, 50 + i * spacing));
				}
			}
		}
	}


};
