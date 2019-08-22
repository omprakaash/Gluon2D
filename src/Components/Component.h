//
// Created by Om Prakaash on 2019-07-22.
//

#ifndef GLUON2D_COMPONENT_H
#define GLUON2D_COMPONENT_H

#include "../GameObject.h"

namespace Gluon2D {

class GameObject;

class Component {

public:
    GameObject* m_parent;
    Component(GameObject* parent);
    void set_parent(GameObject* parent);

};

}

#endif //GLUON2D_COMPONENT_H
