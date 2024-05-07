#include "raylib.h"
#include "enemy.h" 

Enemy enemy; 

void InitEnemy(Enemy *enemy) { 

    enemy->position.x = 800;
    enemy->position.y = 300; 
    enemy->height = 96; 
    enemy->width = 96; 
    enemy->speed = 0.3;

    enemy->enemyRect.x = 0;
    enemy->enemyRect.y = 0; 
    enemy->enemyRect.height = 96; 
    enemy->enemyRect.width = 96; 

    enemy->enemyTex = LoadTexture("resources/entities/zombie/zombie.png");

}

void DrawEnemy(Enemy enemy) { 

    DrawTextureRec(enemy.enemyTex, enemy.enemyRect, (Vector2){enemy.position.x, enemy.position.y}, WHITE);

}

void EnemyCollision(Enemy *enemy) { 

    if (enemy->position.x < 0) {
            enemy->position.x = 0;
        }
        if (enemy->position.x > GetScreenWidth() - enemy->width) {
            enemy->position.x = GetScreenWidth() - enemy->width;
        }
        if (enemy->position.y < 0) {
            enemy->position.y = 0;
        }
        if (enemy->position.y > GetScreenHeight() - enemy->height) {
            enemy->position.y = GetScreenHeight() - enemy->height;
        }


}

void EnemyMovement(Enemy *enemy) { 
    
    enemy->position.x -= enemy->speed; 

}

