#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;

class Addons {
public:
    Sprite sprite;
    Texture texture;
    float positionX;
    float positionY;
    float speed;
    float timeSinceLastDrop; 
    Clock clock; 

    Addons(const string& texturePath, float x, float y, float speed)
        : positionX(x), positionY(y), speed(speed), timeSinceLastDrop(0.0f) {
        texture.loadFromFile(texturePath);
        sprite.setTexture(texture);
        sprite.setPosition(positionX, positionY);
    }

    virtual void move(float deltaTime) {
        positionY += speed * deltaTime;
        sprite.setPosition(positionX, positionY);
    }
    string type; 
};

class PowerUp : public Addons {
public:
    PowerUp(float x, float y)
        : Addons("img/PNG/Power-ups/bolt_gold.png", x, y, 300.0f) {
        type = "PowerUp";
    }
};

class Fire : public Addons {
public:
    Fire(float x, float y)
        : Addons("img/PNG/Power-ups/star_gold.png", x, y, 100.0f) {
        type = "Fire";
    }
};

class Danger : public Addons {
public:
    Danger(float x, float y)
        : Addons("img/PNG/Power-ups/powerupRed_bolt.png", x, y, 100.0f) {
        type = "Danger";
    }
};

class LivesAddon : public Addons {
public:
    LivesAddon(float x, float y)
        : Addons("img/heart2.png", x, y, 100.0f) {
        type = "LivesAddon";
    }
};
