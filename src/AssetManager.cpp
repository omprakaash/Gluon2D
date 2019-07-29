//
// Created by Om Prakaash on 2019-07-21.
//

#include <SDL_image.h>
#include <iostream>

#include "AssetManager.h"

Gluon2D::AssetManager::AssetManager(){
    std::map<std::string, SDL_Texture*> m_textures;
}

void Gluon2D::AssetManager::saveTexture(const char *t_file, SDL_Texture* texture) {
    std::string s = std::string(t_file);
    std::string texture_name = s.substr(s.find_last_of("/\\") + 1);;
    m_textures.insert( std::pair<std::string, SDL_Texture*> ( texture_name , texture ) );
}

SDL_Texture* Gluon2D::AssetManager::getTexture(const char * texture_name) {
    return m_textures[texture_name];
}