/*********************************************************************
** Program name: Messier94
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Game class introduces the user to the game,
** prints the map, manages player movement, and monitors all
** conditions related to winning or losing. Each round, a new
** Game object is created and, upon meeting the criteria for
** winning or losing, it is destroyed.
*********************************************************************/

#include "Game.hpp"

/*********************************************************************
** Description: This constructor creates a Game object. First, it
** introduces the user to the game. Then, the user plays a round that
** includes a brief tutorial. Next, the game iterates through additional
** rounds until it identifies one of the end-of-game conditions.
*********************************************************************/

Game::Game() {

    intro();
    pause();
    divider();
    battery(level);
    gameboard.printMap();

    std::cout
            << "\tYou step outside your house. In the distance, you can smell smoke. "
               "\n\tThe explosion came from somewhere beyond the forest.";

    // This section prints a mini tutorial, explaining the game mechanics.
    // The tutorial isn't offered in future rounds.

    movementTutorial();

    movePlayer();

    // After each movement, the battery level decreases by 20%.

    level = level - 20;

    // There are three end-of-game conditions: 1) the user's flashlight is dead (no more
    // available moves), 2) the user died (not a win but still game over), and 3) the
    // user won (both a win and game over). These conditions are all tracked with three
    // boolean values: flashlight, win and, end. If any of the various end-of-game conditions
    // are met, no more rounds can be played.

    while (!end) {

        divider();
        battery(level);
        gameboard.printMap();

        if (level <= 0) {

            flashlight = false;
            end = true;

        } else {

            level = level - 20;
            gameboard.player->event();
            gameboard.player->action();

            // If the user is at the alien ship and they have at least one artifact,
            // the ship unlocks.

            if (gameboard.player->getCol() == 78 && gameboard.player->getRow() == 9 && items->numArtifact() > 0) {
                unlockShip();

            } else {

                // If the user is at the alien ship but they do not have any artifacts, they
                // can continue searching the map.

                movePlayer();
            }
        }
    }
    ending();
    divider();
}


/*********************************************************************
** Description: The movePlayer function is responsible for moving
** the player on the game board. The player is actually a pointer
** that points to a "node" (Space object) in a list/mesh (Board object).
** First, a player provides a control character ([a] for move left,
** [w] for move up, [s] for move down, [d] for move right, or [i]
** to access their inventory). The program will re-prompt the user
** to provide a control character under two conditions: 1) the
** user accessed their inventory instead of moving, and 2) the
** space the user wants to move to is out-of-bounds. Upon providing
** a possible move, the player pointer is updated to the new location.
** The function requires no parameters and returns void.
*********************************************************************/

void Game::movePlayer() {

    move = false;
    while (!move) {

        direction = getMove("What would you like to do?");

        if (direction == 'I') {
            manageInventory();
            std::cout << std::endl;
        }

        move = gameboard.checkBounds(direction);

    }

    // This section of code updates the player's location.

    if (direction == 'W') {
        gameboard.setPlayerTop();
    } else if (direction == 'A') {
        gameboard.setPlayerLeft();
    } else if (direction == 'S') {
        gameboard.setPlayerBottom();
    } else if (direction == 'D') {
        gameboard.setPlayerRight();
    } else {
        std::cout << "\tSomething went wrong!" << std::endl;
    }
}


/*********************************************************************
** Description: The manageInventory function handles all aspects of
** the player's inventory. All operations are performed by modifying
** the Inventory singleton. The function requires no parameters and
** returns void.
*********************************************************************/

void Game::manageInventory() {

    invExit = false;
    std::cout << std::endl;

    while (!invExit) {

        // This code prints the inventory graphic.
        // It lets the user see the contents of the inventory.

        items->printInventory();

        // This menu lets the user manipulate the inventory in various ways.

        invMenuStr = "\n\t[1] <- use battery\n\t[2] <- drop battery\n\t[3] <- drop artifact\n\t[4] <- close inventory";
        int invMenu = menu(1, 4, invMenuStr);

        if (invMenu == 1) {

            // This code increases the user's battery level.

            std::cout << std::endl;
            level = items->useBattery(level);
            std::cout << std::endl;

        } else if (invMenu == 2) {

            // This code lets the user drop a battery.

            std::cout << std::endl;
            items->removeBattery();
            std::cout << std::endl;

        } else if (invMenu == 3) {

            // This code lets the user drop an artifact.

            std::cout << std::endl;
            items->removeArtifact();
            std::cout << std::endl;

        } else if (invMenu == 4) {

            invExit = true;

        } else {
            std::cout << "\n\tSomething went wrong!\n" << std::endl;
        }
    }
}


