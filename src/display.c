#include "raylib.h"
#include "display.h"

void MakeFullScreen() {
    if ((!IsWindowFullscreen()) && (IsKeyDown(KEY_TAB))) { 
        ToggleFullscreen(); 
    }
    else if (IsWindowFullscreen() && (IsKeyDown(KEY_TAB))) { 
        ToggleFullscreen(); 
    } 
}



