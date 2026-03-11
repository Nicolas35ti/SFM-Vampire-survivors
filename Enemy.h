#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
    private:
    
    public:
    sf::Vector2i size;
    sf::RectangleShape boundingRectangle;
    
    sf::RectangleShape enemyShape;
    
    int health;

    public:
    Enemy();
    ~Enemy();

    void changeHealth(int hp);

    void Initialize();
    void Load();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
};