/*********************************************************************
** Description: The movementTutorial prints an initial explanation for
** the user, detailing the game's controls and mechanic. The function
** requires no parameters and returns void.
*********************************************************************/

void Game::movementTutorial() {

    std::cout << "\n" << std::endl;
    std::cout << "┌───────────────────────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "| To move the player, press one of the movement keys on the keyboard and hit ENTER. |" << std::endl;
    std::cout << "|               [a] <- left   [w] <- up   [s] <- down   [d] <-right                 |" << std::endl;
    std::cout << "|                                                                                   |" << std::endl;
    std::cout << "|            To manage the player's inventory, press [i] and hit ENTER.             |" << std::endl;
    std::cout << "|         You'll get an opportunity to move after checking your inventory.          |" << std::endl;
    std::cout << "|                                                                                   |" << std::endl;
    std::cout << "|                Make sure your flashlight has enough battery power.                |" << std::endl;
    std::cout << "|                You wouldn't want to be stuck out here in the dark.                |" << std::endl;
    std::cout << "└───────────────────────────────────────────────────────────────────────────────────┘\n" << std::endl;
}


/*********************************************************************
** Description: The game's final puzzle executes if the user has an
** artifact in their inventory and is located on the alien ship Space.
** It requires the user to complete a sequence. The provided graphic
** contains four of the lunar phases - one is missing. The correct solution
** is to select the New Moon icon (#3). The function requires no parameters
** and returns void.
*********************************************************************/

void Game::unlockShip() {

    clear();
    pause();
    divider();
    std::cout << "┌───────────────────────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "|       Five boxes appear on the screen, some filled with different pictures.       |" << std::endl;
    std::cout << "|            One box is empty. It's almost like a... computer password.             |" << std::endl;
    std::cout << "|                     Which symbol would complete the sequence?                     |" << std::endl;
    std::cout << "└───────────────────────────────────────────────────────────────────────────────────┘\n" << std::endl;

    // ASCII art adapted from JGS' work which can be found at: https://www.asciiart.eu/space/moons

    std::cout << "    ┌─────────────┐┌─────────────┐┌─────────────┐┌─────────────┐┌─────────────┐" << std::endl;
    std::cout << "    |             ||    _..._    ||    _..._    ||    _..._    ||    _..._    |" << std::endl;
    std::cout << "    |             ||  .::::. `.  ||  .::::  `.  ||  .::'   `.  ||  .'     `.  |" << std::endl;
    std::cout << "    |             || :::::::.  : || ::::::    : || :::       : || :         : |" << std::endl;
    std::cout << "    |             || :::::::.  : || ::::::    : || :::       : || :         : |" << std::endl;
    std::cout << "    |             || '::::::' .' || ':::::   .' || '::.     .' || '.       .' |" << std::endl;
    std::cout << "    |             ||   `'::'-'   ||   `'::.-'   ||   `':..-'   ||   `-...-'   |" << std::endl;
    std::cout << "    └─────────────┘└─────────────┘└─────────────┘└─────────────┘└─────────────┘\n" << std::endl;
    std::cout << "    ┌─────────────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "    |   ↓ Choose one of the five symbols below to fill in the empty box. ↓    |" << std::endl;
    std::cout << "    └─────────────────────────────────────────────────────────────────────────┘\n" << std::endl;
    std::cout << "    ┌─────────────┐┌─────────────┐┌─────────────┐┌─────────────┐┌─────────────┐" << std::endl;
    std::cout << "    |    _..._    ||    _..._    ||    _..._    ||    _..._    ||    _..._    |" << std::endl;
    std::cout << "    |  .::::  `.  ||  .::::. `.  ||  .:::::::.  ||  .'     `.  ||  .::'   `.  |" << std::endl;
    std::cout << "    | ::::::    : || :::::::.  : || ::::::::::: || :         : || :::       : |" << std::endl;
    std::cout << "    | ::::::    : || :::::::.  : || ::::::::::: || :         : || :::       : |" << std::endl;
    std::cout << "    | ':::::   .' || '::::::' .' || ':::::::::' || '.       .' || '::.     .' |" << std::endl;
    std::cout << "    |   `':::''   ||   `'::'-'   ||   `':::''   ||   `-...-'   ||   `':..-'   |" << std::endl;
    std::cout << "    └─────────────┘└─────────────┘└─────────────┘└─────────────┘└─────────────┘" << std::endl;
    std::cout << "    ┌─────────────┐┌─────────────┐┌─────────────┐┌─────────────┐┌─────────────┐" << std::endl;
    std::cout << "    |      1      ||      2      ||      3      ||      4      ||      5      |" << std::endl;
    std::cout << "    └─────────────┘└─────────────┘└─────────────┘└─────────────┘└─────────────┘\n" << std::endl;

    key = menu(1, 5, "What's the worst that could happen? Go ahead. Pick a symbol.");

    if (key == 3) {

        // If the user chooses the New Moon icon (#3), the game is won.

        std::cout << "\n\tYou drag the icon into the appropriate place on the screen. It glows.\n" << std::endl;

        win = true;
        end = true;

    } else {

        // If the user chooses any icon other than the New Moon icon (#3), the game is over and the
        // player dies.

        std::cout << "\n\tA bright light emanates from the console. That's the last thing you remember.\n" << std::endl;

        win = false;
        end = true;

    }
}


