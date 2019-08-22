//
// Created by Om Prakaash on 2019-08-06.
//

#ifndef GLUON2D_PLAYERPHYSICSCOMPONENT_H
#define GLUON2D_PLAYERPHYSICSCOMPONENT_H

#include "PhysicsComponent.h"

namespace Gluon2D{

class PlayerPhysicsComponent : public PhysicsComponent {

public:

    PlayerPhysicsComponent(GameObject* parent): PhysicsComponent(parent){};
    void onCollision(GameObject* other) override;

};

}

#endif //GLUON2D_PLAYERPHYSICSCOMPONENT_H
