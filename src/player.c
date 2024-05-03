#include <math.h>

#include "raylib.h"
#include "player.h"
#include "enemy.h"

Player player;


void InitPlayer(Player *player) { 

    player->position.x = 30; 
    player->position.y = 300; 
    player->height = 96; 
    player->width = 96; 
    player->speed = 2.0;
    player->health = 10;
    player->has_weapon = false; 
    player->is_alive = true; 

    player->playerRect.x = 0;
    player->playerRect.y = 0; 
    player->playerRect.height = 96;
    player->playerRect.width = 96;
    player->playerTex = LoadTexture("resources/entities/guy.png");
     
}

void DrawPlayer(Player player) { 

    DrawTextureRec(player.playerTex, player.playerRect, (Vector2){player.position.x, player.position.y}, WHITE);

}

void InitGun(Player *player, Gun *gun) { 

    gun->position.x = player->position.x + 60; 
    gun->position.y = player->position.y + 35;

    gun->gunRect.x = 0;
    gun->gunRect.y = 0; 
    gun->gunRect.height = 48;
    gun->gunRect.width = 48;
    gun->gunTex = LoadTexture("resources/weapons/pistol.png");

}

void DrawGun(Player player, Gun gun) { 
        
    Vector2 cursorPos = GetMousePosition();
    float angle = atan2(cursorPos.y - gun.position.y, cursorPos.x - gun.position.x);
    angle = angle * RAD2DEG;

    Rectangle destRect = {
        gun.position.x, 
        gun.position.y, 
        gun.gunRect.width,
        gun.gunRect.height
    };

    Vector2 origin = {gun.gunRect.width / 800, gun.gunRect.height / 800}; 
    DrawTexturePro(gun.gunTex, gun.gunRect, destRect, origin, angle, WHITE);

}

void EquipGun(Gun gun){

    if (IsKeyPressed(KEY_ONE)) {
        player.has_weapon = !player.has_weapon; 
    }

    if(player.has_weapon) {
        DrawGun(player, gun);
        player.has_weapon = true; 
    }
}

void PlayerMovement(Player *player, Gun *gun) { 
    
    if ((IsKeyDown(KEY_RIGHT)) || (IsKeyDown(KEY_D)))
    player->position.x += player->speed;
    gun->position.x = player->position.x + 60; 
    gun->position.y = player->position.y + 35;

    if ((IsKeyDown(KEY_LEFT)) || (IsKeyDown(KEY_A))) 
    player->position.x -= player->speed;
    gun->position.x = player->position.x + 60; 
    gun->position.y = player->position.y + 35;
    
    if ((IsKeyDown(KEY_DOWN)) || (IsKeyDown(KEY_S)))
    player->position.y += player->speed;
    gun->position.x = player->position.x + 60; 
    gun->position.y = player->position.y + 35; 
    
    if((IsKeyDown(KEY_UP) || (IsKeyDown(KEY_W))))
    player->position.y -= player->speed;
    gun->position.x = player->position.x + 60; 
    gun->position.y = player->position.y + 35;

}

void PlayerCollision(Player *player) { 

    if (player->position.x < 0) {
            player->position.x = 0;
        }
        if (player->position.x > GetScreenWidth() - player->width) {
            player->position.x = GetScreenWidth() - player->width;
        }
        if (player->position.y < 0) {
            player->position.y = 0;
        }
        if (player->position.y > GetScreenHeight() - player->height) {
            player->position.y = GetScreenHeight() - player->height;
        }
}
