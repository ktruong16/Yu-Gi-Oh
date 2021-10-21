//
// Created by Minec on 11/23/2020.
//

#ifndef FINAL_PROJECT_CARD_H
#define FINAL_PROJECT_CARD_H

#include "Background.h"
#include "Picture.h"
#include "Name.h"
#include "MonsterStats.h"
class Card : public sf::Drawable, sf::Transformable{
public:
    //constructor
    Card();
    Card(Monsters monster);
    //copy
    Card(const Card &monster);
    //member function
    Monsters getMonsterName();
    void changeCardTo(Card monster);
    void setPosition(float x, float y);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;
private:
    Monsters monsterListName;   //enum monsterList
    Background background;      //background of the monster card
    Picture picture;            //monster card picture
    Name name;                  //the name of the monster card
    MonsterStats stats;         //contains data of monster card
};


#endif //FINAL_PROJECT_CARD_H
