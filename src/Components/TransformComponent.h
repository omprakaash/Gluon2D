//
// Created by Om Prakaash on 2019-07-29.
//

#ifndef GLUON2D_TRANSFORMCOMPONENT_H
#define GLUON2D_TRANSFORMCOMPONENT_H

#include "Component.h"
#include "../Math/Transform.h"

namespace Gluon2D {

class TransformComponent: public Component {
public:
    int X;
    int Y;
    int W;
    int H;
    TransformComponent(int x, int y, int w, int h): X(x), Y(y), W(w), H(h){}

    virtual void update() override;
    virtual const char* name() override;
};

}

#endif //GLUON2D_TRANSFORMCOMPONENT_H
