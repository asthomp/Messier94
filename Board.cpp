/*********************************************************************
** Program name: Project 5
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Board class handles all functionality related to
** creating, printing, and editing the game board. The game board is
** an interwoven mesh (linked list) of Space nodes, each containing four
** directional pointers. The mesh is represented graphically by a 2D array
** that tracks the Space node occupied by the player character.
*********************************************************************/

#include "Game.hpp"
#include "Board.hpp"
#include "menu.hpp"
#include "Space.hpp"
#include "Field.hpp"
#include "Artifact.hpp"
#include "Forest.hpp"
#include "Meadow.hpp"
#include "Ship.hpp"
#include <vector>

// Creates a board object, setting up the 2D array (the graphical map) and the
// interwoven mesh of Space nodes.

Board::Board() {

    createMap();

    setupBoard();
}


/*********************************************************************
** Description: The setupBoard member function creates a vector and populates
** it with the appropriate Space class child objects. It calls helper functions
** to perform key tasks: 1) creating a row (doubly linked list), 2) weaving each
** row together. This allows the list to take on the appearance of a mesh with
** 4 directional pointers. A pointer to the "front" of each row is saved for later
** destruction. The function requires no parameters and returns void.
*********************************************************************/

void Board::setupBoard() {

    // Creates the initial game tiles or spaces. Each game tile is actually just
    // a coordinate stored in a mesh-like linked list. While the map prints the entire
    // graphic, the only thing that effectively "moves" on the board is tied to the
    // coordinate stored in each Space node.

    std::vector<Space *> row1 = {new Field, new Artifact, new Field, new Forest, new Forest, new Meadow, new Meadow};
    std::vector<Space *> row2 = {new Field, new Field, new Field, new Forest, new Artifact, new Meadow, new Ship};
    std::vector<Space *> row3 = {new Field, new Field, new Field, new Forest, new Forest, new Meadow, new Artifact};

    makeRow(row1);
    makeRow(row2);
    makeRow(row3);

    stitchRows(row1, row2);
    stitchRows(row2, row3);

    rowPtr1 = row1[0];
    rowPtr2 = row2[0];
    rowPtr3 = row3[0];

    // Sets the player's starting position.

    player = row2[0];

}


/*********************************************************************
** Description: The makeRows function takes a vector of Space* and
** creates a doubly-linked list out of these nodes. It also sets the
** coordinates for each row. Upon creation, the row value will be
** incorrect and is "built up" to the correct value by the stitchRows
** function. The function requires a vector of Space* and returns void.
*********************************************************************/

void Board::makeRow(std::vector<Space *> vector) {

    for (unsigned int i = 0; i < vector.size() - 1; i++) {
        vector[i]->right = vector[i + 1];
        vector[i]->setCoords(3, 6 + (12 * i));
        vector[i + 1]->left = vector[i];
    }

    vector[vector.size() - 1]->setCoords(3, 6 + (12 * (vector.size() - 1)));
}


/*********************************************************************
** Description: The stitchRows function takes two vectors, each containing
** a row of Space nodes. The Space nodes, previously, must have been linked
** together as a doubly linked list. This function takes those nodes and
** stitches the two rows together. It also sets the coordinates that each
** Space node must contain. The function requires two Space* vectors and
** and returns void.
*********************************************************************/

void Board::stitchRows(std::vector<Space *> fixed, std::vector<Space *> toAttach) {

    for (unsigned int i = 0; i < fixed.size(); i++) {

        toAttach[i]->top = fixed[i];
        fixed[i]->bottom = toAttach[i];
        toAttach[i]->setCoords(fixed[i]->getRow() + 6, fixed[i]->getCol());
    }
}


/*********************************************************************
** Description: The getPlayer getter function requires no parameters
** and returns the player pointer (which pointers to the player's
** location or Space node).
*********************************************************************/

Space *Board::getPlayer() {
    return player;
}


/*********************************************************************
** Description: The setPlayerTop setter function moves the player
** pointer to the node above it. It requires no parameters and returns
** void.
*********************************************************************/

void Board::setPlayerTop() {

    player = player->top;
}


/*********************************************************************
** Description: The setPlayerBottom setter function moves the player
** pointer to the node below it. It requires no parameters and returns
** void.
*********************************************************************/

void Board::setPlayerBottom() {

    player = player->bottom;
}


/*********************************************************************
** Description: The setPlayerLeft setter function moves the player
** pointer to the node to the left of it. It requires no parameters
** and returns void.
*********************************************************************/

void Board::setPlayerLeft() {

    player = player->left;
}


/*********************************************************************
** Description: The setPlayerRight setter function moves the player
** pointer to the node to the right of it. It requires no parameters
** and returns void.
*********************************************************************/

void Board::setPlayerRight() {

    player = player->right;
}


/*********************************************************************
** Description: The checkBounds function requires a direction character
** as a parameter and returns whether or not the player can move in
** that direction. It checks to see if the player-occupied Space node's
** direction pointer (top, bottom, left, right) points to nullptr. If it
** does, the player cannot move in that direction and the function returns
** false.
*********************************************************************/

bool Board::checkBounds(char direction) {

    if (direction == 'W' && player->top == nullptr) {

        std::cout << "\tYou can't go in that direction!\n" << std::endl;
        return false;

    } else if (direction == 'A' && player->left == nullptr) {

        std::cout << "\tYou can't go in that direction!\n" << std::endl;
        return false;

    } else if (direction == 'S' && player->bottom == nullptr) {

        std::cout << "\tYou can't go in that direction!\n" << std::endl;
        return false;

    } else if (direction == 'D' && player->right == nullptr) {

        std::cout << "\tYou can't go in that direction!\n" << std::endl;
        return false;

    } else if (direction == 'I') {

        return false;

    } else {

        return true;
    }
}


