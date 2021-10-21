/*
 * Name: Truong, Kyle
 * Project Name: Final Project
 * Description: My game is based on the card game, Yu-Gi-Oh!, with my own twist to it.
 *              The game begins with a set of random cards in the player's hand and field pattern with attack or defense.
 *              Blue indicates defense, Red indicating attack.
 *              The player decides to choose where to place the cards onto the field.
 *              Once the field is completely filled, it will show the ai's field and proceed with damage calculations.
 *              Whoever loses the most points, loses the game.
 *              The game ends with a banner if you either a win, lose, or draw.
 * Date: December 9, 2020
 */
#include <iostream>
#include "MyGame.h"
int main() {
    MyGame game;
    game.run();
    return 0;
}
