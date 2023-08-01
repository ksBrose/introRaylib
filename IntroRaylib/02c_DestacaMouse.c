/**

Muda a cor do quadrado se o mouse estiver sobre ele

**/

#include "raylib.h"
#define ScreenSize 800      //tamanho da janela quadrada para calculos
#define Nb 10               //quantos quadrados por linha
#define Sb (ScreenSize/Nb)  //tamanho de cada quadrado, entre parenteses pois vai ser usado em calculo depois

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;//+40; // cabeçalho

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(120);               // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        ClearBackground(RAYWHITE);
        BeginDrawing();
        for(int i = 0; i<Nb; i++)
        {
            for(int j = 0; j<Nb; j++)
            {
                if(GetMouseX()/Sb == i && (GetMouseY())/Sb == j)
                {
                    DrawRectangle(Sb*i,Sb*j,Sb,Sb,BLUE);
                }
                else
                    DrawRectangle(Sb*i, Sb*j, Sb, Sb, GREEN);
                //DrawRectangle(800*i/10, 800*j/10, screenWidth/10, screenHeight/10, BLACK);
                //DrawRectangle(Sb*i, Sb*j/*+40*/, Sb, Sb, BLUE);
                DrawRectangleLines(Sb*i, Sb*j, Sb, Sb, BLACK);
            }
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
