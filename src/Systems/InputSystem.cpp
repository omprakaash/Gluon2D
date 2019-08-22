//
// Created by Om Prakaash on 2019-07-29.
//

#include <iostream>
#include "InputSystem.h"

std::set<SDL_Keycode> Gluon2D::InputManager::m_activeKeys;

void Gluon2D::InputManager::update() {
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_KEYDOWN){
            m_activeKeys.insert(event.key.keysym.sym);
        }
        else if(event.type == SDL_KEYUP){
            m_activeKeys.erase(event.key.keysym.sym);
        }
    }
}

bool Gluon2D::InputManager::isKeyPressed(char c) {
    return m_activeKeys.find(c) != m_activeKeys.end();
}

