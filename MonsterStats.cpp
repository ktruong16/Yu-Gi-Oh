//
// Created by Minec on 12/8/2020.
//

#include "MonsterStats.h"
MonsterStats::MonsterStats() : MonsterStats(BlueEyesWhiteDragon){

}
MonsterStats::MonsterStats(Monsters monster){
    if(!font.loadFromFile("OpenSans-Bold.ttf"))
        exit(1);
    //attack stats
    attackDmg.setFont(font);
    attackDmg.setFillColor(sf::Color::Black);
    attackDmg.setCharacterSize(25);
    //defense stats
    defenseDmg.setFont(font);
    defenseDmg.setFillColor(sf::Color::Black);
    defenseDmg.setCharacterSize(25);

    //sets the text to display attack and defense damage
    switch(monster){
        case BlueEyesWhiteDragon:
            attackDmg.setString("ATK: 3000");
            defenseDmg.setString("DEF: 2500");
            break;
        case DarkMagician:
            attackDmg.setString("ATK: 2500");
            defenseDmg.setString("DEF: 2000");
            break;
        case BusterBlader:
            attackDmg.setString("ATK: 2800");
            defenseDmg.setString("DEF: 2500");
            break;
        case JoeEyesBlackDragon:
            attackDmg.setString("ATK: 3000");
            defenseDmg.setString("DEF: 2500");
            break;
        case WingedKuriboh:
            attackDmg.setString("ATK: 3000");
            defenseDmg.setString("DEF: 2500");
            break;
        case ChimeratechOverdragon:
            attackDmg.setString("ATK: 3000");
            defenseDmg.setString("DEF: 2500");
            break;
    }
}
void MonsterStats::setAttackPosition(sf::FloatRect bounds){
    sf::FloatRect pos = attackDmg.getGlobalBounds();
    float top = bounds.top;
    float bottom = bounds.top + bounds.height;
    attackDmg.setPosition(bounds.left + pos.width / 2.5, top + (pos.height * 10.5));
}
void MonsterStats::setDefensePosition(sf::FloatRect bounds){
    sf::FloatRect pos = defenseDmg.getGlobalBounds();
    float top = bounds.top;
    float bottom = bounds.top + bounds.height;
    defenseDmg.setPosition(bounds.left + pos.width / 2.5, top + (pos.height * 12));
}
void MonsterStats::setStats(Monsters monster){
    //attack stats
    attackDmg.setFont(font);
    attackDmg.setFillColor(sf::Color::Black);
    attackDmg.setCharacterSize(25);
    //defense stats
    defenseDmg.setFont(font);
    defenseDmg.setFillColor(sf::Color::Black);
    defenseDmg.setCharacterSize(25);

    //sets the text to display attack and defense damage
    switch(monster){
        case BlueEyesWhiteDragon:
            attackDmg.setString("ATK: 3000");
            defenseDmg.setString("DEF: 2500");
            break;
        case DarkMagician:
            attackDmg.setString("ATK: 2500");
            defenseDmg.setString("DEF: 2000");
            break;
        case BusterBlader:
            attackDmg.setString("ATK: 2800");
            defenseDmg.setString("DEF: 2500");
            break;
        case JoeEyesBlackDragon:
            attackDmg.setString("ATK: 2400");
            defenseDmg.setString("DEF: 2000");
            break;
        case WingedKuriboh:
            attackDmg.setString("ATK: 1000");
            defenseDmg.setString("DEF: 1000");
            break;
        case ChimeratechOverdragon:
            attackDmg.setString("ATK: 2800");
            defenseDmg.setString("DEF: 2400");
            break;
    }
}
void MonsterStats::draw(sf::RenderTarget &window, sf::RenderStates state) const{
    window.draw(attackDmg);
    window.draw(defenseDmg);
}