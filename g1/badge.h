class Badge
{
public:
    sf::Texture texture;
    sf::Sprite sprite;

    Badge(const std::string& textureFile)
    {
        texture.loadFromFile(textureFile);
        sprite.setTexture(texture);
    }
};
