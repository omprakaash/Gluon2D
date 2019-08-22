cmake_minimum_required(VERSION 3.14)
project(Gluon2D)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(/usr/local/include/SDL2 -D_THREAD_SAFE)

add_executable(${PROJECT_NAME} main.cpp src/Game.cpp src/Game.h src/Window.cpp src/Window.h src/AssetManager.cpp src/AssetManager.h src/Systems/RendererSystem.cpp src/Systems/RendererSystem.h src/GameObject.cpp src/GameObject.h src/Components/Component.cpp src/Components/Component.h src/Components/RenderComponent.cpp src/Components/RenderComponent.h src/Components/TransformComponent.cpp src/Components/TransformComponent.h src/Math/Transform.cpp src/Math/Transform.h src/Systems/InputSystem.cpp src/Systems/InputSystem.h src/ObjectManager.cpp src/ObjectManager.h src/Math/Vector.cpp src/Math/Vector.h src/Components/PhysicsComponent.cpp src/Components/PhysicsComponent.h src/Systems/PhysicsSystem.cpp src/Systems/PhysicsSystem.h src/Components/PlayerPhysicsComponent.cpp src/Components/PlayerPhysicsComponent.h src/Systems/System.cpp src/Systems/System.h src/Systems/LogicSystem.cpp src/Systems/LogicSystem.h src/Components/LogicComponent.hpp src/Components/PlayerLogicComponent.cpp src/Components/PlayerLogicComponent.h)
target_link_libraries(${PROJECT_NAME} /usr/local/lib -lSDL2_image -lSDL2 -lpng)