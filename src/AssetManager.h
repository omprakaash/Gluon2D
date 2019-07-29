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
         std::map<std::string, SDL_Texture*> m_textures;

    public:
        AssetManager();
        void saveTexture( const char *file, SDL_Texture* texture );
        SDL_Texture* getTexture(const char* texture_name);
    };


}


#endif //GLUON2D_ASSETMANAGER_H
