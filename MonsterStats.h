//
// Created by Minec on 12/8/2020.
//

#ifndef FINAL_PROJECT_MONSTERSTATS_H
#define FINAL_PROJECT_MONSTERSTATS_H

#include <SFML/Graphics.hpp>
#include "MonsterCardList.h"
using namespace mc;
class MonsterStats : public sf::Drawable, sf::Transformable{
private:
    sf::Font font;                      //create font
    sf::Text attackDmg, defenseDmg;     //attack dmg & defense dmg text
public:
    //constructors
    MonsterStats();
    MonsterStats(Monsters monster);
    //setters
    void setAttackPosition(sf::FloatRect bounds);
    void setDefensePosition(sf::FloatRect bounds);
    void setStats(Monsters monster);
    //functions
    void draw(sf::RenderTarget &window, sf::RenderStates state) const;
};


#endif //FINAL_PROJECT_MONSTERSTATS_H
