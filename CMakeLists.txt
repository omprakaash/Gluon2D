cmake_minimum_required(VERSION 3.14)
project(Gluon2D)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(/usr/local/include/SDL2 -D_THREAD_SAFE)

add_executable(${PROJECT_NAME} main.cpp src/Game.cpp src/Game.h src/Window.cpp src/Window.h src/AssetManager.cpp src/AssetManager.h src/Renderer.cpp src/Renderer.h src/GameObject.cpp src/GameObject.h)
target_link_libraries(${PROJECT_NAME} /usr/local/lib -lSDL2_image -lSDL2)