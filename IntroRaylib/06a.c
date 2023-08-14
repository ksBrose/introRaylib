/**
Se identificar colisão (um quadrado ja esta dentro do outro)
CheckCollisionRecs(rec1,rec2)
movimentar para o sentido oposto
rec1.x --;

é necessario arredondar pois a velocidade pode retornar um float deixando um quadrado afastado do outro
então é necessario arredondar para cima ou para baixo com ceil ou floor dependendo do lado da colisao
rec1.x= ceil(rec1.x);


**/
#include "raylib.h"
#include <math.h>
#define FPS 60

int main(void)
{
    Rectangle rec1 = (Rectangle) {300,450,100,100};
    Rectangle rec2 = (Rectangle) {300,300,100,100};

    Vector2 veloc = {150,100};

    InitWindow(800, 800, "raylib [core] example - input mouse wheel");

    SetTargetFPS(FPS);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if(IsKeyDown (KEY_UP))
        {
            rec1.y -= veloc.y/FPS;
            while(CheckCollisionRecs(rec1,rec2))
            {
                rec1.y ++;
                rec1.y= ceil(rec1.y);
            }
        }
        if(IsKeyDown (KEY_DOWN))
        {
            rec1.y += veloc.y/FPS;
            while(CheckCollisionRecs(rec1,rec2))
            {
                rec1.y --;
                rec1.y= ceil(rec1.y);
            }
        }
        if(IsKeyDown (KEY_LEFT))
        {
            rec1.x -= veloc.x/FPS;
            while(CheckCollisionRecs(rec1,rec2))
            {
                rec1.x ++;
                rec1.x= ceil(rec1.x);
            }
        }
        if(IsKeyDown (KEY_RIGHT))
        {
            rec1.x += veloc.x/FPS;
            while(CheckCollisionRecs(rec1,rec2))
            {
                rec1.x --;
                rec1.x= ceil(rec1.x);
            }
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawRectangleRec(rec1, BLUE);
            DrawRectangleRec(rec2, RED);



        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
