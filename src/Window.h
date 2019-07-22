//
// Created by Om Prakaash on 2019-07-19.
//

#ifndef GLUON2D_WINDOW_H
#define GLUON2D_WINDOW_H

#include <SDL.h>

namespace Gluon2D {

class Window {
private:
    int m_height;
    int m_width;
    const char* m_title;
    SDL_Window* m_window;
public:
    Window(int height, int width, const char* title);
    SDL_Window* getSDLWindow();
    ~Window();
};

}
#endif //GLUON2D_WINDOW_H

