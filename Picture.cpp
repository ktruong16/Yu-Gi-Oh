//
// Created by Minec on 11/25/2020.
//

#include "Picture.h"
Picture::Picture() : Picture(BlueEyesWhiteDragon){

}
Picture::Picture(Monsters monster){
    if(!texture.loadFromFile(getImagePath(monster)))
        exit(1);
    picture.setTexture(texture);
    picture.scale(sf::Vector2f(0.17, 0.17));
}
void Picture::setPicture(Monsters monster){
    if(!texture.loadFromFile(getImagePath(monster)))
        exit(1);
}
string Picture::getImagePath(Monsters monster){
    //grabs the file to set picture
    switch(monster){
        case BlueEyesWhiteDragon:
            return "BlueEyes.png";
        case DarkMagician:
            return "DarkMagician.png";
        case BusterBlader:
            return "BusterBlader.png";
        case JoeEyesBlackDragon:
            return "JoeEyesBlackDragon.png";
        case WingedKuriboh:
            return "WingedKuriboh.png";
        case ChimeratechOverdragon:
            return "ChimeratechOverdragon.png";
    }
}
void Picture::setPosition(sf::FloatRect bounds){
    picture.setPosition(bounds.left + 30, bounds.top + 70);
}
void Picture::draw(sf::RenderTarget &window, sf::RenderStates state) const{
    window.draw(picture);
}