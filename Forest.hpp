/*********************************************************************
** Program name: Messier94
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Forest class is derived from the Space base class. It
** represents a forest on the game board. The class has two functions
** that override Space's pure virtual functions: action and event.
** In addition, Forest objects have three actions specific only to
** them that allow the user to interact with the space. This header
** file has include guards to prevent duplication.
*********************************************************************/

#ifndef FOREST_HPP
#define FOREST_HPP

#include "Space.hpp"

class Forest : public Space {

private:

public:

    Forest();

    void event() override;

    void action() override;

    void search(int chance);

    void lights(int chance);

    void hide(int chance);

};

#endif //FOREST_HPP
