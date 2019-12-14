/*********************************************************************
** Program name: Reusable
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The menu functions receive user input (either numeric
** or character), validate that input, and return validated input.
*********************************************************************/

#include <iostream>

/*********************************************************************
** Description: This function requires two integers representing the range
** of menu options and a string representing the text to be printed for
** the user. First, it prints the string of text so that the user knows
** what choices are available. Then, it will loop forever until the
** user provides valid input. For each iteration of the while loop, it
** also clears the input buffer, ensuring a fresh chance for validation
** each time the function loops. After checking the input, the function
** returns the user's (validated) choice as an integer.
*********************************************************************/

int menu(int min, int max, std::string options) {

    int userInput;
    std::cout << "\t" << options << " ";

    while (true) {

        std::cin >> userInput;

        if (std::cin.fail() || std::cin.peek() != '\n' || userInput < min || userInput > max) {
            std::cout << "\tInvalid menu selection. Please try again." << std::endl;
            std::cout << "\tHint: Press ENTER after typing your selection.\n" << std::endl;
            std::cout << "\t" << options << " ";

        } else {
            return userInput;
        }

        //This clears cin and instructs the computer to ignore any remaining characters in the buffer.
        //This ensures that leftover characters don't impact performance when iterating.

        std::cin.clear();
        std::cin.ignore(1000000, '\n');
    }
}


/*********************************************************************
** Description: This function receives a string as a parameter, which
** contains menu prompts, and prints that string. Then, it asks the
** user for keyboard input. The code confirms that it receives the
** correct type of input (character) and the correct number of characters
** (1 and then ENTER). Then, it converts the characters to upper-case and
** checks to see if they are one of the game's control characters: W, A,
** S, D, or I. It returns the validated character.
*********************************************************************/

char getMove(std::string options) {

    char userInput;
    std::cout << "\t" << options << " ";

    while (true) {
        std::cin >> userInput;

        if (std::cin.fail() || std::cin.peek() != '\n') {

            std::cout << "\tYou entered too many characters. Please try again." << std::endl;
            std::cout << "\tHint: Press ENTER after typing a control character.\n" << std::endl;
            std::cout << "\t" << options << " ";

        } else {

            userInput = toupper(userInput);

            if (userInput == 'W' || userInput == 'A' || userInput == 'S' || userInput == 'D' || userInput == 'I') {
                return userInput;
            }

            std::cout << "\tInvalid character selection. Please try again." << std::endl;
            std::cout << "\tHint: Press ENTER after typing a control character.\n" << std::endl;
            std::cout << "\t" << options << " ";

        }

        //This clears cin and instructs the computer to ignore any remaining characters in the buffer.
        //This ensures that leftover characters don't impact performance when iterating.

        std::cin.clear();
        std::cin.ignore(1000000, '\n');
    }
}

