#include "Enemy.h"
#include <iostream>

Enemy::Enemy() : health(100)
{
}

Enemy::~Enemy()
{
}

void Enemy::changeHealth(int hp)
{
    health += hp;
}

void Enemy::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(32, 64);

    
}

void Enemy::Load()
{
    enemyShape.setSize(sf::Vector2f(35, 75));
    enemyShape.setPosition(sf::Vector2f(700, 100));
    enemyShape.setFillColor(sf::Color::Red);

    boundingRectangle.setSize(sf::Vector2f(size.x * enemyShape.getScale().x, size.y * enemyShape.getScale().y));
}

void Enemy::Update(float deltaTime)
{
    if (health > 0) {
        boundingRectangle.setPosition(enemyShape.getPosition());
    }
}

void Enemy::Draw(sf::RenderWindow &window)
{
    if (health > 0) {
        window.draw(enemyShape);
        window.draw(boundingRectangle);
    }
}
