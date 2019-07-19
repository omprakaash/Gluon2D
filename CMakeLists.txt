cmake_minimum_required(VERSION 3.14)
project(Gluon2D)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(/usr/local/include/SDL2 -D_THREAD_SAFE)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} /usr/local/lib -lSDL2)