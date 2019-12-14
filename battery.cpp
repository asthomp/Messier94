/*********************************************************************
** Program name: Messier94
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The battery function receives an integer from 0-100 as
** a parameter and prints a graphic representing the battery level of
** the player's flashlight. It returns void.
*********************************************************************/

#include "battery.hpp"

void battery(int levels) {
    if (levels == 100) {
        std::cout << "                                        [FLASHLIGHT BATTERY %] ║████████████████████║";
    } else if (levels >= 80 && levels <= 99) {
        std::cout << "                                        [FLASHLIGHT BATTERY %] ║██████████████████░░║";
    } else if (levels >= 60 && levels <= 79) {
        std::cout << "                                        [FLASHLIGHT BATTERY %] ║███████████████░░░░░║";
    } else if (levels >= 40 && levels <= 59) {
        std::cout << "                                        [FLASHLIGHT BATTERY %] ║██████████░░░░░░░░░░║";
    } else if (levels >= 20 && levels <= 39) {
        std::cout << "                                        [FLASHLIGHT BATTERY %] ║█████░░░░ ! ░░░░░░░░║";
    } else if (levels >= 1 && levels <= 19) {
        std::cout << "                                        [FLASHLIGHT BATTERY %] ║██░░░░░░░ ! ░░░░░░░░║";
    } else {
        std::cout << "                                        [FLASHLIGHT BATTERY %] ║░░░░░░░░░ X ░░░░░░░░║";
    }
    std::cout << std::endl;
}