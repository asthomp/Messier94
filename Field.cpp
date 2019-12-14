/*********************************************************************
** Program name: Messier94
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Field derived class inherits from the Space class. It
** represents a space on the game board, specifically a corn field. The
** class has two unique functions: event and action. These functions handle
** user interactions that can only take place in a corn field.
*********************************************************************/

#include "Field.hpp"
#include "Inventory.hpp"

Field::Field() : Space() {

}

/*********************************************************************
** Description: The event function describes the setting to the user.
** It requires no parameters and returns void.
*********************************************************************/

void Field::event() {

    std::cout << "\tYou're in a corn field.\n\n"
                 "\tThere's a strong, earthy smell here. You heart beats faster.\n"
                 "\tEars of corn brush against your skin as you move deeper\n"
                 "\tinto the field. It feels like it goes on forever. Suddenly,\n"
                 "\tyou stumble over a strange mound of dirt. The earth here\n"
                 "\tlooks like it was disturbed recently." << std::endl;
}


/*********************************************************************
** Description: This function lets the user perform an action unique to
** a particular space. For example, the actions that can be performed
** in a forest are different than those performed in a corn field. The
** user can execute multiple actions each time they enter a particular
** space. Afterwards, they will be queued to move the character. This
** function requires no parameters and returns void.
*********************************************************************/

void Field::action() {

    explore=true;

    while (explore) {

        chance = randomEvent();
        choice = 0;

        // This code prints an action menu for the user.
        choice = menu(1, 4,
                      "\n\t[1] <- search field\n\t[2] <- inspect corn\n\t[3] <- dig \n\t[4] <- quit exploring");

        // When the user selects an action, the action's function is called. Each
        // action function requires a random number to determine which event will
        // happen. For each action, four unique events are possible.

        if (choice == 1) {
            search(chance);
        } else if (choice == 2) {
            inspect(chance);
        } else if (choice == 3) {
            dig(chance);
        } else {
            explore = false;
            std::cout << std::endl;
        }
    }

    // After the action menu is exited, the user will be returned to
    // the movement/inventory menu.

    std::cout << "\tYou decided to keep moving.\n" << std::endl;
}


/*********************************************************************
** Description: This function represents one of the actions that can
** be performed in this space. There are four unique outcomes that
** can result from selecting this action. The function requires a
** random integer (Range: 1-4) as a parameter and returns void.
*********************************************************************/

void Field::search(int chance) {

    chance = randomEvent();

    if (chance == 1) {

        std::cout << "\n\tThe corn is tall above you, obscuring your view of what\n"
                     "\tlies ahead. Something rushes past you in the darkness.\n"
                     "\tYou didn't get a good look at it but it wasn't human." << std::endl;

    } else if (chance == 2) {

        std::cout << "\n\tThe corn rustles around you. You can hear something moving \n"
                     "\tin the darkness. From somewhere to your left, you hear a \n"
                     "\tstrange, shuffling noise and heavy breathing." << std::endl;


    } else if (chance == 3) {

        std::cout << "\n\tYou push stalks of corn aside and move into an open \n"
                     "\tclearing. The corn has been flattened into an intricate \n"
                     "\tpattern. You can't tell what the design is but you're pretty\n"
                     "\tsure you're standing in a crop circle. There's a backpack\n"
                     "\tsitting off to the side. Was someone here before you?" << std::endl;

        std::cout << std::endl;
        Inventory::getInventory()->addBattery();

    } else {

        std::cout << "\n\tYou find an old truck nearby. It looks like it crashed while \n"
                     "\tdriving through the field. Why would someone be driving\n"
                     "\tthrough a corn field in the first place? There's no sign of\n"
                     "\tthe driver but you find a battery in the glove compartment." << std::endl;

        std::cout << std::endl;
        Inventory::getInventory()->addBattery();
    }
}


/*********************************************************************
** Description: This function represents one of the actions that can
** be performed in this space. There are four unique outcomes that
** can result from selecting this action. The function requires a
** random integer (Range: 1-4) as a parameter and returns void.
*********************************************************************/

void Field::inspect(int chance) {

    chance = randomEvent();

    if (chance == 1) {

        std::cout << "\n\tA strange slime coats the corn stalks here. It's viscous,\n"
                     "\tclear, and flecked with black spots. A strange buzzing sound\n"
                     "\tis all around you and... did it just move?" << std::endl;

    } else if (chance == 2) {

        std::cout << "\n\tA red cotton-like substance coats the corn. You pinch\n"
                     "\tsome of it between your fingers. It burns! Quickly, you\n"
                     "\tbrush it off on your jeans. It's probably fine." << std::endl;

    } else if (chance == 3) {

        std::cout << "\n\tThe corn stalks are wilted, their leaves covered in black\n"
                     "\tvein-like growths. It looks like some sort of disease or\n"
                     "\tblight. You don't remember seeing that earlier..." << std::endl;

    } else {

        std::cout << "\n\tThe corn doesn't appear out of the ordinary. Really.\n"
                     "\tNo, really, it's fine. Totally normal corn." << std::endl;

    }
}


/*********************************************************************
** Description: This function represents one of the actions that can
** be performed in this space. There are four unique outcomes that
** can result from selecting this action. The function requires a
** random integer (Range: 1-4) as a parameter and returns void.
*********************************************************************/

void Field::dig(int chance) {

    chance = randomEvent();

    if (chance == 1) {

        std::cout << "\n\tYou use your hands to dig deep into the disturbed earth.\n"
                     "\tThere's something here... a strange metallic object. When\n"
                     "\tyou pick it up, you shiver. You know, instinctively, that\n"
                     "\tthis isn't something from Earth. This is alien." << std::endl;

        std::cout << std::endl;
        Inventory::getInventory()->addArtifact();

    } else if (chance == 2) {

        std::cout << "\n\tYou use the edge of your sneaker to push dirt aside.\n"
                     "\tThere's nothing here of interest, though. Just dirt." << std::endl;

    } else if (chance == 3) {


        std::cout << "\n\tThere's... clothing here. You find some overalls, a jacket,\n"
                     "\ta flashlight, and a pair of shoes. Each item is covered with\n"
                     "\ta black, slimy substance. It stings when you touch it. But,\n"
                     "\tthere's no body... so it couldn't be foul play, right?" << std::endl;

        std::cout << std::endl;
        Inventory::getInventory()->addBattery();

    } else {

        std::cout << "\n\tYou start digging using the end of your flashlight. There's some\n"
                     "\tsort of black, metallic object buried here. When you touch it, it\n"
                     "\tshatters! And, something slithers out of it...disappearing into\n"
                     "\tthe darkness. You didn't see it very well - it moved too fast." << std::endl;

        std::cout << std::endl;
        Inventory::getInventory()->addArtifact();

    }
}