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
