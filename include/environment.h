#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H 

#include "raylib.h"
#include "display.h"

#define TILE_SIZE 120

typedef struct{

    Vector2 position;
    Texture2D backgroundTex; 
    bool is_stained; 

} Background; 


void InitBackground(Background *background);
void DrawBackground(Background background); 

#endif