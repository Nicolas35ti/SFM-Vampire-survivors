#include "Player.h"
#include "Math.h"

Player::Player() : playerSpeed(1.0f), maxFireRate(150), fireRateTimer(0)
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

void Player::Update(float deltaTime, sf::Vector2f& mousePosition)
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
    
    fireRateTimer += deltaTime;

    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate) {
        bullets.push_back(Bullet());
        int i = bullets.size() -1;
        bullets[i].Initialize(characterShape.getPosition(), mousePosition, 0.5f);
        fireRateTimer = 0;
    }

    for (size_t i = 0; i < bullets.size(); i++) {
        bullets[i].Update(deltaTime);
    }
}

void Player::Draw(sf::RenderWindow &window)
{
    window.draw(characterShape);

    //para renderizar o vetor das bullets
    for (size_t i = 0; i < bullets.size(); i++) {
        bullets[i].Draw(window);
    }
}
