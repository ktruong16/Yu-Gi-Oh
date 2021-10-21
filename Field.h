//
// Created by Minec on 12/1/2020.
//

#ifndef FINAL_PROJECT_FIELD_H
#define FINAL_PROJECT_FIELD_H

#include <SFML/Graphics.hpp>
#include "MonsterCardList.h"
using namespace mc;
class Field : public sf::Drawable, sf::Transformable{
private:
    sf::RectangleShape field1, field2, field3;          //drawable rectangle field
    Monsters field[3];                                  //contains monster data
public:
    //constructor
    Field();
    Field(float yPos, sf::Color pattern[]);
    //getters
    sf::FloatRect getField1Bounds();
    sf::FloatRect getField2Bounds();
    sf::FloatRect getField3Bounds();
    sf::Vector2f getPositionOfField(int numberField);
    Monsters getFieldMonsters(int fieldNum);
    sf::Color getFieldColor(int fieldNum);
    //functions
    void eraseField();
    void insert(Monsters card, int fieldSpot);
    void changePatternTo(sf::Color pattern[]);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};


#endif //FINAL_PROJECT_FIELD_H
