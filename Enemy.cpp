#include "Enemy.h"
#include "Player.h"
#include "Math.h"
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

//movimrnto do inimigo, faz ele perseguir o player
void Enemy::Move(float deltaTime, Player& player) {
    sf::Vector2f playerPosition = player.characterShape.getPosition();
    sf::Vector2f thisPosition = enemyShape.getPosition();
    sf::Vector2f direction = Math::NormalizeVector(playerPosition - thisPosition);

    speed = 0.5f;

    enemyShape.move (direction * speed * deltaTime);
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

void Enemy::Update(float deltaTime, Player& player)
{
    if (health > 0) {
        boundingRectangle.setPosition(enemyShape.getPosition());
        Move(deltaTime, player);
    }
}

void Enemy::Draw(sf::RenderWindow &window)
{
    if (health > 0) {
        window.draw(enemyShape);
        window.draw(boundingRectangle);
    }
}
