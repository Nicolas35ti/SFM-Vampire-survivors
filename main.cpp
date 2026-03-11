#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "FrameRate.h"
#include "Enemy.h"

int main() {
    // ------------------ INITIALIZE
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Vampire Survivors SFML", sf::Style::Default, settings);
    window.setFramerateLimit(360);
    //-------------------
    FrameRate frameRate;
    Player player;
    Enemy enemy;

    frameRate.Initialize();
    player.Initialize();
    enemy.Initialize();

    frameRate.Load();
    player.Load();
    enemy.Load();

    //---------------- LOAD

    sf::Clock clock;
    double deltaTime;
    while(window.isOpen()) {
        sf::Time deltaTimeTimer = clock.restart();
        double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;
        // ---------------- UPDATE
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

        frameRate.Update(deltaTime);
        player.Update(deltaTime, enemy, mousePosition);
        enemy.Update(deltaTime, player);
        // -----------------------
        window.clear(sf::Color::Black);

        frameRate.Draw(window);
        player.Draw(window);
        enemy.Draw(window);

        window.display();
    }
    return 0;
}