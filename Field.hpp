/*********************************************************************
** Program name: Messier94
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Field derived class inherits from the Space class. It
** represents a space on the game board, specifically a corn field. The
** class has two unique functions: event and action. These functions handle
** user interactions that can only take place in a corn field. The header
** file contains include guards to prevent duplication.
*********************************************************************/

#ifndef FIELD_HPP
#define FIELD_HPP

#include "Space.hpp"

class Field : public Space {

private:

public:

    Field();

    void event() override;

    void action() override;

    void search(int chance);

    void inspect(int chance);

    void dig(int chance);

};


#endif //FIELD_HPP
