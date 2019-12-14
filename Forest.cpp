/*********************************************************************
** Program name: Project 5
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Forest class is derived from the Space base class. It
** represents a forest on the game board. The class has two functions
** that override Space's pure virtual functions: action and event.
** In addition, Forest objects have three actions specific only to
** them that allow the user to interact with the space.
*********************************************************************/

#include "Forest.hpp"
#include "Inventory.hpp"

Forest::Forest() : Space() {

}


/*********************************************************************
** Description: The event function describes the setting to the user.
** It requires no parameters and returns void.
*********************************************************************/

void Forest::event() {
    std::cout << "\tYou're in a forest.\n\n"
                 "\tTrees tower over you. The wind makes the branches creak like\n"
                 "\trusty hinges. Spindly thorns scratch at your clothing as you \n"
                 "\tpass and the smell of pine invades your nostrils. Underneath\n"
                 "\tyour feet, needles and soft earth quiet your footsteps and, in\n"
                 "\tthe distance, strange lights flicker in bursts of neon green." << std::endl;
}


/*********************************************************************
** Description: This function lets the user perform an action unique to
** a particular space. For example, the actions that can be performed
** in a forest are different than those performed in a corn field. The
** user can execute multiple actions each time they enter a particular
** space. Afterwards, they will be queued to move the character. This
** function requires no parameters and returns void.
*********************************************************************/

void Forest::action() {

    explore = true;

    while (explore) {

        chance = randomEvent();
        choice = 0;

        // This code prints an action menu for the user.

        choice = menu(1, 4,
                      "\n\t[1] <- search the forest\n\t[2] <- follow the lights\n\t[3] <- hide somewhere!\n\t[4] <- quit exploring");

        // When the user selects an action, the action's function is called. Each
        // action function requires a random number to determine which event will
        // happen. For each action, four unique events are possible.

        if (choice == 1) {
            search(chance);
        } else if (choice == 2) {
            lights(chance);
        } else if (choice == 3) {
            hide(chance);
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

void Forest::search(int chance) {

    if (chance == 1) {

        std::cout << "\n\tThere's a rucksack hidden between two of the taller trees. It\n"
                     "\thas some supplies in it. Otherwise, there's nothing unusual here." << std::endl;

        std::cout << std::endl;
        Inventory::getInventory()->addBattery();

    } else if (chance == 2) {

        std::cout << "\n\tA partly cocooned body hangs suspended between a tree's branches.\n"
                     "\tSmall glowing insects crawl out of the corpse's mouth, held open in a\n"
                     "\twordless scream. You find a broken flashlight nearby." << std::endl;

        std::cout << std::endl;
        Inventory::getInventory()->addBattery();

    } else if (chance == 3) {

        std::cout << "\n\tYou decide to climb a tree to get a good vantage point. Halfway\n"
                     "\tup, you smell vinegar and the bark becomes slippery. There's a\n"
                     "\tblack, oil-like substance coating your fingers. It coalesces into\n"
                     "\tvine-like tendrils and burrows into your palms! The pain causes you\n"
                     "\tto black out. Waking up, you can't remember what happened but you're\n"
                     "\tsure that everything is fine." << std::endl;

    } else {

        std::cout << "\n\tThere's an artifact wedged between two trees. Each trunk's bark\n"
                     "\tis scorched by the heat and, higher up, the tree is on fire! When\n"
                     "\tyou reach for the object, though, it's cool to the touch. You \n"
                     "\tknow this isn't a normal piece of metal. This is something else." << std::endl;

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

void Forest::lights(int chance) {

    if (chance == 1) {

        std::cout << "\n\tYou run after the lights. You're not sure how long you chase\n"
                     "\tthem. You only know that you're getting tired. But, you can't\n"
                     "\tseem to stop. Suddenly, the lights go out. You collapse on the\n"
                     "\tground, the muscles in your legs burning from exhaustion. It's\n"
                     "\tbeen hours." << std::endl;

    } else if (chance == 2) {

        std::cout << "\n\tYou follow the lights into a clearing. There's a camp-site here.\n"
                     "\tThe lights came from two head lamps sitting on a stump. Where\n"
                     "\tare the campers?" << std::endl;

        std::cout << std::endl;
        Inventory::getInventory()->addBattery();

    } else if (chance == 3) {

        std::cout << "\n\tThe lights are glittering eyes. You can see them in the darkness.\n"
                     "\tYou started out chasing them but, now, it's clear that they're\n"
                     "\tchasing you. You should get out of here." << std::endl;

    } else {

        std::cout << "\n\tThe green lights swarm around you. Upon closer inspection, you\n"
                     "\tcan see that they're insects. One lands on you. You hold it up\n"
                     "\tso that you can see it better and it burrows into your eye!\n"
                     "\tNow, your head aches and, sometimes, your body seems to move\n"
                     "\ton its own..." << std::endl;
    }
}


/*********************************************************************
** Description: This function represents one of the actions that can
** be performed in this space. There are four unique outcomes that
** can result from selecting this action. The function requires a
** random integer (Range: 1-4) as a parameter and returns void.
*********************************************************************/

void Forest::hide(int chance) {

    if (chance == 1) {

        std::cout << "\n\tYou quickly hide behind a tree and close your eyes. You hid just\n"
                     "\tin time. A scream echoes through the woods. You hear a loud crunch.\n"
                     "\tThen, all's quiet. You wait. When you emerge from your hiding spot,\n"
                     "\tyou find bloodied clothing but there's no trace of a body." << std::endl;

        std::cout << std::endl;
        Inventory::getInventory()->addBattery();

    } else if (chance == 2) {

        std::cout << "\n\tYou turn your flashlight off and hold your breath. There's a strange\n"
                     "\tbuzzing sound nearby. A feeling of dread fills your bones and your\n"
                     "\theart beats fast in your chest. Whatever made the sound is gone just\n"
                     "\tas quickly as it came. When you turn your flashlight back on, you can\n"
                     "\tsee footsteps in the wet earth. They're too close for comfort." << std::endl;

    } else if (chance == 3) {


        std::cout << "\n\tYou crawl into a nearby thicket of trees and underbrush. The foliage is\n"
                     "\tso dense here that you can hardly move. Crawling forward, you reach out\n"
                     "\tto push some ferns aside. Your hand comes away coated in sticky webbing.\n"
                     "\tIn front of you, there's a human-sized cocoon! The dessicated body is\n"
                     "\tswarming with strange, glowing insects. You gather some supplies and\n"
                     "\tescape but not before the swarm gets a taste." << std::endl;

        std::cout << std::endl;
        Inventory::getInventory()->addBattery();

    } else {

        std::cout << "\n\tYou hide behind a tree. There are some supplies hidden here, likely left\n"
                     "\tbehind or lost by hikers. The forest is quiet, though. There doesn't seem\n"
                     "\tto be anything unusual here." << std::endl;

        std::cout << std::endl;
        Inventory::getInventory()->addBattery();
    }
}