/*********************************************************************
** Description: This function prints the 2D map array, converts
** several ASCII characters into characters from the extended ASCII
** set, and prints the player character on the board. It requires
** no parameters and returns void.
*********************************************************************/

void Board::printMap() {

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 85; j++) {
            if (player->getRow() == i && player->getCol() == j) {
                std::cout << "■";
            } else if (mapArray[i][j] == 'D') {
                std::cout << "░";
            } else if (mapArray[i][j] == 'F') {
                std::cout << "±";
            } else if (mapArray[i][j] == '1') {
                std::cout << "┌";
            } else if (mapArray[i][j] == '2') {
                std::cout << "┐";
            } else if (mapArray[i][j] == '3') {
                std::cout << "└";
            } else if (mapArray[i][j] == '4') {
                std::cout << "┘";
            } else if (mapArray[i][j] == '_') {
                std::cout << "─";
            } else {
                std::cout << mapArray[i][j];
            }
        }
        std::cout << std::endl;
    }

    // This is the map key, which prints each time the map is printed.

    std::cout << "┌───────────────────────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "|    Map Key: H home, ■ you, \\|/ corn field, ±.± forest, \\V/ meadow, ░ X unknown    |" << std::endl;
    std::cout << "|                                                                                   |" << std::endl;
    std::cout << "| Controls:  [w] <- up   [a] <- left   [s] <- down   [d] <-right   [i] <- inventory |" << std::endl;
    std::cout << "└───────────────────────────────────────────────────────────────────────────────────┘\n" << std::endl;
}


/*********************************************************************
** Description: This function creates the map array. The map array is
** a series of characters that draw out a map. While, in actuality,
** there are only 21 spaces on the board, the map array "draws"
** out multiple characters, making the world appear bigger than it
** actually is. The function requires no parameters and returns void.
*********************************************************************/

void Board::createMap() {

    mapArray = new char *[19];

    for (int i = 0; i < 19; ++i) {
        mapArray[i] = new char[85];
    }

    this->fillArray();

}


/*********************************************************************
** Description: This function opens a file and imports each character in
** the file, line by line, including spaces. The characters are stored in
** the map array and, lastly, the file is closed. This allows the map
** "graphic" to be altered without affecting the 21 game piece coordinates.
** The function requires no parameters and returns void.
*********************************************************************/

void Board::fillArray() {

    //First, we open the file.

    openFile();

    //Then, we fill the array with the items in the file stream object,
    //one-after-another.

    for (int i = 0; i < 19; i++) {

        std::getline(mapStream, mapLine);

        for (int j = 0; j < 85; j++) {
            mapArray[i][j] = mapLine.at(j);
        }

    }

    //Lastly, we close the file stream object.

    mapStream.close();
}


/*********************************************************************
** Description: This function attempts to open the map art file. If the
** file is not present, it gives the user an opportunity to correct the
** error and load a different file. The function requires no parameters
** and returns void.
*********************************************************************/

void Board::openFile() {

    int choice = 0;

    //This code opens the appropriate file. If the file can be opened successfully,
    //it exits the loop. If the file cannot be opened, it prints a warning.

    while (!mapStream.is_open()) {

        //The string pointer must be de-referenced to open the file!

        mapStream.open(mapFile);

        if (!mapStream.is_open()) {

            //These errors print in the event that the file could not be opened.
            std::cout << "\n\tCould not access file." << std::endl;
            std::cout << "\tHint: Confirm that file is actually in the working directory." << std::endl;

            //On a second failure, the user is reminded to enter the file appropriately.
            if (choice == 2) {
                std::cout << "\tHint: Type the file name with an extension but without any leading/trailing "
                             "spaces." << std::endl;
            }

            //The user is prompted to resolve the issue. They can either try to open the file again or enter a
            //completely new file name.

            choice = menu(1, 2,
                          "\n\tHow would you like to proceed?\n1. Try opening the file again.\n2. Enter a new file name.");

            if (choice == 2) {
                std::cout << "\tEnter your new file name: ";
                std::cin >> mapFile;
            }
        }
    }
}


/*********************************************************************
** Description: The deleteBoard function calls a helper function
** to delete each row of linked Space nodes. It also iterates over
** the 2D dynamic array, deleting it. All pointers are set to nullptr.
** The function requires no parameters and returns void.
*********************************************************************/

void Board::deleteBoard() {

    deleteRow(rowPtr1);
    deleteRow(rowPtr2);
    deleteRow(rowPtr3);

    // This code iterates over each nested array, deleting it, and then,
    // deletes mapArray (the array containing the
    // other arrays). Then, it sets the pointers to null.

    for (int i = 0; i < 19; ++i) {
        delete[] mapArray[i];
    }

    delete[] mapArray;
    mapArray = nullptr;

}


/*********************************************************************
** Description: The deleteRow function creates a pointer to traverse
** the array, deleting Space objects and setting pointers to nullptr
** as it does so. It requires a Space* as a parameter and returns void.
*********************************************************************/

void Board::deleteRow(Space *traveler) {

    Space *trash;

    for (int i = 0; i < 7; i++) {

        trash = traveler;
        traveler = traveler->right;
        trash->left = nullptr;
        trash->top = nullptr;
        trash->bottom = nullptr;
        trash->right = nullptr;
        delete trash;

    }

    traveler = nullptr;
    trash = nullptr;

}