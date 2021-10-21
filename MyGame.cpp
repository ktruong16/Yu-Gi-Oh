//
// Created by Minec on 11/23/2020.
//

#include "MyGame.h"
MyGame::MyGame() : window({1920, 1080, 32}, "Janky Yu-Gi-Oh!"){
    window.setKeyRepeatEnabled(false);
}
void MyGame::run (){
    //randomly generate pattern
    srand(time(NULL));
    int pattern = rand() % 2;

    bool splashScreenOn = true;                         //check for splash screen
    SplashScreen splashScreen("Janky Yu-Gi-Oh!", "Kyle Truong", "CS3A", "CRN: 77058", "Fall 2020");       //title of window

    //create the deck
    initDeck();

    //set up player hand and deck
    Player player(playerDeck);
    Player ai(aiDeck, 150);
    Field playerField(450, attackPattern);
    Field aiField(150, defensePattern);

    //determine random pattern
    if(pattern == 1){
        playerField.changePatternTo(defensePattern);
        aiField.changePatternTo(attackPattern);
    }
    else{
        playerField.changePatternTo(attackPattern);
        aiField.changePatternTo(defensePattern);
    }

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                //mouse position
                sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
                //splash screen buttons
                sf::FloatRect startBounds = splashScreen.getStartButtonBounds();
                sf::FloatRect exitBounds = splashScreen.getExitButtonBounds();
                //field options
                sf::FloatRect field1Bounds = playerField.getField1Bounds();
                sf::FloatRect field2Bounds = playerField.getField2Bounds();
                sf::FloatRect field3Bounds = playerField.getField3Bounds();

                //splashscreen buttons
                if(startBounds.contains(mpos) && splashScreenOn)
                    splashScreenOn = false;
                if(exitBounds.contains(mpos) && splashScreenOn)
                    window.close();
                //gameplay
                if(field1Bounds.contains(mpos) && !splashScreenOn){
                    //move the card onto the field
                    player.moveMonsterCard(selectCard, playerField, 1);
                    //place monster card to field 1
                    switch(selectCard){
                        case 1:
                            playerField.insert(player.getMonsterFirst().getMonsterName(), 1);
                            break;
                        case 2:
                            playerField.insert(player.getMonsterSecond().getMonsterName(), 1);
                            break;
                        case 3:
                            playerField.insert(player.getMonsterThird().getMonsterName(), 1);
                            break;
                    }
                    aiField.insert(ai.getMonsterFirst().getMonsterName(), 1);
                    selectCard++;
                }
                else if(field2Bounds.contains(mpos) && !splashScreenOn){
                    //move the card onto the field
                    player.moveMonsterCard(selectCard, playerField, 2);
                    //place monster card to field 1
                    switch(selectCard){
                        case 1:
                            playerField.insert(player.getMonsterFirst().getMonsterName(), 2);
                            break;
                        case 2:
                            playerField.insert(player.getMonsterSecond().getMonsterName(), 2);
                            break;
                        case 3:
                            playerField.insert(player.getMonsterThird().getMonsterName(), 2);
                            break;
                    }
                    aiField.insert(ai.getMonsterSecond().getMonsterName(), 2);
                    selectCard++;
                }
                else if(field3Bounds.contains(mpos) && !splashScreenOn){
                    //move the card onto the field
                    player.moveMonsterCard(selectCard, playerField, 3);
                    //place monster card to field 1
                    switch(selectCard){
                        case 1:
                            playerField.insert(player.getMonsterFirst().getMonsterName(), 3);
                            break;
                        case 2:
                            playerField.insert(player.getMonsterSecond().getMonsterName(), 3);
                            break;
                        case 3:
                            playerField.insert(player.getMonsterThird().getMonsterName(), 3);
                            break;
                    }
                    aiField.insert(ai.getMonsterThird().getMonsterName(), 3);
                    selectCard++;
                }
            }
            //calculated damage and determines winner
            dmgField1.damageCalculation(playerField, aiField, 1);
            dmgField2.damageCalculation(playerField, aiField, 2);
            dmgField3.damageCalculation(playerField, aiField, 3);
            dmgField1.changePosition(600);
            dmgField2.changePosition(900);
            dmgField3.changePosition(1200);
            setupBanner();                                  //create banner
        }
        //draw splash screen
        if(splashScreenOn){
            window.clear(sf::Color(137,0,0));
            window.draw(splashScreen);
            window.display();
        }
        //game is completed, show end screen
        else if(selectCard >= 4 && !splashScreenOn){
            window.clear(sf::Color(85, 107, 47));

            //create field for both players
            window.draw(playerField);
            window.draw(aiField);

            //draw cards on both player and ai
            window.draw(player);
            window.draw(ai);

            //draw damage numbers
            window.draw(dmgField1);
            window.draw(dmgField2);
            window.draw(dmgField3);

            window.draw(banner);                    //banner drawn
            window.display();
        }
        //normal gameplay screen
        else{
            window.clear(sf::Color(85, 107, 47));
            window.draw(playerField);
            window.draw(aiField);
            window.draw(player);
            window.display();
        }
    }
}
void MyGame::initDeck(){
    srand(time(NULL));
    //pushing cards into the deck(stack linked list)
    for(int i = 0; i < 3; i++){
        playerDeck.push(static_cast<Monsters>(rand() % mc::end));
        aiDeck.push(static_cast<Monsters>(rand() % mc::end));
    }
}
void MyGame::setupBanner(){
    if(!font.loadFromFile("OpenSans-Bold.ttf"))
        exit(1);
    banner.setFont(font);
    banner.setFillColor(sf::Color::Black);
    banner.setCharacterSize(75);
    banner.setPosition(1500, 400);

    //condition for damage for player and ai
    int totalDmgPlayer = 0, totalDmgAi = 0;
    if(dmgField1.getDmgTaken() > 0){
        totalDmgAi += dmgField1.getDmgTaken();
    }
    else{
        totalDmgPlayer += -(dmgField1.getDmgTaken());
    }
    if(dmgField2.getDmgTaken() > 0){
        totalDmgAi += dmgField2.getDmgTaken();
    }
    else{
        totalDmgPlayer += -(dmgField2.getDmgTaken());
    }
    if(dmgField3.getDmgTaken() > 0){
        totalDmgAi += dmgField3.getDmgTaken();
    }
    else{
        totalDmgPlayer += -(dmgField3.getDmgTaken());
    }

    //calculate who took the most damage
    if(totalDmgPlayer < totalDmgAi)
        banner.setString("You Win!");
    else if(totalDmgPlayer == totalDmgAi)
        banner.setString("Draw!");
    else
        banner.setString("You Lose!");
}