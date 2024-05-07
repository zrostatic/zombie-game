#include "raylib.h"
#include "display.h"
#include "cursor.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "environment.h"

int main() {

    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(SCREEN_HEIGHT, SCREEN_WIDTH, "zombie-game");
    SetTargetFPS(144);
    DisableCursor();

    Cursor cursor;
    Player player;
    Gun gun;
    Bullet bullets[MAX_BULLETS]; 
    Enemy enemy;

    InitCursor(&cursor);
    InitPlayer(&player);
    InitBullet(gun, bullets); 
    InitGun(&player, &gun);
    InitEnemy(&enemy);

    while (!WindowShouldClose()) {

        MakeFullScreen(); 

        DrawBullet(bullets);
        UpdateGunRotation(player, &gun);

        PlayerMovement(&player, &gun);
        PlayerCollision(&player);
        FireBullet(player, gun, bullets);

        UpdateGunRotation(player, &gun);
        UpdateBullet(player, bullets);

        EnemyMovement(&enemy);
        EnemyCollision(&enemy);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // DrawUI();

        DrawPlayer(player);
        DrawEnemy(enemy);
        DrawCursor(cursor);

        CheckEquipGun(&player, &gun);

        EndDrawing();
    }

    CloseWindow();
}
