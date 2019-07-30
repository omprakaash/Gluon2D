//
// Created by Om Prakaash on 2019-07-29.
//

#include <iostream>
#include "TransformComponent.h"
#include "../Game.h"

void Gluon2D::TransformComponent::update() {
    if(InputManager::isKeyPressed('a')){
        X -= 10;
    }
    else if(InputManager::isKeyPressed('d')){
        X += 10;
    }
}

const char* Gluon2D::TransformComponent::name() {
    return "TransformComponent";
}