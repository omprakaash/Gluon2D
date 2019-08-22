//
// Created by Om Prakaash on 2019-07-24.
//

#include <iostream>
#include "RenderComponent.h"

Gluon2D::RenderComponent::RenderComponent( GameObject* parent, RendererSystem* renderer, SDL_Texture* texture ):
            Component(parent), m_renderer(renderer), m_texture(texture) {
    makeParentRenderable();
}

SDL_Texture* Gluon2D::RenderComponent::getTexture() {
    return m_texture;
}

void Gluon2D::RenderComponent::makeParentRenderable() {
    m_renderer->addRenderable(m_parent);
}

