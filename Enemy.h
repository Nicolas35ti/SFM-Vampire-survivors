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
    
    sf::RectangleShape lifeBarRect1;
    sf::RectangleShape lifeBarrect2;
    
    int health;
    int maxHealth;
    float maxLBWidth;

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