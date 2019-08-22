//
// Created by Om Prakaash on 2019-08-14.
//

#ifndef GLUON2D_LOGICCOMPONENT_HPP
#define GLUON2D_LOGICCOMPONENT_HPP


#include "Component.h"
#include "../Systems/LogicSystem.h"

namespace Gluon2D {

class LogicComponent: public Component {

public:
    LogicComponent(GameObject* parent):Component(parent){
        LogicSystem::addObject(parent);
    };
    virtual void update() = 0;
};

}


#endif //GLUON2D_LOGICCOMPONENT_HPP
