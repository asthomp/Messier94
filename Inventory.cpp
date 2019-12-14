/*********************************************************************
** Program name: Messier94
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Inventory class creates a singleton object. It creates
** a container object and manages the objects within the container.
*********************************************************************/

#include "Inventory.hpp"

// This inventory pointer allocates some memory for our Inventory instance.

Inventory *Inventory::instance;


// This code creates the inventory container.

Inventory::Inventory() {

}

/*********************************************************************
** Description: The getInventory static method creates a new Inventory
** ONLY if one has NOT been created. If an Inventory exists, it does
** NOT create a new Inventory. The function requires no parameters and
** returns a pointer to the Inventory object.
*********************************************************************/

Inventory *Inventory::getInventory() {

    if (instance == nullptr) {
        instance = new Inventory;
    }

    return instance;
}


/*********************************************************************
** Description: The printInventory method calls other member functions
** to get a count of the items in the inventory. Then, it prints those
** counts for the user. The function requires no parameters and returns
** void.
*********************************************************************/

void Inventory::printInventory() {

    std::cout << "\t┌─────────────────────────────────────────┐" << std::endl;
    if (numBattery() == 0 && numArtifact() == 0) {
        std::cout << "\t|  Inventory:     (EMPTY)                 |" << std::endl;
    } else if (numBattery() > 0 && numBattery() < 10 && numArtifact() == 0) {
        std::cout << "\t|  Inventory:     Batteries (x" << numBattery() << ")          |" << std::endl;
    } else if (numBattery() == 10 && numArtifact() == 0) {
        std::cout << "\t|  Inventory:     Batteries (x10)         |" << std::endl;
    } else if (numBattery() == 0 && numArtifact() == 10) {
        std::cout << "\t|  Inventory:     Artifacts (x10)         |" << std::endl;
    } else if (numBattery() == 0 && numArtifact() > 0 && numArtifact() < 10) {
        std::cout << "\t|  Inventory:     Artifacts (x" << numArtifact() << ")          |" << std::endl;
    } else {
        std::cout << "\t|  Inventory:     Batteries (x" << numBattery() << ")          |" << std::endl;
        std::cout << "\t|                 Artifacts (x" << numArtifact() << ")          |" << std::endl;
    }
    std::cout << "\t└─────────────────────────────────────────┘" << std::endl;
}


/*********************************************************************
** Description: The numBattery method iterates over the Inventory
** container and counts the number of batteries in the list. It
** requires no parameters and returns a count of the batteries in
** the Inventory container.
*********************************************************************/

int Inventory::numBattery() {

    int batteryCount = 0;

    for (traveler = items.begin(); traveler != items.end(); ++traveler) {

        if (*traveler == power) {
            batteryCount++;
        }

    }
    return batteryCount;
}


/*********************************************************************
** Description: The numArtifact method iterates over the Inventory
** container and counts the number of artifacts in the list. It
** requires no parameters and returns a count of the alien artifacts
** in the Inventory container.
*********************************************************************/

int Inventory::numArtifact() {

    int artifactCount = 0;

    for (traveler = items.begin(); traveler != items.end(); ++traveler) {

        if (*traveler == artifact) {
            artifactCount++;
        }
    }
    return artifactCount;

}


/*********************************************************************
** Description: The addBattery pushes an item into the list container.
** The item is added to the front of the list. If the user has 10 items,
** they cannot add an additional item to the list. The maximum size of
** the Inventory is 10. The function requires no parameters and returns
** void.
*********************************************************************/

void Inventory::addBattery() {

    if (items.size() < 10) {

        items.push_front(power);

        std::cout << "\tYou added one (1) battery to your inventory." << std::endl;

    } else {

        std::cout << "\tYou can't carry anymore items! \n\tYou'll have to drop something first." << std::endl;

    }
}


/*********************************************************************
** Description: The addArtifact pushes an item into the list container.
** The item is added to the front of the list. If the user has 10 items,
** they cannot add an additional item to the list. The maximum size of
** the Inventory is 10. The function requires no parameters and returns
** void.
*********************************************************************/

void Inventory::addArtifact() {

    if (items.size() < 10) {

        items.push_front(artifact);

        std::cout << "\tYou added (1) alien artifact to your inventory." << std::endl;

    } else {

        std::cout << "\tYou can't carry anymore items! \n\tYou'll have to drop something first." << std::endl;
    }
}


/*********************************************************************
** Description: The removeBattery function iterates over the list and
** locates a battery. It erases that object from the list, deleting it.
** The function requires no parameters and returns void.
*********************************************************************/

void Inventory::removeBattery() {

    traveler = items.begin();

    if (numBattery() > 0) {

        traveler = std::find(items.begin(), items.end(), power);
        items.erase(traveler);

        std::cout << "\tYou dropped one of the batteries you were carrying." << std::endl;

    } else {

        std::cout << "\tYou don't have anymore batteries." << std::endl;
    }

}


/*********************************************************************
** Description: The removeArtifact function iterates over the list and
** locates an alien artifact. It erases that object from the list,
** deleting it. The function requires no parameters and returns void.
*********************************************************************/

void Inventory::removeArtifact() {

    traveler = items.begin();

    if (numArtifact() > 0) {

        traveler = std::find(items.begin(), items.end(), artifact);
        items.erase(traveler);

        std::cout << "\tYou dropped one of the alien artifacts." << std::endl;

    } else {

        std::cout << "\tYou don't have any artifacts." << std::endl;
    }

}


/*********************************************************************
** Description: The useBattery function requires the flashlight's current
** battery level as a parameter. It locates a battery by iterating over
** the list container (or prints that the user has no batteries) and
** deletes that battery object. Then, it increases the battery level
** variable and returns it. The battery level cannot go higher than 100.
*********************************************************************/

int Inventory::useBattery(int juice) {

    traveler = items.begin();

    if (numBattery() > 0) {

        traveler = std::find(items.begin(), items.end(), power);
        items.erase(traveler);

        if (juice + 50 > 100) {

            juice = 100;
            std::cout << "\tYou used a battery! Your battery is now at 100%!" << std::endl;
            return juice;

        } else {

            juice = juice + 50;
            std::cout << "\tYou used a battery! Your battery is now at " << juice << "%!" << std::endl;
            return juice;

        }

    } else {

        std::cout << "\tYou don't have any batteries. :(" << std::endl;

        return juice;
    }
}


/*********************************************************************
** Description: The freeInventory function identifies whether or not
** an inventory instance has been created. If it has, it deletes it.
** Then, it sets the instance pointer to nullptr. The function requires
** no parameters and returns void.
*********************************************************************/

void Inventory::freeInventory() {

    if (instance != nullptr) {
        delete instance;
    }

    instance = nullptr;
}