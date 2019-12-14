/*********************************************************************
** Program name: Messier94
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Meadow derived class inherits from the Space class. It
** represents a space on the game board, specifically a meadow. The
** class has two unique functions: event and action. These functions handle
** user interactions that can only take place in a meadow.
*********************************************************************/

#include "Meadow.hpp"
#include "Inventory.hpp"

Meadow::Meadow() : Space() {

}

/*********************************************************************
** Description: The event function describes the setting to the user.
** It requires no parameters and returns void.
*********************************************************************/

void Meadow::event() {
    std::cout << "\tYou're in a meadow. \n\n"
                 "\tWith your flashlight, you can see the tall grass around you.\n"
                 "\tThere's a rustling noise coming from somewhere nearby. The \n"
                 "\tair smells smokey; you must be getting closer to the source\n"
                 "\tof the explosion." << std::endl;
}


/*********************************************************************
** Description: This function lets the user perform an action unique to
** a particular space. For example, the actions that can be performed
** in a forest are different than those performed in a corn field. The
** user can execute multiple actions each time they enter a particular
** space. Afterwards, they will be queued to move the character. This
** function requires no parameters and returns void.
*********************************************************************/

void Meadow::action() {

    explore = true;

    while (explore) {

        chance = randomEvent();
        choice = 0;

        // This code prints an action menu for the user.

        choice = menu(1, 4, "\n\t[1] <- search the meadow\n\t[2] <- investigate grass\n\t[3] <- dig\n\t[4] <- quit exploring");

        // When the user selects an action, the action's function is called. Each
        // action function requires a random number to determine which event will
        // happen. For each action, four unique events are possible.

        if (choice == 1) {
            search(chance);
        } else if (choice == 2) {
            grass(chance);
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

void Meadow::search(int chance) {

    if (chance == 1) {

        std::cout << "\n\tThere's a rucksack hidden in the tall grass. It has some supplies\n"
                     "\tin it. Otherwise, there's nothing unusual here." << std::endl;

        std::cout << std::endl;
        Inventory::getInventory()->addBattery();

    } else if (chance == 2) {

        std::cout << "\n\tThere's... clothing here. You find some overalls, a jacket,\n"
                     "\ta flashlight, and a pair of shoes. Each item is covered with\n"
                     "\ta black, slimy substance. It stings when you touch it. But,\n"
                     "\tthere's no body... so it couldn't be foul play, right?" << std::endl;

        std::cout << std::endl;
        Inventory::getInventory()->addBattery();

    } else if (chance == 3) {

        // This event only forces the user to lose a battery if they *have* a battery.

        if (Inventory::getInventory()->numBattery() > 0) {

            std::cout << "\n\tThe tall grass makes it difficult to see anything, even with\n"
                         "\ta flashlight. You trip! One of your batteries falls out of your\n"
                         "\tbag and disappears into the underbrush. You decide it's too\n"
                         "\trisky to recover it." << std::endl;

            std::cout << std::endl;
            Inventory::getInventory()->removeBattery();

        } else {

            std::cout << "\n\tThe tall grass makes it difficult to see anything, even with a\n"
                         "\tflashlight. You trip! You've fallen into a strange puddle of black\n"
                         "\tgoo and frantically try to wipe it from your eyes. You should get\n"
                         "\tout of here!" << std::endl;
        }

    } else {

        std::cout << "\n\tThe grass is catching fire! You frantically try to stomp it\n"
                     "\tout and, after a little bit, you succeed! Under the burnt\n"
                     "\tgrass and debris is a strange electronic device. It doesn't\n"
                     "\tlook like anything you've ever seen before." << std::endl;

        std::cout << std::endl;
        Inventory::getInventory()->addArtifact();

    }
}


/*********************************************************************
** Description: This function represents one of the actions that can
** be performed in this space. There are four unique outcomes that
** can result from selecting this action. The function requires a
** random integer (Range: 1-4) as a parameter and returns void.
*********************************************************************/

void Meadow::grass(int chance) {

    if (chance == 1) {

        std::cout << "\n\tThere's a strange light overhead. It hovers above you\n"
                     "\tand your whole body vibrates. You can see it clearly. It's\n"
                     "\tsome sort of strange, silver disc. You can't believe it.\n"
                     "\tYou're looking at an actual UFO! It stays perfectly still\n"
                     "\tfor a few moments and then, it disappears as quickly as\n"
                     "\tit came." << std::endl;

    } else if (chance == 2) {

        std::cout << "\n\tThere's something hiding in the tall grass. You can hear it\n"
                     "\tmoving in quick bursts. Out of the corner of your eye, you think\n"
                     "\tyou see it... a hulking gray mass of scales. You decide to run." << std::endl;

    } else if (chance == 3) {

        std::cout << "\n\tFlashing lights suddenly swarm around you. You reach out to\n"
                     "\ttouch one and it disappears. The lights flash red and then\n"
                     "\tgold and then green again. In a blink, they vanish." << std::endl;

    } else {

        std::cout << "\n\tThe grass doesn't appear out of the ordinary. Really.\n"
                     "\tNo, really, it's fine. Totally normal grass." << std::endl;
    }
}


/*********************************************************************
** Description: This function represents one of the actions that can
** be performed in this space. There are four unique outcomes that
** can result from selecting this action. The function requires a
** random integer (Range: 1-4) as a parameter and returns void.
*********************************************************************/

void Meadow::dig(int chance) {

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


        std::cout << "\n\tThere's... a strange box here. It looks like an emergency\n"
                     "\tsurvival kit. You brush some of the dirt off. What's this\n"
                     "\tdoing out here in the middle of nowhere?" << std::endl;

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