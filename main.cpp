/*********************************************************************
** Program name: Messier94
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: Messier94 is an adventure game where the user investigates
** a UFO crash. The user is turn-limited by a flashlight which slowly runs
** out of battery. To win, the user must find an alien artifact, locate
** the crashed ship, and solve a puzzle.
*********************************************************************/

#include "menu.hpp"
#include "Game.hpp"

int main() {

    bool play = true;

    // This text printed here is by TA request.

    std::cout << "Final Project #6 programmed by Aaron Thompson for CS 162.\n" << std::endl;

    // This code allows the user to play again. Each time the game is played,
    // a Game object is created and destroyed.

    while (play) {

        Game g1;

        if (menu(1, 2, "Would you like to play again?\n\t1. Play Again\n\t2. Quit ") == 2) {

            play = false;
        }

        clear();
    }

    return 0;
}

