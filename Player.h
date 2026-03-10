#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Player {
    private:
    std::vector<Bullet> bullets;

    float maxFireRate;
    float fireRateTimer;
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
    void Update(float deltaTime, sf::Vector2f& mousePosition);
    void Draw(sf::RenderWindow& window);
};