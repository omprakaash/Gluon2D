//
// Created by Om Prakaash on 2019-07-19.
//

#ifndef GLUON2D_GAME_H
#define GLUON2D_GAME_H


#include <vector>

#include "Window.h"
#include "AssetManager.h"
#include "Renderer.h"
#include "Input.h"

namespace Gluon2D {

class Game {

private:
    Window* m_window;
    Renderer* m_renderer;
    AssetManager* m_asset_manager; // Should asset manager be in the heap?
    std::vector<GameObject*> m_game_objects;
    bool m_is_running;

public:

    InputManager* input;

    Game();
    void start();
    void update();
    void render();

    void addGameObject(GameObject* gameObject);
};

}
#endif //GLUON2D_GAME_H
