#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "display.h"
#include "bullet.h"

// Constants

typedef struct { 

    Rectangle enemyRect; 
    Texture2D enemyTex;
    Vector2 position; 
 
    int height; 
    int width; 
    float speed;
    int health; 

    
} Enemy;

void InitEnemy(Enemy *enemy); 
void DrawEnemy(Enemy enemy); 

void EnemyCollision(Enemy *enemy);
void EnemyMovement(Enemy *enemy);

// void EnemyHurt(Enemy enemy); 

#endif 