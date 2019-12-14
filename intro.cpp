/*********************************************************************
** Program name: Project 5
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The introduction function prints opening prompts for
** the user. The divider function prints a divider bar to the console
** to improve the user interface. The pause function pauses the game
** until the user hits ENTER. The clear function clears the buffer in
** preparation for the pause function. All functions require no
** parameters and return void.
*********************************************************************/

#include <iostream>
#include "Inventory.hpp"
#include <limits>


/*********************************************************************
** Description: The introduction functions prints opening prompts for
** the user. It requires no parameters and returns void.
*********************************************************************/

void intro() {

    // This prints the title screen.
    // ASCII art generated using the ASCII Art Generator by Patrick Gillespie
    // at http://patorjk.com/software/taag/

    std::cout << "\n`7MMM.     ,MMF'                           db                                             \n";
    std::cout << "  MMMb    dPMM" << std::endl;
    std::cout << "  M YM   ,M MM   .gP\"Ya  ,pP\"Ybd ,pP\"Ybd `7MM   .gP\"Ya  `7Mb,od8      .d*\"*bg.      ,AM\n";
    std::cout << "  M  Mb  M' MM  ,M'   Yb 8I   `\" 8I   `\"   MM  ,M'   Yb   MM' \"'     6MP    Mb     AVMM   \n";
    std::cout << "  M  YM.P'  MM  8M\"\"\"\"\"\" `YMMMa. `YMMMa.   MM  8M\"\"\"\"\"\"   MM         YMb    MM   ,W' MM\n";
    std::cout << "  M  `YM\'   MM  YM.    , L.   I8 L.   I8   MM  YM.    ,   MM          `MbmmdM9 ,W\'   MM\n";
    std::cout << ".JML. `\'  .JMML. `Mbmmd' M9mmmP\' M9mmmP' .JMML. `Mbmmd' .JMML.             .M' AmmmmmMMmm\n";
    std::cout << "_________________________________________________________________________ .d9 _____  MM\n";
    std::cout << "                                                                       m\"'           MM   \n\n";

    // This prints the introductory prompt.

    std::cout << "  ┌──────────────────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "  |                                                                              |" << std::endl;
    std::cout << "  |                     There's been an explosion outside.                       |" << std::endl;
    std::cout << "  |                  A strange light illuminates the night sky.                  |" << std::endl;
    std::cout << "  |                    You should go find out what happened.                     |" << std::endl;
    std::cout << "  |                                                                              |" << std::endl;
    std::cout << "  └──────────────────────────────────────────────────────────────────────────────┘\n" << std::endl;


    // This prints information about the user's first item.
    // ASCII art by Joan Stark at https://www.oocities.org/spunk1111/electro.htm

    std::cout << "\t\t\t                    __    .-----,\n"
                 "\t\t\t     .-------------(__)--'     / \\\n"
                 "\t\t\t    /  ========         :     |.-|\n"
                 "\t\t\t    \\                   :     |'-|\n"
                 "\t\t\t     '-------------------.     \\ /\n"
                 "\t\t\t                         '-----' \n" << std::endl;

    std::cout << "  ┌──────────────────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "  |                                                                              |" << std::endl;
    std::cout << "  |       Wait! It's dark! Before you leave, you should grab a flashlight.       |" << std::endl;
    std::cout << "  |      You'll want to take some batteries with you, too, just in case...       |" << std::endl;
    std::cout << "  |                                                                              |" << std::endl;
    std::cout << "  └──────────────────────────────────────────────────────────────────────────────┘" << std::endl;

    std::cout << std::endl;
    Inventory::getInventory()->addBattery();
    std::cout << std::endl;

}


/*********************************************************************
** Description: The divider function prints a bar to improve the user
** interface. It requires no parameters and returns void.
*********************************************************************/

void divider() {

    std::cout << "\n─────────────────────────────────────────────────────────────────────────────────────\n" <<std::endl;

}


/*********************************************************************
** Description: The pause functions pauses the game until the user
** hits ENTER. It requires no parameters and returns void.
*********************************************************************/

// Code adatped from Duthomhas's example (Jan 28, 2009, http://www.cplusplus.com/forum/articles/7312/).

void pause() {

    int input;

    printf( "\tPress ENTER to continue... " );
    fflush( stdout );
    do input = getchar(); while ((input != '\n') && (input != EOF));
}

/*********************************************************************
** Description: The clear functions flushes the buffer in preparation
** for the pause function. It requires no parameters and returns void.
*********************************************************************/

void clear(){

    std::cout << std::flush << std::endl;
    std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );

}
