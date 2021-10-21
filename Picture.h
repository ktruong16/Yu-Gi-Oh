//
// Created by Minec on 11/25/2020.
//

#ifndef FINAL_PROJECT_PICTURE_H
#define FINAL_PROJECT_PICTURE_H

#include <SFML/Graphics.hpp>
#include <string>
#include "MonsterCardList.h"
using namespace std;
using namespace mc;
class Picture : public sf::Drawable, sf::Transformable{
public:
    //constructors
    Picture();
    Picture(Monsters monster);
    //setters
    void setPicture(Monsters monster);
    void setPosition(sf::FloatRect bounds);
    //getters
    string getImagePath(Monsters monster);
    //functions
    void draw(sf::RenderTarget &window, sf::RenderStates state) const;
private:
    sf::Sprite picture;         //visible picture
    sf::Texture texture;        //load file onto picture
};


#endif //FINAL_PROJECT_PICTURE_H
