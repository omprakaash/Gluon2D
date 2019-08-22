//
// Created by Om Prakaash on 2019-07-31.
//

#ifndef GLUON2D_VECTOR_H
#define GLUON2D_VECTOR_H

namespace Gluon2D {

class Vector {

public:
    float X;

    float Y;

public:

    Vector(): X(0), Y(0){};

    Vector(int x , int y): X(x), Y(y){};

    float length();

    void scale(int scale_factor);

    void translate(int x, int y) ;

    Vector dot ( Vector v);

    float cross (Vector v);

    static Vector normalize(Vector v);

};

}
#endif //GLUON2D_VECTOR_H
