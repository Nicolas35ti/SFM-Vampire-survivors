#pragma once
#include <SFML/Graphics.hpp>

class Player {
    private:
    float playerSpeed;

    sf::RectangleShape boundingRectangle;

    sf::Vector2i size;

    public:
    sf::RectangleShape characterShape;

    public:
    Player();
    ~Player();

    void Initialize();
    void Load();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
};