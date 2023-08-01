/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"  //inclusão da biblioteca
#define TAM 4

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;    //largura da janela
    const int screenHeight = 450;   //altura da janela
    int fonte = 50; //tamanho da fonte 20px
    int E = 1;  //espaçamento entre cada linha

    int Yi = (screenHeight - TAM * fonte - (TAM-1) * E)/2; //distancia do primeiro texto até topo da janela (para centralizar todo ele)

    char texto [TAM][50]= {"Introducao","de","Raylib", "Que comecem os jogos"};


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");  //cria a jenela

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();     //começa a desenhar na janela

            ClearBackground(RAYWHITE);      //cor do fundo

            //DrawText("ops aqui vai um texto"  , (screenWidth/2 - MeasureText("ops aqui vai um texto",fonte)/2), (screenHeight/2 - fonte/2), fonte, LIGHTGRAY);
            //DrawText(     "mensagem"          ,largura, altura, fonte, cor)
            //para largura MeasureText("texto" ou var sring, tamanhofonte); Retornatá o tamanho da largura de todo texto
            //para altura já é direto pelo tamanho da fonte

            for(int i = 0; i < TAM ; i++)
            {
                //DrawText("mensagem", largura, altura, fonte, cor)
                DrawText(texto[i], (screenWidth/2 - MeasureText(texto[i],fonte)/2), Yi + i * (fonte + E), fonte, LIGHTGRAY);
                      //texto para cada i, centralizar dependendo do tamanho de cada linha, altura é Yi distancia para o topo mais (n) linhas e espaçamento se tiver

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
