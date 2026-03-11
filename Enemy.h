#pragma once
#include <SFML/Graphics.hpp>

class Player;

class Enemy {
    private:
    float xPos;
    float yPos;
    float speed;
    
    public:
    sf::Vector2i size;
    sf::RectangleShape boundingRectangle;
    
    sf::RectangleShape enemyShape;
    
    int health;

    public:
    Enemy();
    ~Enemy();

    void changeHealth(int hp);
    void Move(float deltaTime, Player& player);

    void Initialize();
    void Load();
    void Update(float deltaTime, Player& player);
    void Draw(sf::RenderWindow& window);
};