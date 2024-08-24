#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;

class Bomb {
public:
    Sprite sprite;
    Texture texture;
    Vector2f position;
    float speed;

    Bomb(const std::string& texturePath, float x, float y, float speed)
        : position(x, y), speed(speed) {
        texture.loadFromFile(texturePath);
        sprite.setTexture(texture);

        sprite.setPosition(position);
		
    }

    virtual void move(float deltaTime) {
        position.y += speed * deltaTime;
        sprite.setPosition(position);
    }
};