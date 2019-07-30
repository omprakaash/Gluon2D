//
// Created by Om Prakaash on 2019-07-22.
//

#ifndef GLUON2D_COMPONENT_H
#define GLUON2D_COMPONENT_H


namespace Gluon2D {

class GameObject;

class Component {


public:
    GameObject* m_parent;

    Component(){}
    void set_parent(GameObject* parent);
    virtual void update() = 0;
    virtual const char* name() = 0;

};

}

#endif //GLUON2D_COMPONENT_H
