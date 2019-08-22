#include <iostream>

#include "src/Game.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    Gluon2D::Game game = Gluon2D::Game();
    game.start();
    return 0;
}

