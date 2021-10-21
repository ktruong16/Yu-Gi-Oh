//
// Created by Minec on 11/30/2020.
//

#ifndef FINAL_PROJECT_PLAYER_H
#define FINAL_PROJECT_PLAYER_H

#include "StackDeck.h"
#include "Card.h"
#include "Field.h"
using namespace std;
class Player : public sf::Drawable, sf::Transformable{
private:
    Card monsterFirst, monsterSecond, monsterThird;
public:
    //constructor
    Player(StackDeck deck);
    Player(StackDeck deck, float yPosition);
    //getters
    Card getMonsterFirst();
    Card getMonsterSecond();
    Card getMonsterThird();
    //functions
    void moveMonsterCard(int monsterSelect, Field field, int fieldNumber);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};


#endif //FINAL_PROJECT_PLAYER_H
