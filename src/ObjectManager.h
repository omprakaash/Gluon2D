//
// Created by Om Prakaash on 2019-07-30.
//

#ifndef GLUON2D_OBJECTMANAGER_H
#define GLUON2D_OBJECTMANAGER_H

#include <map>
#include "GameObject.h"

namespace Gluon2D {

class ObjectManager {

private:

    std::vector<GameObject*> m_gameObjects;
    std::map<const char*, GameObject*> m_tagMap;
    int m_nextId;

public:

    ObjectManager();
    void addGameObject(GameObject*);
    GameObject* findObjectWithTag(const char*);
    std::vector<GameObject*> getGameObjects();


};

}


#endif //GLUON2D_OBJECTMANAGER_H
