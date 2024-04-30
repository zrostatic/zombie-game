#include "raylib.h"
#include "display.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "environment.h"

int main() {

    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(SCREEN_HEIGHT, SCREEN_WIDTH, "RayLib - zombie-shooter");
    SetTargetFPS(144);
    // DisableCursor(); 

    Background background; 

    Player player;
    Gun gun;
    Bullet bullet; 
    Enemy enemy;

    InitBackground(&background);
    InitPlayer(&player);
    InitGun(&player, &gun);
    InitBullet(&bullet, &gun);
    InitEnemy(&enemy); 

    player.has_weapon = true; 

    while (!WindowShouldClose()) {

        MakeFullScreen(); 

        PlayerMovement(&player, &gun);
        PlayerCollision(&player); 

        EnemyMovement(&enemy);
        EnemyCollision(&enemy); 
 
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            DrawBackground(background);
            
            DrawText("ZOMBIE-GAME", 10, 10, 30, RED);
            DrawText("HEALTH: ", 30, 60, 20, RAYWHITE); 
            DrawText("WAVE: ", 800, 10, 20, RED); 

            DrawPlayer(player);
            DrawEnemy(enemy);

            EquipGun(gun);
            
        EndDrawing();
    }
    CloseWindow();
}
