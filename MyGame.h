//
// Created by Minec on 11/23/2020.
//

#ifndef FINAL_PROJECT_MYGAME_H
#define FINAL_PROJECT_MYGAME_H

#include <SFML/Graphics.hpp>
#include "SplashScreen.h"
#include "StackDeck.h"
#include "Player.h"
#include "Field.h"
#include "Damage.h"
class MyGame {
private:
    int selectCard = 1;             //controls which card to select

    //each players' deck
    StackDeck playerDeck;
    StackDeck aiDeck;

    sf::RenderWindow window;        //SFML window

    //field pattern
    sf::Color attackPattern[3] = {sf::Color::Red, sf::Color::Blue, sf::Color::Red};
    sf::Color defensePattern[3] = {sf::Color::Blue, sf::Color::Red, sf::Color::Blue};

    //controls the damage on the field
    Damage dmgField1;
    Damage dmgField2;
    Damage dmgField3;

    //display winner/loser banner
    sf::Text banner;
    sf::Font font;

    void setupBanner();         //creates banner for win/lose
    void initDeck();            //creates the deck
public:
    void run();             //run the game
    MyGame();               //generate game
};

#endif //FINAL_PROJECT_MYGAME_H
