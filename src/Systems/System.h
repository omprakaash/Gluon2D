//
// Created by Om Prakaash on 2019-08-07.
//

#ifndef GLUON2D_SYSTEM_H
#define GLUON2D_SYSTEM_H

#include "../GameObject.h"

namespace Gluon2D {

class GameObject;

class System {

public:
    virtual void update() = 0;
};

}
#endif //GLUON2D_SYSTEM_H
