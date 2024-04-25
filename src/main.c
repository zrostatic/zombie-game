#include "raylib.h"
#include "player.h"

int main() 
{

    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(SCREEN_HEIGHT, SCREEN_WIDTH, "RayLib - zombie-shooter");
    SetTargetFPS(144);             
    HideCursor(); 

    Texture2D guyTex = LoadTexture("resources/big-guy.png"); 
    Texture2D zombieTex = LoadTexture("resources/big-zombie.png");

    while (!WindowShouldClose())
    {


        PlayerControls();

        BeginDrawing();

            ClearBackground(RAYWHITE);

            DisplayPlayerPosition();

            DrawTexture(guyTex, playerPosition.x, playerPosition.y, WHITE); 
            DrawTexture(zombieTex, 400, 300, WHITE); 

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    CloseWindow();

    return 0;
}
