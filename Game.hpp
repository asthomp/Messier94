/*********************************************************************
** Program name: Project 5
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Game class introduces the user to the game,
** prints the map, manages player movement, and monitors all
** conditions related to winning or losing. Each round, a new
** Game object is created and, upon meeting the criteria for
** winning or losing, is destroyed. This header file contains
** include guards to prevent duplication.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <fstream>
#include <string>
#include <vector>
#include "Space.hpp"
#include "Board.hpp"
#include "menu.hpp"
#include "intro.hpp"
#include "battery.hpp"
#include "Inventory.hpp"

class Game {

    friend class Space;

private:

    Inventory *items = Inventory::getInventory();
    Board gameboard;
    int level = 100;
    int key = 0;
    char direction;
    std::string invMenuStr = "";
    bool invExit = false;
    bool flashlight = true;
    bool end = false;
    bool win = false;
    bool move = false;

    static void movementTutorial();

    void movePlayer();

    void manageInventory();

    void unlockShip();

    void ending();

public:

    Game();

    ~Game();

};

#endif //GAME_HPP
