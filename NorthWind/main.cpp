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

    SetTargetFPS(60);

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

        DrawTextureEx(map, mapPos, 0.0f, 4.0f, WHITE);
        
        EndDrawing();
    }
    CloseWindow();
}