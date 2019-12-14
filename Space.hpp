/*********************************************************************
** Program name: Project 5
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Space class is the parent class for all board
** tiles. Each Space object is, effectively, a node in an interwoven
** doubly-linked list. Each Space object contains four directional
** pointers and holds a set of coordinates. This code contains include
** guards to prevent duplication.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <random>
#include "menu.hpp"

class Space {

    friend class Board;

protected:


    int choice;
    int chance;
    int row;
    int col;
    bool explore=true;

    Space *top;
    Space *right;
    Space *bottom;
    Space *left;

    std::default_random_engine generator;

public:

    Space();

    virtual ~Space();

    void setCoords(int r, int c);

    int getRow();

    int getCol();

    int randomEvent();

    // The Space class contains two pure virtual functions.

    virtual void event() = 0;

    virtual void action() = 0;

};

#endif //SPACE_HPP
