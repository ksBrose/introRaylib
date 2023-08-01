/*
Fazer um programa como se fosse a tela de espera do dvd
com um texto DVD mude de direção ao tocar nas laterais da janela
*/

#include "raylib.h" //inclusão da biblioteca
#define TAM 1       //numero de linhas no texto

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;    //largura da janela
    const int screenHeight = 450;   //altura da janela
    int fonte = 40; //tamanho da fonte 20px
    int E = 1;      //espaçamento se tiver mais de uma linha
    float i = 0;
    float Vx = 2.5; //velocidade no eixo x
    float j = 0;
    float Vy = 2.5; //velocidade no eixo y
    char texto [TAM][50]= {"DVD"};
    int Yi = (screenHeight - TAM * fonte - (TAM-1) * E)/2; //distancia do primeiro texto até topo da janela (para centralizar todo ele)



    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");  //cria a jenela

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();     //começa a desenhar na janela
        //a cada loop (Frame) ira atualizar a posição x=i e y=j
        i = i + Vx;         //posição x será posição mais deslocamento
        j = j + Vy;         //posição y será posição mais deslocamento
            ClearBackground(RAYWHITE);      //cor do fundo

            DrawText(texto,i,j , fonte, LIGHTGRAY); //DrawText("mensagem", posição x, posição y, fonte, cor)

            if(i  <= 0 || i>= (screenWidth-MeasureText(texto,fonte)))   //ao chegar na lateral considerando o tamanho do texto
                Vx = -Vx;                                               //inverte a variavel Vx
            if(j  <= 0 || j>= (screenHeight-fonte) )                    //ao chegar na lateral considerando a fonte do texto
                Vy = -Vy;                                               //inverte a variavel Vy
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
