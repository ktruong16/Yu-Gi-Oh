//
// Created by Minec on 11/23/2020.
//

#include "Card.h"
Card::Card() : Card(BlueEyesWhiteDragon){
    monsterListName = BlueEyesWhiteDragon;
}
Card::Card(const Card &monster){
    monsterListName = monster.monsterListName;                          //monsterList
    setPosition(monster.getPosition().x, monster.getPosition().y);      //set position of card
    this->picture.setPicture(monster.monsterListName);                  //create picture of card
    this->name.setName(monster.monsterListName);                        //create text of card
    this->stats.setStats(monster.monsterListName);                      //text of monster stats
}
Card::Card(Monsters monster){
    monsterListName = monster;
    setPosition(100,100);
    this->picture.setPicture(monster);
    this->name.setName(monster);
    this->stats.setStats(monster);
}
Monsters Card::getMonsterName(){
    return monsterListName;
}
void Card::changeCardTo(Card monster){
    //given a new card, the variable will switch to that new card
    monsterListName = monster.monsterListName;
    this->picture.setPicture(monster.monsterListName);
    this->name.setName(monster.monsterListName);
    this->stats.setStats(monster.monsterListName);
}
void Card::setPosition(float x, float y){
    //adjust all of the other parts of the card if card is moved
    this->background.setPosition(x, y);
    this->picture.setPosition(background.getGlobalBounds());
    this->name.setPosition(background.getGlobalBounds());
    this->stats.setAttackPosition(background.getGlobalBounds());
    this->stats.setDefensePosition(background.getGlobalBounds());
}
void Card::draw(sf::RenderTarget &window, sf::RenderStates state) const{
    window.draw(this->background);
    window.draw(this->picture);
    window.draw(this->name);
    window.draw(this->stats);
}