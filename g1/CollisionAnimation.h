#include <SFML/Graphics.hpp>

class CollisionAnimation {
public:
    CollisionAnimation(sf::Sprite& enemy1, sf::Sprite& enemy2) : enemy1(enemy1), enemy2(enemy2), state(MOVING) {}

    void update(float deltaTime) {
        if (state == MOVING) {
            // Move the enemies towards each other
            enemy1.move(velocity1 * deltaTime);
            enemy2.move(velocity2 * deltaTime);

            // Check for collision
            if (enemy1.getGlobalBounds().intersects(enemy2.getGlobalBounds())) {
                // Collision detected
                state = SHRINKING;
            }
        } else if (state == SHRINKING) {
            // Scale down enemies
            enemy1.scale(1 - shrinkSpeed * deltaTime, 1 - shrinkSpeed * deltaTime);
            enemy2.scale(1 - shrinkSpeed * deltaTime, 1 - shrinkSpeed * deltaTime);

            // Check if enemies have disappeared
            if (enemy1.getScale().x <= 0 || enemy2.getScale().x <= 0) {
                // Animation complete
            }
        }
    }

private:
    sf::Sprite& enemy1;
    sf::Sprite& enemy2;
    sf::Vector2f velocity1 = {-100, 0};
    sf::Vector2f velocity2 = {100, 0};
    float shrinkSpeed = 2;
    enum State { MOVING, SHRINKING };
    State state;
};
