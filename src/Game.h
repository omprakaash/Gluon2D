//
// Created by Om Prakaash on 2019-07-19.
//

#ifndef GLUON2D_GAME_H
#define GLUON2D_GAME_H


#include <vector>

#include "Window.h"
#include "AssetManager.h"
#include "Renderer.h"

namespace Gluon2D {

class Game {

private:
    Window* m_window;
    Renderer* m_renderer;
    AssetManager* m_asset_manager; // Should asset manager be in the heap?
    bool m_is_running;
public:
    Game();
    void start();
    void update();
    void render();
};

}
#endif //GLUON2D_GAME_H
