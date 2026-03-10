#include "Player.h"

Player::Player() : playerSpeed(1.0f)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
}

void Player::Load()
{
    characterShape.setSize(sf::Vector2f(50, 100));
    characterShape.setPosition(sf::Vector2f(100, 100));
    characterShape.setFillColor(sf::Color::Blue);
}

void Player::Update(float deltaTime)
{
    sf::Vector2f position = characterShape.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        characterShape.setPosition(position + sf::Vector2f(0, -1) * playerSpeed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        characterShape.setPosition(position + sf::Vector2f(-1, 0) * playerSpeed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        characterShape.setPosition(position + sf::Vector2f(0, 1) * playerSpeed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        characterShape.setPosition(position + sf::Vector2f(1, 0) * playerSpeed * deltaTime);
}

void Player::Draw(sf::RenderWindow &window)
{
    window.draw(characterShape);
}
