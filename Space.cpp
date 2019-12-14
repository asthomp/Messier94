/*********************************************************************
** Program name: Messier94
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Space class is the parent class for all board
** tiles. Each Space object is, effectively, a node in an interwoven
** doubly-linked list. Each Space object contains four directional
** pointers and holds a set of coordinates.
*********************************************************************/

#include <chrono>
#include "Space.hpp"


// Creates a Space object, initializes pointers, and seeds the random generator.

Space::Space() : top(nullptr), right(nullptr), bottom(nullptr), left(nullptr),
                 generator(std::chrono::system_clock::now().time_since_epoch().count()) {

}

// This virtual destructor allows the derived classes to be destroyed.

Space::~Space() = default;


/*********************************************************************
** Description: The setCoords setter function sets the row and col
** for a Space object. It requires two integers and returns void.
*********************************************************************/

void Space::setCoords(int r, int c) {
    row = r;
    col = c;
}


/*********************************************************************
** Description: This getter function returns the Space object's row.
** It requires no parameters and returns an integer.
*********************************************************************/

int Space::getRow() {
    return row;
}

/*********************************************************************
** Description: This getter function returns the Space object's column.
** It requires no parameters and returns an integer.
*********************************************************************/

int Space::getCol() {
    return col;
}


/*********************************************************************
** Description: The randomEvent member function returns a randomly
** generated number with a range of 1-4. It requires no parameters
** and returns an integer from 1-4.
*********************************************************************/

int Space::randomEvent() {

    std::uniform_int_distribution<int> roll(1, 4);

    return roll(generator);
}
