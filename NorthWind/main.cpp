#include "raylib.h"
#include "raymath.h"

int main()
{
    const int windowWidth{800};
    const int windowHeight{800};
    InitWindow(windowWidth, windowHeight, "NorthWind");

    Texture2D map = LoadTexture("nature_tileset/WorldMap.png");
    Vector2 mapPos{};
    float speed{4.0};

    Texture2D knight = LoadTexture("characters/Erland.png");
    Vector2 knightPos
    {
        static_cast<float>(windowWidth)/2.0f - 4.0f * (0.5f * (static_cast<float>(knight.width)/8.0f)),
        static_cast<float>(windowHeight)/2.0f - 4.0f * (0.5f * static_cast<float>(knight.height)/4.0f)
    };

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if(IsKeyDown(KEY_A))
        {
            direction.x -= 1.0;
        }

        if(IsKeyDown(KEY_D))
        {
            direction.x += 1.0;
        }

        if(IsKeyDown(KEY_W))
        {
            direction.y -= 1.0;
        }

        if(IsKeyDown(KEY_S))
        {
            direction.y += 1.0;
        }

        if(Vector2Length(direction) != 0.0)
        {

            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        }

        // draw the map
        DrawTextureEx(map, mapPos, 0.0f, 4.0f, WHITE);
        
        //draw the character
        Rectangle source{0.f, 0.f, static_cast<float>(knight.width)/8.f, static_cast<float>(knight.height)/4.0f};
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * static_cast<float>(knight.width)/8.0f, 4.0f * static_cast<float>(knight.height)/4.0f};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);

        EndDrawing();
    }
    CloseWindow();
}