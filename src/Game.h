//
// Created by Om Prakaash on 2019-07-19.
//

#ifndef GLUON2D_GAME_H
#define GLUON2D_GAME_H


#include <vector>

#include "Window.h"
#include "AssetManager.h"
#include "Systems/RendererSystem.h"
#include "Systems/InputSystem.h"
#include "ObjectManager.h"
#include "Systems/LogicSystem.h"
#include "Systems/PhysicsSystem.h"

namespace Gluon2D {

class Game {

private:
    Window* m_window;
    RendererSystem* m_renderer;
    AssetManager m_assetManager; // Should asset manager be in the heap?
    ObjectManager m_objectManager;
    LogicSystem logicSystem;
    PhysicsSystem physicsSystem;

    bool m_isRunning;

    void update();

public:

    InputManager* input;

    Game();
    ~Game();
    void start();

    void render();

    void addGameObject(GameObject* gameObject);

    void findGameObject(const char* tag);




};

}
#endif //GLUON2D_GAME_H
