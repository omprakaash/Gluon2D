//
// Created by Om Prakaash on 2019-07-21.
//

#ifndef GLUON2D_ASSETMANAGER_H
#define GLUON2D_ASSETMANAGER_H

#include <map>
#include <SDL_render.h>


namespace Gluon2D {

class AssetManager {

private:

     /** A Map of texture names and texture data */
     std::map<std::string, SDL_Texture*> m_textures;

public:

    AssetManager();

    /** Saves texture data in texture map(m_textures) */
    void saveTexture( const char *file, SDL_Texture* texture );

    SDL_Texture* getTexture(const char* texture_name);

};


}


#endif //GLUON2D_ASSETMANAGER_H
