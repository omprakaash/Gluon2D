//
// Created by Om Prakaash on 2019-07-19.
//

#include <iostream>
#include <SDL_image.h>
#include "Game.h"
#include "Components/RenderComponent.h"

Gluon2D::Game::Game() {}

void Gluon2D::Game::start() {
    int sdl_init = SDL_Init(SDL_INIT_EVERYTHING);
    int img_init = IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    if(!img_init){
        std::cout << "Could not initilize image subsystem" << std::endl;
    }

    if(sdl_init < 0){
        std::cerr << "Error initializing SDL" << std::endl;
    }
    else{
       m_window = new Window(1300, 1300, "First Game");
       m_asset_manager = new AssetManager();
       m_renderer = new Renderer(m_window->getSDLWindow(), m_asset_manager);

       if( ! m_renderer){
           std::cerr << "Renderer could not be created " << std::endl;
       }

       std::vector<GameObject*> m_game_objects;
       m_is_running = true;
    }

    GameObject* player = new GameObject();
    m_renderer->loadTexture("/Users/om/CLionProjects/Gluon2D/cat.jpg");
    RenderComponent* playerRenderer = new RenderComponent(m_renderer, m_asset_manager->getTexture("cat.jpg"));
    player->addComponent( dynamic_cast<Component*>(playerRenderer) );

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


       render();

    }
}

void Gluon2D::Game::addGameObject(Gluon2D::GameObject *gameObject) {
    m_game_objects.push_back(gameObject);
}

void Gluon2D::Game::render() {
    m_renderer->clear();
    for(auto& texture: m_renderer->getRenderables()){
        m_renderer->render(static_cast<RenderComponent*>(texture->getComponent<RenderComponent>())->getTexture());
    }
    m_renderer->present();

    SDL_Delay(200);

}