//
// Created by Minec on 12/6/2020.
//

#ifndef FINAL_PROJECT_DAMAGE_H
#define FINAL_PROJECT_DAMAGE_H

#include "SFML/Graphics.hpp"
#include "Field.h"
class Damage : public sf::Drawable, sf::Transformable{
private:
    int dmgTaken;               //damage taken in integer form
    sf::Font font;              //font of text
    sf::Text textDmg;           //drawable text
    int attackDmg(Monsters monster);            //gets attack dmg of monster
    int defenseDmg(Monsters monster);           //gets defense dmg of monster
public:
    //constructor
    Damage();
    Damage(int dmg, float xPosition);
    //getter
    int getDmgTaken();
    //function
    void changePosition(float yPosition);
    void damageCalculation(Field player, Field ai, int fieldNumber);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};


#endif //FINAL_PROJECT_DAMAGE_H
