#include <math.h>
#include "raylib.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"

Gun gun;
Bullet bullets[MAX_BULLETS];

void InitBullet(Gun gun, Bullet *bullets) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets[i].bulletRect = (Rectangle){0, 0, 24, 24};
        bullets[i].bulletTex = LoadTexture("resources/weapons/shitty-bullet.png");
        bullets[i].position = (Vector2){gun.position.x, gun.position.y};
        bullets[i].velocityX = 6.0f;
        bullets[i].velocityY = 6.0f;
        bullets[i].is_active = false;
    }
}

void DrawBullet(Bullet bullets[]) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].is_active) {
            DrawTextureRec(bullets[i].bulletTex, bullets[i].bulletRect, (Vector2){bullets[i].position.x, bullets[i].position.y}, WHITE);
        }
    }
}

void FireBullet(Player player, Gun gun, Bullet *bullets) {
    static bool canFire = true;

    if (player.has_weapon && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && canFire) {
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (!bullets[i].is_active) {
                bullets[i].is_active = true;

                // Calculate direction vector from player to cursor
                float directionX = GetMouseX() - (player.position.x + 90.0f);
                float directionY = GetMouseY() - (player.position.y + 35.0f);

                // Calculate the magnitude of the direction vector
                float magnitude = sqrt(directionX * directionX + directionY * directionY);

                // Normalize the direction vector
                if (magnitude > 0) {
                    directionX /= magnitude;
                    directionY /= magnitude;
                }

                // Set bullet's velocity components
                float bulletSpeed = 5.0f;
                bullets[i].velocityX = directionX * bulletSpeed;
                bullets[i].velocityY = directionY * bulletSpeed;

                // Set bullet's initial position
                bullets[i].position = player.position;

                // Set canFire to false to prevent rapid firing
                canFire = false;
                break;
            }
        }
    }

    if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        canFire = true;
    }
}

void UpdateBullet(Player player, Bullet *bullets) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].is_active) {
            bullets[i].position.x += bullets[i].velocityX;
            bullets[i].position.y += bullets[i].velocityY;
        }
    }
}
