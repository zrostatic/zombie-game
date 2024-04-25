#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

// Constants
#define SCREEN_HEIGHT 960
#define SCREEN_WIDTH 720

#define PLAYER_HEIGHT 96
#define PLAYER_WIDTH 96
#define PLAYER_RADIUS 10


#define MAX_PROJECTILES 70
#define IS_DEAD FALSE 


// PlayerProjectile Struct
typedef struct{

    Vector2 position;
    Vector2 velocity; 
    bool is_active;
    Color color; 

} Projectile; 

// Player Position 
Vector2 playerPosition = {300, 400};

// // Player Projectile 
// Projectile projectiles[MAX_PROJECTILES] = {0}; 

// int PlayerProjectile() { 

//     if(IsKeyDown(KEY_SPACE)) { 
//         for (int i = 0; i < MAX_PROJECTILES; i++) { 
//             if (!projectiles[i].is_active){  
//             projectiles[i].position = (Vector2){playerPosition.x + PLAYER_WIDTH / 2, playerPosition.y + PLAYER_HEIGHT / 2 };
//             projectiles[i].velocity = (Vector2){ 7, 0 }; 
//             projectiles[i].is_active = true; 
//             projectiles[i].color = SKYBLUE; 
//             }
//         }
//     }
//     // Update Projectiles
//     for (int i = 0; i < MAX_PROJECTILES; i++)
//         {
//             if (projectiles[i].is_active)
//             {
//                 projectiles[i].position.x += projectiles[i].velocity.x;
//                 projectiles[i].position.y += projectiles[i].velocity.y;

//                 // Deactivate projectiles when they go out of bounds
//                 if (projectiles[i].position.x > SCREEN_WIDTH|| projectiles[i].position.y > SCREEN_HEIGHT)
//                 {
//                     projectiles[i].is_active = false;
//                 }
//             }
//     }
// }





// int DrawPlayerProjectile() { 
//         for (int i = 0; i < MAX_PROJECTILES; i++)
//         {
//             if (projectiles[i].is_active)
//             {
//                 DrawRectangleV(projectiles[i].position, (Vector2){ 5, 5 }, projectiles[i].color);
//             }
//         }

// }



// Player Controls 
int PlayerControls() { 

    if(IsKeyDown(KEY_RIGHT))
    playerPosition.x += 2.0f;

    if(IsKeyDown(KEY_LEFT))
    playerPosition.x -= 2.0f;
    
    if(IsKeyDown(KEY_DOWN))
    playerPosition.y += 2.0f; 
    
    if(IsKeyDown(KEY_UP))
    playerPosition.y -= 2.0f; 

    return 0;
}


// Debug

int DisplayPlayerPosition() { 

    DrawText(TextFormat("Player Position: [%i , %i]", (int)playerPosition.x, (int)playerPosition.y), 20, 20, 20, SKYBLUE);

    return 0;
}


#endif 