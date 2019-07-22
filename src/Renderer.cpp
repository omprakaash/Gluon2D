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
}

void Gluon2D::Renderer::loadTexture(const char *file) {
    SDL_Surface* load_surface = IMG_Load(file);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, load_surface);
    if( ! texture){
        std::cerr << "Error loading texture from surface " << std::endl;
    }
    else {
        m_asset_manager->saveTexture(file, texture);
    }
}

void Gluon2D::Renderer::render(SDL_Texture *texture) {
    SDL_RenderCopy(m_renderer, texture, NULL, NULL);
}
