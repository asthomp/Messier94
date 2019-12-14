/*********************************************************************
** Program name: Messier94
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Ship class is derived from the Space base class. It
** represents the UFO crash site on the game board. The class has two
** functions that override Space's pure virtual functions: action
** and event. This header file has include guards to prevent duplication.
*********************************************************************/

#ifndef SHIP_HPP
#define SHIP_HPP

#include "Space.hpp"

class Ship : public Space {

private:

public:

    Ship();

    void event() override;

    void action() override;

};

#endif //SHIP_HPP
