//
// Created by Om Prakaash on 2019-07-19.
//

#include <iostream>
#include <SDL_image.h>
#include "Game.h"
#include "Components/RenderComponent.h"
#include "Components/TransformComponent.h"
#include "Components/PlayerPhysicsComponent.h"
#include "Components/PlayerLogicComponent.h"

Gluon2D::Game::Game() {
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
        m_assetManager = AssetManager();
        m_renderer = new RendererSystem(m_window->getSDLWindow(), &m_assetManager);
        m_objectManager = ObjectManager();
        input = new InputManager() ;
        physicsSystem = PhysicsSystem();
        logicSystem   = LogicSystem();

        if( ! m_renderer){
            std::cerr << "RendererSystem could not be created " << std::endl;
        }

        std::vector<GameObject*> m_game_objects;
        m_isRunning = true;
    }


    /*
     * Creating all game objects in game. Need to move this into a load_game function. Or not maybe the user
     * can create game objects on the fly after game initializes.
     */
    GameObject* player = new GameObject();
    m_renderer->loadTexture("/Users/om/CLionProjects/Gluon2D/cat.jpg");
    player->addComponent<TransformComponent>(10,10,20,30);
    player->addComponent<RenderComponent>( m_renderer, m_assetManager.getTexture("cat"));
    player->addComponent<PlayerPhysicsComponent>();
    player->addComponent<PlayerLogicComponent>();

    TransformComponent* transform = player->getComponent<TransformComponent>();

    this->addGameObject(player);

}

void Gluon2D::Game::start() {
    update();
}

void Gluon2D::Game::update() {
    SDL_Event event;

    while(m_isRunning){

        input->update();
        logicSystem.update();
        physicsSystem.update();
        m_renderer->update();

        render();

    }
}

void Gluon2D::Game::addGameObject(Gluon2D::GameObject *gameObject) {
    m_objectManager.addGameObject(gameObject);
}

void Gluon2D::Game::render() {
    m_renderer->clear();
    for(auto& texture: m_renderer->getRenderables()){
        TransformComponent* transform = static_cast<TransformComponent*>(texture->getComponent<TransformComponent>());
        m_renderer->render(
                static_cast<RenderComponent*>(texture->getComponent<RenderComponent>())->getTexture(),
                transform->getXPos(),
                transform->getYPos(),
                transform->getHeight(),
                transform->getWidth(),
                transform->getAngle()
                );
    }
    m_renderer->present();

}

Gluon2D::Game::~Game(){
    delete(m_window);
    delete(m_renderer);
}