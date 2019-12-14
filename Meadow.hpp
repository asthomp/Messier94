/*********************************************************************
** Program name: Messier94
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Meadow class is derived from the Space base class. It
** represents a meadow on the game board. The class has two functions
** that override Space's pure virtual functions: action and event.
** In addition, Meadow objects have three actions specific only to
** them that allow the user to interact with the space. This header
** file has include guards to prevent duplication.
*********************************************************************/

#ifndef MEADOW_HPP
#define MEADOW_HPP

#include "Space.hpp"

class Meadow : public Space {

private:

public:

    Meadow();

    void event() override;

    void action() override;

    void search(int chance);

    void grass(int chance);

    void dig(int chance);

};

#endif //MEADOW_HPP
