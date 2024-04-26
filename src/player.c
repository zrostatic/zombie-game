#include "raylib.h"
#include "logic.h"
#include "player.h"

Player player; 

void InitPlayer() { 

    player.position.x = 300; 
    player.position.y = 400; 
}

void PlayerControls() { 

    if(IsKeyDown(KEY_RIGHT))
    player.position.x += player.speed;

    if(IsKeyDown(KEY_LEFT))
    player.position.x -= player.speed;
    
    if(IsKeyDown(KEY_DOWN))
    player.position.y += player.speed; 
    
    if(IsKeyDown(KEY_UP))
    player.position.y -= player.speed; 

}
