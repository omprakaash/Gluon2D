//
// Created by Om Prakaash on 2019-07-21.
//

#include <iostream>
#include <SDL_image.h>
#include "Renderer.h"
#include "AssetManager.h"

Gluon2D::Renderer::Renderer(SDL_Window *window, AssetManager* assetManager) {
    m_asset_manager = assetManager;
    m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if( ! m_renderer){
        std::cerr << "Error creating SDL renderer" << std::endl;
    }
    std::vector<GameObject*> m_renderables;
}

void Gluon2D::Renderer::loadTexture(const char *file) {
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
        m_asset_manager->saveTexture(file, texture);
    }
    SDL_FreeSurface(load_surface);
}

void Gluon2D::Renderer::render(SDL_Texture *texture, int x, int y, int width, int height) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.h = height;
    rect.w = width;
    SDL_RenderCopy(m_renderer, texture, NULL, &rect);
}

void Gluon2D::Renderer::addRenderable(GameObject* renderable) {
    m_renderables.push_back(renderable);
}

const std::vector<Gluon2D::GameObject *> &Gluon2D::Renderer::getRenderables() const {
    return m_renderables;
}

void Gluon2D::Renderer::clear() {
    SDL_RenderClear(m_renderer);
}

void Gluon2D::Renderer::present(){
    SDL_RenderPresent(m_renderer);
}


