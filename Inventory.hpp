/*********************************************************************
** Program name: Messier94
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Inventory class creates a singleton object. It creates
** a container object and manages the objects within the container. This
** header file contains include guards to prevent duplication.
*********************************************************************/

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include <list>
#include <algorithm>
#include "Space.hpp"

// Two types of object can be stored in the player's inventory: batteries (power) and alien artifacts).

enum Items {
    power, artifact
};

class Inventory {

private:

    std::list<Items> items;
    std::list<Items>::iterator traveler;
    static Inventory *instance;

    Inventory();

public:

    static Inventory *getInventory();

    void printInventory();

    int numBattery();

    int numArtifact();

    void addBattery();

    void addArtifact();

    void removeBattery();

    void removeArtifact();

    int useBattery(int juice);

    static void freeInventory();

};

#endif //INVENTORY_HPP