/*********************************************************************
** Description: The ending function handles printing the end-of-game
** results. There are three possible endings, all determined by the
** settings of three booleans: end, flashlight, and win. The function
** requires no parameters and returns void.
*********************************************************************/

void Game::ending() {

    if (!win && !flashlight) {

        std::cout << "  ┌──────────────────────────────────────────────────────────────────────────────┐" << std::endl;
        std::cout << "  |                                                                              |" << std::endl;
        std::cout << "  |                    Your flashlight is out of batteries...                    |" << std::endl;
        std::cout << "  |                  Something rushes past you in the darkness.                  |" << std::endl;
        std::cout << "  |                      It wasn't human. You'd better run.                      |" << std::endl;
        std::cout << "  |                                                                              |" << std::endl;
        std::cout << "  |                                   Game Over                                  |" << std::endl;
        std::cout << "  └──────────────────────────────────────────────────────────────────────────────┘" << std::endl;

    } else if (!win && flashlight) {

        std::cout << "  ┌──────────────────────────────────────────────────────────────────────────────┐" << std::endl;
        std::cout << "  |                                                                              |" << std::endl;
        std::cout << "  |                            You died horrifically!                            |" << std::endl;
        std::cout << "  |                           No. Really. It was awful.                          |" << std::endl;
        std::cout << "  |                                                                              |" << std::endl;
        std::cout << "  |                                   Game Over                                  |" << std::endl;
        std::cout << "  └──────────────────────────────────────────────────────────────────────────────┘" << std::endl;

    } else {

        std::cout << "  ┌──────────────────────────────────────────────────────────────────────────────┐" << std::endl;
        std::cout << "  |                                                                              |" << std::endl;
        std::cout << "  |       The door to the ship opens and a strange creature gestures at you.     |" << std::endl;
        std::cout << "  |              You've made first contact with a friendly alien race.           |" << std::endl;
        std::cout << "  |                      And oh boy, have you got questions.                     |" << std::endl;
        std::cout << "  |                                                                              |" << std::endl;
        std::cout << "  |                                   Game Over                                  |" << std::endl;
        std::cout << "  └──────────────────────────────────────────────────────────────────────────────┘" << std::endl;
    }
}

/*********************************************************************
** Description: The Game destructor calls two custom functions to
** free memory. First, the Inventory singleton is destroyed. Then,
** a function is called to destroy the Board object mesh, its Space
** objects, and the dynamic 2D array that holds the map graphic.
*********************************************************************/

Game::~Game() {

    Inventory::freeInventory();

    gameboard.deleteBoard();

}