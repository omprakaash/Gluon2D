//
// Created by Om Prakaash on 2019-07-19.
//


#include <iostream>
#include "Game.h"

Gluon2D::Game::Game() {}

void Gluon2D::Game::start() {
    int sdl_init = SDL_Init(SDL_INIT_EVERYTHING);

    if(sdl_init < 0){
        std::cerr << "Error initializing SDL" << std::endl;
    }
    else{
       m_window = new Window(800, 600, "First Game");
       m_asset_manager = new AssetManager();
       m_renderer = new Renderer(m_window->getSDLWindow(), m_asset_manager);
       m_is_running = true;
    }
}

void Gluon2D::Game::update() {
    SDL_Event event;

    while(m_is_running){
        while(SDL_PollEvent( &event )){
            if(event.type == SDL_MOUSEBUTTONDOWN){
                std::cout << "Mouse Button Pressed" << std::endl;
            }
            else if(event.type == SDL_QUIT){
                m_is_running = false;
                std::cout << "QUIT  !!!" << std::endl;
            }
        }
    }
}

void Gluon2D::Game::render() {

}