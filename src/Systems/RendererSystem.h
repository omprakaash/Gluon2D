//
// Created by Om Prakaash on 2019-07-21.
//

#ifndef GLUON2D_RENDERERSYSTEM_H
#define GLUON2D_RENDERERSYSTEM_H


#include <SDL_render.h>
#include "../AssetManager.h"
#include "../GameObject.h"
#include "System.h"

namespace  Gluon2D {

class RendererSystem: System {
private:
    AssetManager* m_assetManager;
    SDL_Renderer* m_renderer;
    std::vector<GameObject*> m_renderables;

public:
    RendererSystem(SDL_Window* window, AssetManager* asset_manager);
    void render(SDL_Texture *texture, int x, int y, int width, int height, float angle);
    void loadTexture(const char* file);

    // TODO
    void addRenderable(GameObject* renderable);
    const std::vector<GameObject*> &getRenderables() const;
    void clear();
    void present();
    void update() override ;
    ~RendererSystem();

};

}

#endif //GLUON2D_RENDERERSYSTEM_H
