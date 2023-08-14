//extra rotacionar cubos

#include "raylib.h"
#include <math.h>
#define FPS 60

#define WIDTH 800
#define HEIGHT 800

typedef struct {
    float x;
    float y;
    float width;
    float height;
    float rot;
    float vel;
    Texture2D text;
} rec;

int main(void)
{
    rec rec1;
    rec1.x =400;
    rec1.y =450;
    rec1.width = 100;
    rec1.height =100;
    rec1.rot=0;
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
            while(CheckCollisionRecs((Rectangle){rec1.x,rec1.y,rec1.width,rec1.height},rec2))
            {
                rec1.y ++;
                rec1.y= floor(rec1.y);
            }
        }
        if(IsKeyDown (KEY_DOWN))
        {
            rec1.y += veloc.y/FPS;
            while(CheckCollisionRecs((Rectangle){rec1.x,rec1.y,rec1.width,rec1.height},rec2))
            {
                rec1.y --;
                rec1.y= ceil(rec1.y);
            }
        }
        if(IsKeyDown (KEY_LEFT))
        {
            rec1.x -= veloc.x/FPS;
            while(CheckCollisionRecs((Rectangle){rec1.x,rec1.y,rec1.width,rec1.height},rec2))
            {
                rec1.rot ++;
                rec1.rot= ceil(rec1.x);
            }
        }
        if(IsKeyDown (KEY_RIGHT))
        {
            rec1.x += veloc.x/FPS;
            while(CheckCollisionRecs((Rectangle){rec1.x,rec1.y,rec1.width,rec1.height},rec2))
            {
                rec1.rot --;
                rec1.rot= floor(rec1.x);
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
            DrawRectanglePro((Rectangle){rec1.x,rec1.y,rec1.width,rec1.height}, (Vector2) {0,0}, rec1.rot, RED);
            DrawRectangleRec((Rectangle){rec1.x,rec1.y,rec1.width,rec1.height}, BLUE);
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
