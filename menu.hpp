/*********************************************************************
** Program name: Reusable
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The menu functions receive user input (either numeric
** or character), validate that input, and return validated input. The
** code contains include guards to prevent duplication.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

int menu(int, int, std::string);

char getMove(std::string options);

#endif //MENU_HPP
