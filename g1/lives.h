class Lives {
private:
	int initialLives = 3;
	int lives;

public:
	Lives() {
		lives = initialLives;
	}

	void increaseLives() {
		lives++;
	}

	void decreaseLives() {
		if (lives > 0) {
			lives--;
		}
	}

	int getLives() {
		return lives;
	}
};
