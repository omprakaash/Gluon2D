//
// Created by Om Prakaash on 2019-08-01.
//

#include "PhysicsComponent.h"
#include "../Systems/PhysicsSystem.h"

namespace Gluon2D{

PhysicsComponent::PhysicsComponent(GameObject *parent): Component(parent) {
    PhysicsSystem::addObject(parent);
}

}