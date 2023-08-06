/**

Struct Rectangle Var        Struct Vector2 Var
Var.x                       var.x               Posição horizontal do canto superior direito
Var.y                       vat.y               Posição vertical do canto superior direito
Var.Width                                       Largura
Var.Height                                      Altura

**/

#include "raylib.h"
#define ScreenSize 800      //tamanho da janela quadrada para calculos

Rectangle Start;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;    //largura da janela
    const int screenHeight = 800;   //altura da janela

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");  //cria a jenela

    int fonte = 80; //tamanho da fonte 20px

    int Yi = (screenHeight -  fonte )/2; //distancia do primeiro texto até topo da janela (para centralizar todo ele)

    char texto [50]= {"Start"};

    Start.x = (screenWidth - MeasureText(texto,fonte))/2;//screenWidth/2;
    Start.y = Yi ; //screenHeight/2;
    Start.width = MeasureText(texto,fonte);
    Start.height = fonte;



    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();     //começa a desenhar na janela

        ClearBackground(RAYWHITE);      //cor do fundo

        //DrawText("mensagem", largura, altura, fonte, cor)
        DrawRectangleRec(Start,BLACK);
        DrawText(texto, (screenWidth - MeasureText(texto,fonte))/2, Yi, fonte, RED);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
