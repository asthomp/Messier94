/*********************************************************************
** Program name: Messier94
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Artifact derived class inherits from the Space base class. It
** represents a space on the game board, specifically an alien structure. The
** class has two unique functions: event and action. These functions handle
** user interactions that can only take place in a artifact. The artifact
** serves one purpose: to ensure the user gets at least one artifact
** for the final puzzle.
*********************************************************************/

#include "Artifact.hpp"
#include "Inventory.hpp"

Artifact::Artifact() : Space() {

}

/*********************************************************************
** Description: The event function describes the setting to the user.
** It requires no parameters and returns void.
*********************************************************************/

void Artifact::event() {
    std::cout << "\tYou see an alien artifact.\n\n"
                 "\tThe huge alien structure rises up from the ground in front of you.\n"
                 "\tIt is covered with strange, glowing symbols. Fires have destroyed \n"
                 "\tmuch of the landscape around the impact site. But, it's clear that \n"
                 "\tthis thing crashed into the planet with tremendous force. You \n"
                 "\tdecide to gather some of the alien artifacts scattered around \n"
                 "\tthe area. Who knows, maybe you'll write a book?" << std::endl;
}


/*********************************************************************
** Description: The action function represents the action that takes place
** when a user enters an Artifact space. It essentially just adds an artifact
** to the user's inventory to ensure that, even given atrocious luck, the
** user will have one artifact by end game. It requires no parameters and
** returns void.
*********************************************************************/

void Artifact::action() {

    std::cout << std::endl;
    Inventory::getInventory()->addArtifact();
    std::cout << std::endl;

    std::cout << "\tYou'd better keep moving.\n" << std::endl;
}