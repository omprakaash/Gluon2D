//
// Created by Om Prakaash on 2019-07-24.
//

#ifndef GLUON2D_RENDERCOMPONENT_H
#define GLUON2D_RENDERCOMPONENT_H


#include "Component.h"
#include "../Systems/RendererSystem.h"

namespace Gluon2D {

class RenderComponent : public Component {
public:

    RenderComponent(GameObject* parent, RendererSystem* renderer, SDL_Texture* texture );
    SDL_Texture* getTexture();
    void makeParentRenderable();

private:
    RendererSystem *m_renderer;
    SDL_Texture* m_texture;

};

}

#endif //GLUON2D_RENDERCOMPONENT_H
