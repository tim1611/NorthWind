#ifndef GAMEASSETS_H
#define GAMEASSETS_H

#include "raylib.h"
#include <map>
#include <string>

namespace World
{
    class GameAssets
    {
    public:
        static GameAssets& GetInstance()
        {
            return _instance;
        }
        void LoadTextures();

        static Texture2D GetTexture(std::string name)
        {
            return GetInstance().GetTextureInternal(name);
        }

    private:
        Texture2D GetTextureInternal(std::string name)
        {
            return _textures[name];
        }

        GameAssets() = default;
        ~GameAssets() = default;

        GameAssets(const GameAssets&) = delete;

        static GameAssets _instance;
        std::map<std::string, Texture2D> _textures;
    };
}

#endif // GAMEASSETS_H