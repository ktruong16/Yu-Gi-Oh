//
// Created by Minec on 9/29/2020.
//

#ifndef DRAWCARD_SFML_BACKGROUND_H
#define DRAWCARD_SFML_BACKGROUND_H

#include <SFML/Graphics.hpp>
class Background : public sf::RectangleShape{
private:
    float size_x, size_y;       //size of the background
public:
    //constructor
    Background();
    //setter
    void setBackgroundSize(float sizeX, float sizeY);
};


#endif //DRAWCARD_SFML_BACKGROUND_H
