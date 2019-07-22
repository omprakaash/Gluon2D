//
// Created by Om Prakaash on 2019-07-19.
//

#include <iostream>
#include "Window.h"


Gluon2D::Window::Window(int height, int width, const char *title): m_height(height), m_width(width), m_title(title) {
    m_window = SDL_CreateWindow(
            m_title,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            m_width, m_height,
            SDL_WINDOW_SHOWN);

    if(m_window == NULL){
        std::cout << "SDL2 Window could not be be created !!" << std::endl;
    }
}

SDL_Window* Gluon2D::Window::getSDLWindow() {
    return m_window;
}

Gluon2D::Window::~Window() {
    SDL_DestroyWindow(m_window);
}


