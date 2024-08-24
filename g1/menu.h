#include <SFML/Audio.hpp>

class Menu {
public:
	sf::Sprite background;
	sf::Text options[6];
	int selected;
	sf::Font font;
	sf::Texture backgroundTexture;
	bool musicOn;
	Menu() {
		backgroundTexture.loadFromFile("img/menu.png");
		background.setTexture(backgroundTexture);

		// load font
		font.loadFromFile("assets/Poppins-Regular.ttf");
		bool musicOn = false;
		// set text for each menu option
		options[0].setString("Start Game");
		options[1].setString("Resume");
		options[2].setString("High Scores");
		options[3].setString("Instructions");
		options[4].setString("Music Off");
		options[5].setString("Exit");

		// set font and character size for each menu option
		for (int i = 0; i < 6; i++) {
			options[i].setFont(font);
			options[i].setCharacterSize(24);
		}

		selected = 0;
	}

	void toggleMusic() {
		musicOn = !musicOn;
		if (musicOn) {
			options[4].setString("Music On");
		}
		else {
			options[4].setString("Music Off");
		}
	}

	bool isMusicOn() const {
		return musicOn;
	}


	void draw(sf::RenderWindow& window) {
		// draw background
		window.draw(background);

		// get window size
		unsigned int windowSizeX = window.getSize().x;
		unsigned int windowSizeY = window.getSize().y;
		float spacing = 20;

		// draw and center menu options
		for (int i = 0; i < 6; i++) {
			// get text bounds
			float textWidth = options[i].getCharacterSize() * options[i].getString().getSize();
			float textHeight = options[i].getCharacterSize();

			// calculate x and y position
			float x = (windowSizeX - textWidth) / 2;
			float y = (windowSizeY - (textHeight + spacing) * 6) / 2 + i * (textHeight + spacing);

			// set position and draw text
			options[i].setPosition(x, y);

			// highlight selected option
			if (i == selected) {
				options[i].setFillColor(sf::Color::White);
				options[i].setStyle(sf::Text::Bold);
				options[i].setStyle(sf::Text::Italic);
			}
			else {
				options[i].setFillColor(sf::Color::Yellow);
				options[i].setStyle(sf::Text::Regular);
			}

			window.draw(options[i]);
		}
	}




	void moveUp() {
		// move selection up
		if (selected > 0) {
			selected--;
		}
	}

	void moveDown() {
		// move selection down
		if (selected < 5) {
			selected++;
		}
	}

	int select() {
		return selected;
	}

};
