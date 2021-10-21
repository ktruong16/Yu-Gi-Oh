//
// Created by Minec on 11/30/2020.
//

#include "Player.h"
Player::Player(StackDeck deck){
    //draw cards in deck
    Card monster1(deck.getMonster());
    deck.pop();
    Card monster2(deck.getMonster());
    deck.pop();
    Card monster3(deck.getMonster());

    //assign card hand to draw cards
    this->monsterFirst.changeCardTo(monster3);
    this->monsterSecond.changeCardTo(monster2);
    this->monsterThird.changeCardTo(monster1);

    //set position of player card hand
    this->monsterFirst.setPosition(600, 750);
    this->monsterSecond.setPosition(900, 750);
    this->monsterThird.setPosition(1200, 750);
}
Player::Player(StackDeck deck, float yPosition){
    //draw cards in deck
    Card monster1(deck.getMonster());
    deck.pop();
    Card monster2(deck.getMonster());
    deck.pop();
    Card monster3(deck.getMonster());

    //assign card hand to draw cards
    this->monsterFirst.changeCardTo(monster1);
    this->monsterSecond.changeCardTo(monster2);
    this->monsterThird.changeCardTo(monster3);

    //set position of player card hand
    this->monsterFirst.setPosition(600, yPosition);
    this->monsterSecond.setPosition(900, yPosition);
    this->monsterThird.setPosition(1200, yPosition);
}
Card Player::getMonsterFirst(){
    return monsterFirst;
}
Card Player::getMonsterSecond(){
    return monsterSecond;
}
Card Player::getMonsterThird(){
    return monsterThird;
}
void Player::moveMonsterCard(int monsterSelect, Field field, int fieldNumber){
    //move a specific monster card
    if(monsterSelect == 1)
        this->monsterFirst.setPosition(field.getPositionOfField(fieldNumber).x, field.getPositionOfField(fieldNumber).y);
    else if(monsterSelect == 2)
        this->monsterSecond.setPosition(field.getPositionOfField(fieldNumber).x, field.getPositionOfField(fieldNumber).y);
    else if(monsterSelect == 3)
        this->monsterThird.setPosition(field.getPositionOfField(fieldNumber).x, field.getPositionOfField(fieldNumber).y);
}
void Player::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    window.draw(monsterFirst);
    window.draw(monsterSecond);
    window.draw(monsterThird);
}