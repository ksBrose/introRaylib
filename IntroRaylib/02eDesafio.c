/**

Ao clicar com botão esquerdo do mouse o quadrado deve ficar azul, com o
botão esquerdo o quadrado deve ficar vermelho e o botao do meio reseta
Mas com cabeçalho no topo

**/

#include "raylib.h"
#define ScreenSize 800
#define Nb 10
#define Sb (ScreenSize/Nb)
#define Mar 40

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800+Mar; //+30 cabeçalho
    int M [Nb][Nb];
    char n_blue = '0';
    for(int i = 0; i<Nb; i++)
    {
        for(int j=0; j<Nb; j++)
        {
            M [i][j] = 0;
        }
    }

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Prog
        //----------------------------------------------------------------------------------
        if( GetMouseX()>0 && GetMouseY()> Mar && GetMouseX()<ScreenSize && GetMouseY()<ScreenSize)
        {
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                M[GetMouseX()/Sb][(GetMouseY()-Mar)/Sb] = 1;
            }
            if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            {
                M[GetMouseX()/Sb][(GetMouseY()-Mar)/Sb] = 2;
            }
            if(IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
            {
                for(int i = 0; i<Nb; i++)
                {
                    for(int j=0; j<Nb; j++)
                    {
                        M [i][j] = 0;
                    }
                }
            }
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangleLines(10,10,Sb,20,BLUE);
        DrawText(" %d", 10, 10, 20, BLUE);

        for(int i = 0; i<Nb; i++)
        {
            for(int j = 0; j<Nb; j++)
            {

                switch (M[i][j])
                {
                case 0:
                    DrawRectangle(Sb*i,Sb*j+Mar,Sb,Sb,WHITE);
                    break;
                case 1:
                    DrawRectangle(Sb*i,Sb*j+Mar,Sb,Sb,BLUE);
                    break;
                case 2:
                    DrawRectangle(Sb*i,Sb*j+Mar,Sb,Sb,RED);
                    break;
                }
                DrawRectangleLines(Sb*i,Sb*j+Mar,Sb,Sb,BLACK);

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

