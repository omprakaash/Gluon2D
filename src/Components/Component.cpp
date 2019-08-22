// Created by Om Prakaash on 2019-07-22.
//

#include "Component.h"

namespace Gluon2D {

Component::Component(Gluon2D::GameObject *parent): m_parent(parent) {}

void Component::set_parent(Gluon2D::GameObject *parent) {
    m_parent = parent;
}

}