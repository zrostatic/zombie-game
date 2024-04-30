#include "raylib.h"
#include "player.h"
#include "bullet.h"

Bullet bullet; 

void InitBullet(Bullet *bullet, Gun *gun){

    bullet->position.x = gun->position.x + 10; 
    bullet->position.y = gun->position.y; 

    bullet->bulletRect.x = 0; 
    bullet->bulletRect.y = 0; 
    bullet->bulletRect.height = 32;
    bullet->bulletRect.width = 32; 

    bullet->bulletTex = LoadTexture("resources/weapons/shitty-bullet.png");

}

void DrawBullet(Bullet bullet, Gun gun) {

    DrawTextureRec(bullet.bulletTex, bullet.bulletRect, (Vector2){bullet.position.x, bullet.position.y}, WHITE);


}
