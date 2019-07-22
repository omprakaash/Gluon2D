//
// Created by Om Prakaash on 2019-07-21.
//

#ifndef GLUON2D_RENDERER_H
#define GLUON2D_RENDERER_H


#include <SDL_render.h>
#include "AssetManager.h"

namespace  Gluon2D {

class Renderer {
private:
    AssetManager* m_asset_manager;
    SDL_Renderer* m_renderer;
public:
    Renderer(SDL_Window* window, AssetManager* asset_manager);
    void render(SDL_Texture *texture);
    void loadTexture(const char* file);

    // TODO
    void addRenderable();
};

}

#endif //GLUON2D_RENDERER_H
