#ifndef BULLET_H
#define BULLET_H

typedef struct{

    Rectangle bulletRect;
    Texture2D bulletTex; 
    Vector2 position; 

} Bullet;

void InitBullet(Bullet *bullet, Gun *gun);
void DrawBullet(Bullet bullet, Gun gun); 


#endif