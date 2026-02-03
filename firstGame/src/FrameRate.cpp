#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate() :frameRateText(font),timer(0) {

}

FrameRate::~FrameRate(){

}

void FrameRate::Initialize()
{
}

void FrameRate::Load(){
    if (font.openFromFile("Assets/Fonts/arial.ttf")) {
        std::cout << "fonts loaded" << std::endl;
        frameRateText.setFont(font);
    }
    else {
        std::cout << "fonts fail to load" << std::endl;
    }
}

void FrameRate::Update(double deltatime){
    frameRateText.setCharacterSize(24);
    frameRateText.setFillColor(sf::Color::Red);

    timer += deltatime;

    if (timer >= 100.0f) {
        double fps = 1000 / deltatime;
        std::string fpsString = "fps:" + std::to_string((int)fps) + " famre:" + std::to_string((int)deltatime);
        frameRateText.setString(fpsString);
        timer = 0;
    }
}

void FrameRate::Draw(sf::RenderWindow& window){

    window.draw(frameRateText);
}
