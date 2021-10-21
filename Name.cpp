//
// Created by Minec on 11/25/2020.
//

#include "Name.h"
Name::Name() : Name(BlueEyesWhiteDragon){

}
Name::Name(Monsters theName){
    if(!name.loadFromFile("OpenSans-Bold.ttf"))
        exit(1);
    setFont(name);
    setFillColor(sf::Color::Black);
    setCharacterSize(50);
    //sets string to text with monster name
    switch(theName) {
        case BlueEyesWhiteDragon:
            setString("Blue Eyes White Dragon");
            break;
        case DarkMagician:
            setString("Dark Magician");
            break;
        case BusterBlader:
            setString("Buster Blader");
            break;
        case JoeEyesBlackDragon:
            setString("Joe Eyes Black Dragon");
            break;
        case WingedKuriboh:
            setString("Winged Kuriboh");
            break;
        case ChimeratechOverdragon:
            setString("Chimeratech Overdragon");
            break;
    }
    setOrigin({getGlobalBounds().width / 2, getGlobalBounds().height / 2});
}
void Name::setPosition(sf::FloatRect bounds){
    sf::FloatRect pos = getGlobalBounds();
    float top = bounds.top;
    float bottom = bounds.top + bounds.height;
    sf::Text::setPosition(bounds.left + pos.width / 1.75, top + pos.height + pos.height);
}
void Name::setName(Monsters newName){
    if(!name.loadFromFile("OpenSans-Bold.ttf"))
        exit(1);
    setFont(name);
    setFillColor(sf::Color::Black);
    setCharacterSize(10);
    //sets string to text with monster name
    switch(newName){
        case BlueEyesWhiteDragon:
            setString("Blue Eyes White Dragon");
            break;
        case DarkMagician:
            setString("Dark Magician");
            break;
        case BusterBlader:
            setString("Buster Blader");
            break;
        case JoeEyesBlackDragon:
            setString("Joe Eyes Black Dragon");
            break;
        case WingedKuriboh:
            setString("Winged Kuriboh");
            break;
        case ChimeratechOverdragon:
            setString("Chimeratech Overdragon");
            break;
    }
    setOrigin({getGlobalBounds().width / 4, getGlobalBounds().height / 4});
}