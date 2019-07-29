//
// Created by Om Prakaash on 2019-07-21.
//

#ifndef GLUON2D_RENDERER_H
#define GLUON2D_RENDERER_H


#include <SDL_render.h>
#include "AssetManager.h"
#include "GameObject.h"

namespace  Gluon2D {

class Renderer {
private:
    AssetManager* m_asset_manager;
    SDL_Renderer* m_renderer;
    std::vector<GameObject*> m_renderables;

public:
    Renderer(SDL_Window* window, AssetManager* asset_manager);
    void render(SDL_Texture *texture);
    void loadTexture(const char* file);

    // TODO
    void addRenderable(GameObject* renderable);
    const std::vector<GameObject *> &getRenderables() const;
    void clear();
    void present();

};

}

#endif //GLUON2D_RENDERER_H
