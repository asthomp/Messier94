/*********************************************************************
** Program name: Messier94
** Author: Aaron Thompson
** Date: 12/10/2019
** Description: The Artifact class is derived from the Space base class. It
** represents an alien artifact on the game board. The class has two
** functions that override Space's pure virtual functions: action
** and event. This header file has include guards to prevent duplication.
*********************************************************************/

#ifndef ARTIFACT_HPP
#define ARTIFACT_HPP

#include "Space.hpp"

class Artifact : public Space {

private:

public:

    Artifact();

    void event() override;

    void action() override;

};

#endif //ARTIFACT_HPP
