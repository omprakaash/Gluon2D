//
// Created by Om Prakaash on 2019-08-06.
//

#include <iostream>
#include "PlayerPhysicsComponent.h"

namespace Gluon2D{

void PlayerPhysicsComponent::onCollision(Gluon2D::GameObject *other) {
    std::cout << "HEY I COLLIDED WITH SOMETHING" << std::endl;
}




}