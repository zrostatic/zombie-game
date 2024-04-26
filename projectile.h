// #ifndef PROJECTILE_H 
// #define PROJECTILE_H

// #include "raylib.h"
// #include "logic.h"
// #include "player.h"


typedef struct { 

    Vector2 velocity; 
    Vector2 position; 
    Texture2D texture;
    float lifetime;  

} Projectile; 

// Projectile projectile;

// void DrawProjectile() { 

//     projectile.texture = LoadTexture("resources/shitty-bullet.png"); 
//     projectile.position.x = playerPosition.x;  
//     projectile.position.y = playerPosition.y; 
// }

// void UpdateProjectile() { 

//     projectile.velocity.x = 10;
//     projectile.velocity.y = 0; 

//     if (IsKeyDown(KEY_SPACE)) { 
//         DrawProjectile();
//         projectile.position.x += projectile.velocity.x; 
//         projectile.position.y += projectile.velocity.y; 
//     } 
// }



// #endif