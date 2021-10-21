//
// Created by Minec on 11/30/2020.
//

#ifndef FINAL_PROJECT_STACKDECK_H
#define FINAL_PROJECT_STACKDECK_H

#include <iostream>
#include "MonsterCardList.h"
using namespace mc;
class StackDeck {
private:
    struct MonsterCard{
        Monsters monster;
        MonsterCard* next;
    };
    MonsterCard* top;
public:
    //constructor
    StackDeck();
    //getter
    Monsters getMonster();
    //functions
    void push(Monsters newMonster);
    void pop();
    bool isEmpty();
    void display();
};


#endif //FINAL_PROJECT_STACKDECK_H
