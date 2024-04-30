#include "environment.h"

Background background; 

void InitBackground(Background *background) {

    background->position.x = 0; 
    background->position.y = 0;

    background->backgroundTex = LoadTexture("resources/materials/grass.png");
    background->is_stained = false; 

}

void DrawBackground(Background background) { 

    for (int y = background.position.y; y < GRID_SIZE; background.position.y++) {
            for (int x = background.position.x; x < GRID_SIZE; background.position.x++) {
                background.position.x = background.position.x * TILE_SIZE; 
                background.position.y = background.position.y * TILE_SIZE; 
                DrawTexture(background.backgroundTex, 0, 0, WHITE);
            }
    }
}