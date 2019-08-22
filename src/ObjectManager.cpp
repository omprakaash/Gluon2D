//
// Created by Om Prakaash on 2019-07-30.
//

#include "ObjectManager.h"

namespace Gluon2D {

ObjectManager::ObjectManager() {
    std::vector<GameObject*> m_gameObjects;
}

void ObjectManager::addGameObject(GameObject* obj){
   m_gameObjects.push_back(obj);
}

std::vector<GameObject*> ObjectManager::getGameObjects() {
    return m_gameObjects;
}


}