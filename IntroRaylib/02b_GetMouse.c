/**

GetMouseX pega a posição x do mouse na janela
substitui x por y para pegar y

**/

#include "raylib.h"
#define ScreenSize 800      //tamanho da janela quadrada para calculos
#define Nb 10               //quantos quadrados por linha
#define Sb (ScreenSize/Nb)  //tamanho de cada quadrado, entre parenteses pois vai ser usado em calculo depois

int main(void)
{
    const int screenWidth = 800;    //largura da janela
    const int screenHeight = 800;   //altura da janela  //+40 cabeçalho

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        ClearBackground(RAYWHITE);
        BeginDrawing();
        for(int i = 0; i<Nb; i++)
        {
            for(int j = 0; j<Nb; j++)
            {
                //DrawRectangle(posição x, posição y, largura do retangulo, altura do retangulo, cor);
                //DrawRectangle(800*i/10, 800*j/10, screenWidth/10, screenHeight/10, BLACK);
                DrawRectangle(Sb*i, Sb*j/*+40*/, Sb, Sb, BLUE);         //o + 40 caso for fazer um cabeçalho no topo
                DrawRectangleLines(Sb*i, Sb*j/*+40*/, Sb, Sb, BLACK);   //o + 40 caso for fazer um cabeçalho no topo
            }
        }
        //GetMouseX pega a posição x do mouse na janela substitui x por y para pegar y
        //DrawRectangle( 0, 0, GetMouseX(), GetMouseY(), RED); //pega a posição do mouse e desenha um quadrado do (0,0) até a ponta do mouse
        DrawRectangle(GetMouseX()-50, GetMouseY()-50, 50, 50, RED); //Desenha um quadrado de tamanho 50 na ponta do mouse

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
