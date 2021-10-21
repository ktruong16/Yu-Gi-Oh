//
// Created by Minec on 11/28/2020.
//

#include "SplashScreen.h"
SplashScreen::SplashScreen() : SplashScreen("Test", "test", "test", "test", "test"){

}
SplashScreen::SplashScreen(string newTitle, string newName, string newCourseName, string newCRN, string newSemester){
    //create start button
    this->startButton.setSize({300,75});
    this->startButton.setFillColor(sf::Color::White);
    this->startButton.setPosition({800, 300});
    this->startButton.setOutlineColor(sf::Color::Black);
    this->startButton.setOutlineThickness(4);

    //create exit button
    this->exitButton.setSize({300,75});
    this->exitButton.setFillColor(sf::Color::White);
    this->exitButton.setPosition({800, 400});
    this->exitButton.setOutlineColor(sf::Color::Black);
    this->exitButton.setOutlineThickness(4);

    //load font
    if(!this->font.loadFromFile("OpenSans-Bold.ttf"))
        exit(1);

    //create the word start on splash screen
    startWord.setFont(this->font);
    startWord.setFillColor(sf::Color::Black);
    startWord.setCharacterSize(50);
    startWord.setPosition({885, 300});
    startWord.setString("Start");

    //create the word exit on splash screen
    exitWord.setFont(this->font);
    exitWord.setFillColor(sf::Color::Black);
    exitWord.setCharacterSize(50);
    exitWord.setPosition({900, 400});
    exitWord.setString("Exit");

    //create the word title on splash screen
    title.setFont(this->font);
    title.setFillColor(sf::Color::White);
    title.setCharacterSize(50);
    title.setPosition({750, 200});
    title.setString(newTitle);

    myName.setFont(this->font);
    myName.setFillColor(sf::Color::White);
    myName.setCharacterSize(50);
    myName.setPosition({300, 70});
    myName.setString(newName);

    courseName.setFont(this->font);
    courseName.setFillColor(sf::Color::White);
    courseName.setCharacterSize(50);
    courseName.setPosition({300, 130});
    courseName.setString(newCourseName);

    CRN.setFont(this->font);
    CRN.setFillColor(sf::Color::White);
    CRN.setCharacterSize(50);
    CRN.setPosition({300, 190});
    CRN.setString(newCRN);

    semester.setFont(this->font);
    semester.setFillColor(sf::Color::White);
    semester.setCharacterSize(50);
    semester.setPosition({300, 250});
    semester.setString(newSemester);

    if(!texture.loadFromFile("GameImage.png"))
        exit(1);
    picture.setTexture(texture);
    picture.scale(sf::Vector2f(0.50, 0.50));
    picture.setPosition(200, 400);
}
sf::FloatRect SplashScreen::getStartButtonBounds(){
    return startButton.getGlobalBounds();
}
sf::FloatRect SplashScreen::getExitButtonBounds(){
    return exitButton.getGlobalBounds();
}
void SplashScreen::draw(sf::RenderTarget &window, sf::RenderStates state) const{
    window.draw(startButton);
    window.draw(exitButton);
    window.draw(startWord);
    window.draw(exitWord);
    window.draw(title);
    window.draw(myName);
    window.draw(courseName);
    window.draw(CRN);
    window.draw(semester);
    window.draw(picture);
}