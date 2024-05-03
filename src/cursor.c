#include "raylib.h"
#include "cursor.h"

Cursor cursor; 

void InitCursor(Cursor *cursor) {

    cursor->position = GetMousePosition();

    cursor->cursorRect.width = 96;
    cursor->cursorRect.height = 96; 

    cursor->cursorTex = LoadTexture("resources/weapons/cursor.png");
} 

void DrawCursor(Cursor cursor){

    DrawTextureRec(cursor.cursorTex, cursor.cursorRect, GetMousePosition(), SKYBLUE); 

}

