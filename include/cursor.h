#ifndef CURSOR_H
#define CURSOR_H


typedef struct{

    Rectangle cursorRect; 
    Texture2D cursorTex; 

    Vector2 position;


} Cursor; 

void InitCursor(Cursor *cursor); 
void DrawCursor(Cursor cursor);

#endif