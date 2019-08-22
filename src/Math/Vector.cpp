//
// Created by Om Prakaash on 2019-07-31.
//

#include <cmath>
#include "Vector.h"

namespace Gluon2D{

float Vector::length() {
    return sqrt(pow(X,2) + pow(Y,2));
}

void Vector::scale(int scale){
    X *= scale;
    Y *= scale;
}

void Vector::translate(int x, int y) {
    X += x;
    Y += y;
}


}