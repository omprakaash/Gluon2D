//
// Created by Om Prakaash on 2019-07-29.
//

#ifndef GLUON2D_TRANSFORMCOMPONENT_H
#define GLUON2D_TRANSFORMCOMPONENT_H

#include "Component.h"
#include "../Math/Transform.h"
#include "../Math/Vector.h"

namespace Gluon2D {

class TransformComponent: public Component {
public:

    TransformComponent(GameObject* parent, int x, int y, int width, int height);
    TransformComponent(GameObject* parent, int x, int y, int width, int height, int rot);

    Vector getPos();
    int getXPos();
    int getYPos();
    int getWidth();
    int getHeight();

    void translate(int x, int y);
    void translateX(int x);
    void translateY(int y);

    void rotate(float angle);



    float getAngle();

private:
    Vector m_pos;
    int m_width;
    int m_height;
    float m_rot;
};

}

#endif //GLUON2D_TRANSFORMCOMPONENT_H
