#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"
#include "player.h"
#include "enemy.h"

#define MAX_BULLETS 100

typedef struct {
    Vector2 position;
    Rectangle bulletRect;
    Texture2D bulletTex;
    float velocityX;
    float velocityY;
    bool is_active;
} Bullet;

void InitBullet(Gun gun, Bullet *bullets);
void DrawBullet(Bullet bullets[]);
void FireBullet(Player player, Gun gun, Bullet *bullets);
void UpdateBullet(Player player, Bullet *bullets);

#endif
