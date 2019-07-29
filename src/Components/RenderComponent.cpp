//
// Created by Om Prakaash on 2019-07-24.
//

#include <iostream>
#include "RenderComponent.h"

Gluon2D::RenderComponent::RenderComponent( Renderer* renderer, SDL_Texture* texture ): m_renderer(renderer), m_texture(texture) {}

SDL_Texture* Gluon2D::RenderComponent::getTexture() {
    return m_texture;
}

void Gluon2D::RenderComponent::makeParentRenderable() {
    m_renderer->addRenderable(m_parent);
}

void Gluon2D::RenderComponent::update() {
    std::cout<< "Hello" ;
}