#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate() : timer(0)
{
}

FrameRate::~FrameRate()
{
}

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
    if(font.loadFromFile("assets/fonts/Cormorant-Bold.ttf")) {
        std::cout << "Cormorant-Bold.ttf fonte carregou corretameente!" << std::endl;
        frameRateText.setFont(font);
    } else {
        std::cout << "Falha ao carregar Cormorant-Bold.ttf fonte" << std::endl;
    }
}

void FrameRate::Update(double deltaTime)
{
    timer += deltaTime;

    if (timer >= 100.0) {
        double fps = 1000.0 / deltaTime;

        frameRateText.setString("FPS: " + std::to_string((int)fps) + " | frameTime: " + std::to_string((int)(deltaTime)));
        timer = 0;
    }
}

void FrameRate::Draw(sf::RenderWindow &window)
{
    window.draw(frameRateText);
}
