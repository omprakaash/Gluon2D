//
// Created by Om Prakaash on 2019-07-21.
//

#include <iostream>
#include <SDL_image.h>
#include "RendererSystem.h"
#include "../AssetManager.h"
#include "../Components/TransformComponent.h"
#include "../Components/RenderComponent.h"

Gluon2D::RendererSystem::RendererSystem(SDL_Window *window, AssetManager* assetManager) {
    m_assetManager = assetManager;
    m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if( ! m_renderer){
        std::cerr << "Error creating SDL renderer" << std::endl;
    }
    std::vector<GameObject*> m_renderables;
}

void Gluon2D::RendererSystem::loadTexture(const char *file) {
    SDL_Surface* load_surface = IMG_Load(file);
    if( !load_surface ){
        std::cerr << "Error loading image onto surface" << std::endl;
        std::cout << IMG_GetError();
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, load_surface);
    if( ! texture){
        std::cerr << "Error loading texture from surface " << std::endl;
    }
    else {
        m_assetManager->saveTexture(file, texture);
    }
    SDL_FreeSurface(load_surface);
}

void Gluon2D::RendererSystem::render(SDL_Texture *texture, int x, int y, int width, int height, float angle) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.h = height;
    rect.w = width;
    SDL_RenderCopyEx(m_renderer, texture, NULL, &rect, angle, NULL, SDL_FLIP_NONE);
}

void Gluon2D::RendererSystem::update() {
    for(GameObject* obj : m_renderables){
        TransformComponent* transform = static_cast<TransformComponent*>(obj->getComponent<TransformComponent>());
        RenderComponent* renderComp   = static_cast<RenderComponent*>(obj->getComponent<RenderComponent>());
        render(renderComp->getTexture(), transform->getXPos(), transform->getYPos(), transform->getWidth(),
                transform->getHeight(), transform->getAngle());
    }
}


void Gluon2D::RendererSystem::addRenderable(GameObject* renderable) {
    m_renderables.push_back(renderable);
}

const std::vector<Gluon2D::GameObject *> &Gluon2D::RendererSystem::getRenderables() const {
    return m_renderables;
}

void Gluon2D::RendererSystem::clear() {
    SDL_RenderClear(m_renderer);
}

void Gluon2D::RendererSystem::present(){
    SDL_RenderPresent(m_renderer);
}

Gluon2D::RendererSystem::~RendererSystem() {
    SDL_DestroyRenderer(m_renderer);
}


