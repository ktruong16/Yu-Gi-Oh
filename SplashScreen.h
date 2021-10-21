//
// Created by Minec on 11/28/2020.
//

#ifndef FINAL_PROJECT_SPLASHSCREEN_H
#define FINAL_PROJECT_SPLASHSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
class SplashScreen : public sf::Drawable, sf::Transformable{
private:
    sf::Sprite picture;                                     //game image
    sf::Texture texture;
    sf::RectangleShape startButton, exitButton;             //ractangle shape for button
    sf::Font font;                                          //load font
    sf::Text startWord, exitWord, title, myName, courseName, CRN, semester;     //visible text of game
public:
    //constructor
    SplashScreen();
    SplashScreen(string newTitle, string newName, string courseName, string newCRN, string newSemester);
    //getter
    sf::FloatRect getStartButtonBounds();
    sf::FloatRect getExitButtonBounds();
    //member function
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;
};


#endif //FINAL_PROJECT_SPLASHSCREEN_H
