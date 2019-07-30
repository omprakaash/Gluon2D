//
// Created by Om Prakaash on 2019-07-24.
//

#ifndef GLUON2D_RENDERCOMPONENT_H
#define GLUON2D_RENDERCOMPONENT_H


#include "Component.h"
#include "../Renderer.h"

namespace Gluon2D {

class RenderComponent : public Component {
public:
    RenderComponent(Renderer* renderer, SDL_Texture* texture);
    SDL_Texture* getTexture();

    void makeParentRenderable();

private:
    Renderer *m_renderer;
    virtual void update() override ;
    virtual const char* name() override;
    SDL_Texture* m_texture;

};

}

#endif //GLUON2D_RENDERCOMPONENT_H
