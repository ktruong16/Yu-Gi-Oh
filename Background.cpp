//
// Created by Minec on 9/29/2020.
//

#include "Background.h"
Background::Background(){
    size_x = 200;
    size_y = 250;
    setSize({size_x, size_y});
    setFillColor(sf::Color(222, 184, 135));
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(5);
}
void Background::setBackgroundSize(float sizeX, float sizeY){
    size_x = sizeX;
    size_y = sizeY;
    setSize({size_x, size_y});
    setFillColor(sf::Color(222, 184, 135));
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(5);
}