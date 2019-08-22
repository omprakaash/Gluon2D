//
// Created by Om Prakaash on 2019-08-01.
//

#ifndef GLUON2D_PHYSICSCOMPONENT_H
#define GLUON2D_PHYSICSCOMPONENT_H

#include "Component.h"

namespace Gluon2D {

class PhysicsComponent : public Component {

public:

    PhysicsComponent(GameObject* parent);
    virtual void onCollision(GameObject* other) = 0;

};

}
#endif //GLUON2D_PHYSICSCOMPONENT_H
