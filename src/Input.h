//
// Created by Om Prakaash on 2019-07-29.
//

#ifndef GLUON2D_INPUT_H
#define GLUON2D_INPUT_H

#include <SDL_events.h>
#include <set>

namespace Gluon2D {
class InputManager {

    static std::set<SDL_Keycode> m_active_keys;


public:
    InputManager(){};
    void update();
    static bool isKeyPressed(char c);

};
}

#endif //GLUON2D_INPUT_H
