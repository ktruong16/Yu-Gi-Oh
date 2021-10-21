//
// Created by Minec on 12/1/2020.
//

#include "Field.h"
Field::Field(){
    //first field spot
    this->field1.setSize({200,250});
    this->field1.setFillColor(sf::Color::Red);
    this->field1.setPosition({600, 450});
    this->field1.setOutlineColor(sf::Color::White);
    this->field1.setOutlineThickness(3);
    //second field spot
    this->field2.setSize({200,250});
    this->field2.setFillColor(sf::Color::Blue);
    this->field2.setPosition({900, 450});
    this->field2.setOutlineColor(sf::Color::White);
    this->field2.setOutlineThickness(3);
    //third field spot
    this->field3.setSize({200,250});
    this->field3.setFillColor(sf::Color::Red);
    this->field3.setPosition({1200, 450});
    this->field3.setOutlineColor(sf::Color::White);
    this->field3.setOutlineThickness(3);
}
Field::Field(float yPos, sf::Color pattern[]){
    for(int i = 0; i < 3; i++){
        if(i == 0){
            //first field spot
            this->field1.setSize({200,250});
            this->field1.setFillColor(pattern[i]);
            this->field1.setPosition({600, yPos});
            this->field1.setOutlineColor(sf::Color::White);
            this->field1.setOutlineThickness(3);
        }
        else if(i == 1){
            //second field spot
            this->field2.setSize({200,250});
            this->field2.setFillColor(pattern[i]);
            this->field2.setPosition({900, yPos});
            this->field2.setOutlineColor(sf::Color::White);
            this->field2.setOutlineThickness(3);
        }
        else if(i == 2){
            //third field spot
            this->field3.setSize({200,250});
            this->field3.setFillColor(pattern[i]);
            this->field3.setPosition({1200, yPos});
            this->field3.setOutlineColor(sf::Color::White);
            this->field3.setOutlineThickness(3);
        }
    }
}
Monsters Field::getFieldMonsters(int fieldNum){
    //grabs the monster on the field
    return this->field[fieldNum];
}
sf::Color Field::getFieldColor(int fieldNum){
    switch(fieldNum){
        case 1:
            return field1.getFillColor();
        case 2:
            return field2.getFillColor();
        case 3:
            return field3.getFillColor();
    }
}
void Field::eraseField(){
    int index = 0;
}
void Field::insert(Monsters card, int fieldSpot){
    //place the card onto the field
    this->field[fieldSpot - 1] = card;
}
void Field::changePatternTo(sf::Color pattern[]){
    //switches the pattern to the new one
    for(int i = 0; i < 3; i++){
        if(i == 0)
            this->field1.setFillColor(pattern[i]);
        else if(i == 1)
            this->field2.setFillColor(pattern[i]);
        else if(i == 2)
            this->field3.setFillColor(pattern[i]);
    }
}
sf::Vector2f Field::getPositionOfField(int numberField){
    //grabs the position of the field
    if(numberField == 1)
        return field1.getPosition();
    else if(numberField == 2)
        return field2.getPosition();
    else if(numberField == 3)
        return field3.getPosition();
}
sf::FloatRect Field::getField1Bounds(){
    return this->field1.getGlobalBounds();
}
sf::FloatRect Field::getField2Bounds(){
    return this->field2.getGlobalBounds();
}
sf::FloatRect Field::getField3Bounds(){
    return this->field3.getGlobalBounds();
}
void Field::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    window.draw(field1);
    window.draw(field2);
    window.draw(field3);
}
