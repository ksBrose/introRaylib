/**

DrawRectangle(posição x, posição y, largura do retangulo, altura do retangulo, cor);

**/

#include "raylib.h"
#define ScreenSize 800      //tamanho da janela quadrada para calculos
#define Nb 10               //quantos quadrados por linha
#define Sb ScreenSize/Nb    //tamanho de cada quadrado

int main(void)
{
    const int screenWidth = 800;    //largura da janela
    const int screenHeight = 800;   //altura da janela  //+30 cabeçalho

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
                DrawRectangle(Sb*i, Sb*j, Sb, Sb, BLUE);
                DrawRectangleLines(Sb*i, Sb*j, Sb, Sb, BLACK);  //vai desenhar uma linha de 1 pixel na posição desejada
            }
        }

        //ClearBackground(RAYWHITE);
        //DrawRectangle(0, 0, screenWidth/10, screenHeight/10, BLACK);  //um quadrado no ponto (0,0)

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
