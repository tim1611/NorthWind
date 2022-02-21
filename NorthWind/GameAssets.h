#pragma once

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
            static GameAssets instance;
            return instance;
        }

        static Texture2D GetTexture(std::string name)
        {
            return GetInstance().GetTextureInternal(name);
        }

    private:
        Texture2D GetTextureInternal(std::string name)
        {
            return _textures[name];
        }

        void LoadTextures();

        GameAssets();

        ~GameAssets() = default;

        GameAssets(const GameAssets&) = delete;

        
        std::map<std::string, Texture2D> _textures;
    };
}
