#include "display.h"
#include "environment.h"

Background background; 

void InitBackground(Background *background) {

    background->position.x = 0; 
    background->position.y = 0;

    background->backgroundTex = LoadTexture("resources/materials/grass.png");
    background->is_stained = false; 

}

void DrawBackground(Background background) { 

        for (int y = 0; y < SCREEN_HEIGHT; y += TILE_SIZE) {
            for (int x = 0; x < SCREEN_WIDTH; x += TILE_SIZE) {
                DrawTexture(background.backgroundTex, x, y, WHITE);
            }
        }
}
