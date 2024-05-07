#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "display.h"

// Constants

typedef struct { 

    Rectangle playerRect; 
    Texture2D playerTex; 
    Vector2 position; 

    int height; 
    int width; 
    int health;
    float speed;
    float scale; 
    bool is_alive;
    bool has_weapon; 
    
} Player;

typedef struct{ 

    Rectangle gunRect; 
    Texture2D gunTex;
    Vector2 position; 
    float rotation; 

    char name; 

} Gun; 

// Initialize
void InitPlayer(Player *player); 
void InitGun(Player *player, Gun *gun);

// Draw
void DrawPlayer(Player player);
void DrawGun(Player player, Gun gun);

// Controls 
void PlayerMovement(Player *player, Gun *gun); 
bool CheckEquipGun(Player *player, Gun *gun);
void UpdateGunRotation(Player player, Gun *gun);

// Collision
void PlayerCollision(Player *player);

#endif 

