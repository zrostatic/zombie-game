#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "display.h"

// Constants

typedef struct { 

    Vector2 position; 
    int height; 
    int width; 
    float speed; 
    
} Player;

void InitPlayer(); 
void PlayerControls(); 

#endif 