//
// Created by Minec on 12/6/2020.
//

#include "Damage.h"
Damage::Damage() : Damage(9000, 900){

}
Damage::Damage(int dmg, float xPosition){
    if(!this->font.loadFromFile("OpenSans-Bold.ttf"))
        exit(1);

    this->textDmg.setFont(this->font);
    this->textDmg.setFillColor(sf::Color::Red);
    this->textDmg.setCharacterSize(25);
    this->textDmg.setPosition({xPosition, 800});
    this->textDmg.setString(std::to_string(dmg));
}
void Damage::damageCalculation(Field player, Field ai, int fieldNumber){
    //calculates damage between attack and defense monster on player side
    if(player.getFieldColor(fieldNumber) == sf::Color::Red){
        this->dmgTaken = attackDmg(player.getFieldMonsters(fieldNumber - 1)) - defenseDmg(ai.getFieldMonsters(fieldNumber - 1));
    }
    //calculates damage between defense and attack monster on player side
    else if(player.getFieldColor(fieldNumber) == sf::Color::Blue){
        this->dmgTaken = defenseDmg(player.getFieldMonsters(fieldNumber - 1)) - attackDmg(ai.getFieldMonsters(fieldNumber - 1));
    }
    //set text for damage taken
    this->textDmg.setString(std::to_string(this->dmgTaken));
}
int Damage::getDmgTaken(){
    return this->dmgTaken;
}
void Damage::changePosition(float xPosition){
    this->textDmg.setPosition(xPosition, 800);
}
int Damage::attackDmg(Monsters monster){
    //grabs the attack damage of the monster(used for calculating damage)
    switch(monster){
        case BlueEyesWhiteDragon:
            return 3000;
        case DarkMagician:
            return 2500;
        case BusterBlader:
            return 2800;
        case JoeEyesBlackDragon:
            return 2400;
        case WingedKuriboh:
            return 1000;
        case ChimeratechOverdragon:
            return 2800;
    }
}
int Damage::defenseDmg(Monsters monster){
    //grabs the defense damage of the monster(used for calculating damage)
    switch(monster){
        case BlueEyesWhiteDragon:
            return 2500;
        case DarkMagician:
            return 2000;
        case BusterBlader:
            return 2500;
        case JoeEyesBlackDragon:
            return 2000;
        case WingedKuriboh:
            return 1000;
        case ChimeratechOverdragon:
            return 2400;
    }
}
void Damage::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    window.draw(this->textDmg);
}