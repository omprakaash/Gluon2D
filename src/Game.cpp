//
// Created by Om Prakaash on 2019-07-19.
//

#include <iostream>
#include <SDL_image.h>
#include "Game.h"
#include "Components/RenderComponent.h"
#include "Components/TransformComponent.h"

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
       input = new InputManager() ;

       if( ! m_renderer){
           std::cerr << "Renderer could not be created " << std::endl;
       }

       std::vector<GameObject*> m_game_objects;
       m_is_running = true;
    }


    /*
     * Creating all game objects in game. Need to move this into a load_game function. Or not maybe the user
     * can create game objects on the fly after game initializes.
     */
    GameObject* player = new GameObject();
    m_renderer->loadTexture("/Users/om/CLionProjects/Gluon2D/cat.jpg");
    RenderComponent* playerRenderer = new RenderComponent(m_renderer, m_asset_manager->getTexture("cat"));
    TransformComponent* playerTransform = new TransformComponent(10,10,40,40);

    player->addComponent( dynamic_cast<Component*>(playerRenderer) );
    player->addComponent( dynamic_cast<Component*>(playerTransform) );

    m_game_objects.push_back(player);

}

void Gluon2D::Game::update() {
    SDL_Event event;

    while(m_is_running){

        input->update();
        for(auto& object : m_game_objects){
            object->update();
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
        TransformComponent* transform = static_cast<TransformComponent*>(texture->getComponent<TransformComponent>());
        m_renderer->render(
                static_cast<RenderComponent*>(texture->getComponent<RenderComponent>())->getTexture(),
                transform->X,
                transform->Y,
                transform->H,
                transform->W
                );
    }
    m_renderer->present();

}