//
// Created by Minec on 11/25/2020.
//

#ifndef FINAL_PROJECT_NAME_H
#define FINAL_PROJECT_NAME_H

#include <SFML/Graphics.hpp>
#include "MonsterCardList.h"
using namespace mc;
class Name : public sf::Text{
private:
    sf::Font name;      //name of the monster
public:
    //constructors
    Name();
    Name(Monsters theName);
    //setters
    void setPosition(sf::FloatRect bounds);
    void setName(Monsters newName);
};


#endif //FINAL_PROJECT_NAME_H
