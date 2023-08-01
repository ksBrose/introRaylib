/**

Ao clicar com botão esquerdo do mouse o quadrado deve ficar azul, com o
botão esquerdo o quadrado deve ficar vermelho e o botao do meio reseta

IsMouseButtonDown(MOUSE_BUTTON_LEFT) se mouse estiver pressionado (da para arrastar)
IsMouseButtonPressed() quando for pressionado (não da para arrastar)

**/

#include "raylib.h"
#define ScreenSize 800      //tamanho da janela quadrada para calculos
#define Nb 50               //quantos quadrados por linha
#define Sb (ScreenSize/Nb)  //tamanho de cada quadrado, entre parenteses pois vai ser usado em calculo depois

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;
    int M [Nb][Nb];         //inicializar matriz dos quadrados

    for(int i = 0; i<Nb; i++)
    {
        for(int j=0; j<Nb; j++)
        {
            M [i][j] = 0;   //todos quadrados começam com 0 (branco)
        }
    }

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Prog
        //----------------------------------------------------------------------------------
        if( GetMouseX()>0 && GetMouseY()> 0 && GetMouseX()<ScreenSize && GetMouseY()<ScreenSize) //detalhe para não pintar se arrastar o mouse para fora pode causar erro, pode pintar o lado oposto se não tiver isso ou forcar parada
        {
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))        //segurar o botão esquerdo pinta em azul
            {
                M[GetMouseX()/Sb][GetMouseY()/Sb] = 1;
            }
            if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))    //botão direito pressionado pinta em vermelho
            {
                M[GetMouseX()/Sb][GetMouseY()/Sb] = 2;
            }
            if(IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))   //rrestea as cores
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



        for(int i = 0; i<Nb; i++)
        {
            for(int j = 0; j<Nb; j++)
            {

                switch (M[i][j])
                {
                case 0:
                    DrawRectangle(Sb*i,Sb*j,Sb,Sb,WHITE);
                    break;
                case 1:
                    DrawRectangle(Sb*i,Sb*j,Sb,Sb,BLUE);
                    break;
                case 2:
                    DrawRectangle(Sb*i,Sb*j,Sb,Sb,RED);
                    break;
                }
                DrawRectangleLines(Sb*i,Sb*j,Sb,Sb,BLACK);

                //if(GetMouseX()/Sb == i && GetMouseY()/Sb == j)
                //{
                //    DrawRectangle(Sb*i,Sb*j,Sb,Sb,BLUE);
                //}
                //else
                //DrawRectangle(Sb*i, Sb*j/*+40*/, Sb, Sb, GREEN);
                //DrawRectangle(800*i/10, 800*j/10, screenWidth/10, screenHeight/10, BLACK);
                //  DrawRectangle(Sb*i, Sb*j/*+40*/, Sb, Sb, BLUE);
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

