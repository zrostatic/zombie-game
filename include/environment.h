#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H 

#define GRID_SIZE 8
#define TILE_SIZE 32

#include "raylib.h"

typedef struct{

    Vector2 position;
    Texture2D backgroundTex; 
    bool is_stained; 

} Background; 


void InitBackground(Background *background);
void DrawBackground(Background background); 

#endif