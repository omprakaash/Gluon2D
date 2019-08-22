//
// Created by Om Prakaash on 2019-08-14.
//

#include <iostream>
#include "../Systems/InputSystem.h"
#include "PlayerLogicComponent.h"
#include "TransformComponent.h"

namespace Gluon2D{

PlayerLogicComponent::PlayerLogicComponent(Gluon2D::GameObject *parent): LogicComponent(parent) {}

void PlayerLogicComponent::update() {
    std::cout << "Updating" << std::endl;
    auto playerTransform = m_parent->getComponent<TransformComponent>();
    if(InputManager::isKeyPressed('d')){
        playerTransform->translateX(1);
    }
    else if(InputManager::isKeyPressed('a')){
        playerTransform->translateX(-1);
    }

}

}