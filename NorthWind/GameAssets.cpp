#include "GameAssets.h"

namespace World
{
    GameAssets::GameAssets()
    {
        LoadTextures();
    }

    void GameAssets::LoadTextures()
    {
        _textures["Erland"] = LoadTexture("Art/Erland.png");
        _textures["WorldMap"] = LoadTexture("Art/WorldMap.png");
    }
}