#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "FrameRate.h"

int main() {
    // ------------------ INITIALIZE
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Vampire Survivors SFML", sf::Style::Default, settings);
    window.setFramerateLimit(360);
    //-------------------
    FrameRate frameRate;
    Player player;

    frameRate.Initialize();
    player.Initialize();

    frameRate.Load();
    player.Load();

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

        frameRate.Update(deltaTime);
        player.Update(deltaTime);
        // -----------------------
        window.clear(sf::Color::Black);

        frameRate.Draw(window);
        player.Draw(window);

        window.display();
    }
    return 0;
}