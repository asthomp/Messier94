/*********************************************************************
** Program name: Project 5
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Ship class is derived from the Space base class. It
** represents the UFO crash site on the game board. The class has two
** functions that override Space's pure virtual functions: action
** and event. This header file has include guards to prevent duplication.
*********************************************************************/

#include "Ship.hpp"
#include "Inventory.hpp"

Ship::Ship() : Space() {

}


/*********************************************************************
** Description: The event function describes the setting to the user.
** It requires no parameters and returns void.
*********************************************************************/

void Ship::event() {

    std::cout << "\tYou're at the impact site.\n\n"
                 "\tA huge crater has torn the earth asunder. Unknown machinery and debris \n"
                 "\tspark and beep, smoke rising from their electrical components. In the\n"
                 "\tcenter of the crater, there's an alien ship, clearly damaged. You\n"
                 "\tapproach it and press your hand against the metal. It's oddly cool." << std::endl;
}


/*********************************************************************
** Description: The action function represents the action that takes place
** when a user enters a Ship space. It determines whether or not the user
** has an artifact in their inventory. If they don't, it prompts the user
** to continue the search. If they do, the game will proceed to the end-
** of-game puzzle. It requires no parameters and returns void.
*********************************************************************/

    void Ship::action() {

        Inventory *items = Inventory::getInventory();

        std::cout << "\n\tDirectly in front of you is a strange metallic surface. It turns on\n"
                     "\twhen you approach. Alien symbols quickly propagate across the screen,\n"
                     "\tglowing in the darkness. It must be some sort of computer! But, one\n"
                     "\tof the metallic panels is missing. " << std::endl;

        if (items->numArtifact() > 0) {

            std::cout << "\n\tYour artifact might fit. Let's try it...\n";

        } else {

            std::cout << "\n\tYou should probably search the area for alien artifacts.\n" << std::endl;

        }
    }
