/**
    Camera2D camera;
        BeginMode2D(camera);
        EndMode2D();
Fixar a camera no quadrado que movimenta.
camera tem quatro variaveis, posição x e y, rotação e zoom(se = 1 sera mesmo tamanho da janela)
tem offset pos o ponto da camera é no topo esquerdo offset é necessario para centraliza-la

**/
#include "raylib.h"
#include <math.h>
#define FPS 60

#define WIDTH 800
#define HEIGHT 800

int main(void)
{
    Rectangle rec1 = (Rectangle) {300,450,100,100};
    Rectangle rec2 = (Rectangle) {300,300,100,100};
    Camera2D camera;
    Vector2 veloc = {150,100};
    camera.target.x = rec1.x;
    camera.target.y = rec1.y;
    camera.rotation = 0;
    camera.zoom = 1;
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
                rec1.y= floor(rec1.y);
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
                rec1.x= floor(rec1.x);
            }
        }
        camera.target.x = rec1.x;
        camera.target.y = rec1.y;
        //camera.rotation = -a.rot;
        camera.offset.x = WIDTH/2;
        camera.offset.y = HEIGHT/2;
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        BeginMode2D(camera);

            ClearBackground(RAYWHITE);
            DrawRectangleRec(rec1, BLUE);
            DrawRectangleRec(rec2, RED);

        EndDrawing();
        EndMode2D();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
