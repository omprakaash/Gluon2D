//
// Created by Om Prakaash on 2019-07-22.
//

#ifndef GLUON2D_COMPONENT_H
#define GLUON2D_COMPONENT_H


namespace Gluon2D {

class GameObject;

class Component {


public:
    Component(){}

    void set_parent(GameObject* parent);
    virtual void update() = 0;
    GameObject* m_parent;

};

}

#endif //GLUON2D_COMPONENT_H
