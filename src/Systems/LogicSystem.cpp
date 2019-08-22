//
// Created by Om Prakaash on 2019-08-14.
//

#include <iostream>
#include "LogicSystem.h"
#include "../GameObject.h"
#include "../Components/LogicComponent.hpp"

namespace Gluon2D{

std::vector<GameObject*> LogicSystem::m_logicObjects;

void LogicSystem::update() {
    for(GameObject* object : m_logicObjects){
        if( ! object->getComponent<LogicComponent>() ){
            std::cout << "Gameobject does not have logic component";
        }
        else{
            object->getComponent<LogicComponent>()->update();
        }
    }
}

void LogicSystem::addObject(Gluon2D::GameObject *object) {
    m_logicObjects.push_back(object);
}

}