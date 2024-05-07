#include "raylib.h"
#include "display.h"
#include "player.h" 


void MakeFullScreen() {
    if ((!IsWindowFullscreen()) && (IsKeyDown(KEY_TAB))) { 
        ToggleFullscreen(); 
    }
    else if (IsWindowFullscreen() && (IsKeyDown(KEY_TAB))) { 
        ToggleFullscreen(); 
    } 
}

void DrawUI() {

    DrawText("ZOMBIE-GAME", 10, 10, 30, RED);
    DrawText("HEALTH: ", 30, 60, 30, GREEN); 
    DrawText("WAVE: ", 800, 10, 30, SKYBLUE); 

}


