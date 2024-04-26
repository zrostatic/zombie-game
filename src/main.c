#include "raylib.h"
#include "display.h"
#include "logic.h"
#include "player.h"

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(SCREEN_HEIGHT, SCREEN_WIDTH, "RayLib - zombie-shooter");
    SetTargetFPS(144);
    HideCursor();

    InitPlayer();

    Texture2D guyTex = LoadTexture("resources/entities/guy.png");
    Texture2D zombieTex = LoadTexture("resources/entities/zombie.png");

    Player player; 

    while (!WindowShouldClose()) {
        MakeFullScreen();
        PlayerControls();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
      
        DrawTexture(guyTex, player.position.x, player.position.y, WHITE);
        DrawTexture(zombieTex, 400, 300, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
