//
// Created by Om Prakaash on 2019-08-05.
//

#ifndef GLUON2D_PHYSICSSYSTEM_H
#define GLUON2D_PHYSICSSYSTEM_H


#include "../GameObject.h"
#include "System.h"

namespace Gluon2D {

struct Body{
    int x;
    int y;
    int width;
    int height;
};

class PhysicsSystem: System {

private:
    static std::vector<GameObject*> m_phyObjects;

public:
    void update() override;
    static void addObject(GameObject* gameObject);
};

}


#endif //GLUON2D_PHYSICSSYSTEM_H
