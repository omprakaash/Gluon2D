//
// Created by Om Prakaash on 2019-08-14.
//

#ifndef GLUON2D_PLAYERLOGICCOMPONENT_H
#define GLUON2D_PLAYERLOGICCOMPONENT_H

#include "LogicComponent.hpp"

namespace Gluon2D {

class PlayerLogicComponent : public LogicComponent {


public:
    PlayerLogicComponent(GameObject* parent);
    void update() override;


};

}


#endif //GLUON2D_PLAYERLOGICCOMPONENT_H
