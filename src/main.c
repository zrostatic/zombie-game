#include "raylib.h"
#include "display.h"
#include "cursor.h"
#include "player.h"
#include "enemy.h"
#include "environment.h"


int main() {

    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(SCREEN_HEIGHT, SCREEN_WIDTH, "RayLib - zombie-shooter");
    SetTargetFPS(144);
    DisableCursor(); 

    Cursor cursor; 
    Player player; 
    Gun gun;
    Enemy enemy;

    InitCursor(&cursor);
    InitPlayer(&player);
    InitGun(&player, &gun);
    InitEnemy(&enemy); 

    player.has_weapon = false; 

    while (!WindowShouldClose()) {

        MakeFullScreen(); 

        PlayerMovement(&player, &gun);
        PlayerCollision(&player);
 
        EnemyMovement(&enemy);
        EnemyCollision(&enemy);
 
        BeginDrawing();

            ClearBackground(RAYWHITE);
                        
            DrawText("ZOMBIE-GAME", 10, 10, 30, RED);
            DrawText("HEALTH: ", 30, 60, 30, RED); 
            DrawText("WAVE: ", 800, 10, 30, RED); 

            DrawCursor(cursor);
            DrawPlayer(player);
            DrawEnemy(enemy);

            EquipGun(gun);

        EndDrawing();
    }
    CloseWindow();
}
