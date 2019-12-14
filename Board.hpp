/*********************************************************************
** Program name: Project 5
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Board class handles all functionality related to
** creating, printing, and editing the game board. The game board is
** an interwoven mesh (linked list) of Space nodes, each containing four
** directional pointers. The mesh is represented graphically by a 2D array
** that tracks the Space node occupied by the player character. This
** header file contains include guards to prevent duplication.
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Space.hpp"
#include <fstream>
#include <string>
#include <vector>

class Board {

    friend class Game;

private:

    Space *player;
    Space *rowPtr1;
    Space *rowPtr2;
    Space *rowPtr3;
    char **mapArray = nullptr;
    std::string mapFile = "map.txt";
    std::string mapLine = "";
    std::ifstream mapStream;

    void createMap();

    void openFile();

    void fillArray();

    void makeRow(std::vector<Space *> vector);

    void stitchRows(std::vector<Space *> vector1, std::vector<Space *> vector2);

    void deleteRow(Space *traveler);

public:

    Board();

    void setupBoard();

    Space *getPlayer();

    void setPlayerTop();

    void setPlayerBottom();

    void setPlayerLeft();

    void setPlayerRight();

    bool checkBounds(char direction);

    void printMap();

    void deleteBoard();

};


#endif //BOARD_HPP
