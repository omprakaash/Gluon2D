//
// Created by Om Prakaash on 2019-07-29.
//

#include <iostream>
#include "Input.h"

std::set<SDL_Keycode> Gluon2D::InputManager::m_active_keys;

void Gluon2D::InputManager::update(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        std::cout << "Scaning for Input !!" << std::endl;
        if(event.type == SDL_KEYDOWN){
            std::cout << "Input present " << std::endl;
            m_active_keys.insert(event.key.keysym.sym);
        }
        else if(event.type == SDL_KEYUP){
            m_active_keys.erase(event.key.keysym.sym);
        }
    }
}

bool Gluon2D::InputManager::isKeyPressed(char c) {
    return m_active_keys.find(c) != m_active_keys.end();
}

