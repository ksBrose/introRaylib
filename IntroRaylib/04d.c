/**

fixar a velocidade denpendendo dos frames

#define FPS 60
#define VELOC 180
#define v (VELOC/FPS)

**/

#include "raylib.h"
#define ScreenSize 800      //tamanho da janela quadrada para calculos

#define FPS 60
#define VELOC 180
#define v (VELOC/FPS)


Rectangle Start;
Color Background;
Color Cube;
Vector2 Origin;
Vector2 CubeO;

void DesenharOrigem(Vector2 O)
{
    DrawRectangle(O.x-10, O.y, 21,1,RED);
    DrawRectangle(O.x, O.y-10, 1,21,RED);
}



//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;    //largura da janela
    const int screenHeight = 800;   //altura da janela
    int i=0;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");  //cria a jenela

    Start.x = (screenWidth)/2;//screenWidth/2;
    Start.y = screenHeight/2 ; //screenHeight/2;
    Start.width = 100;
    Start.height = 100;

    Cube.r=0;
    Cube.g=0;
    Cube.b=255;
    Cube.a=255;

    Origin.x = 50;
    Origin.y = 50;

    SetTargetFPS(FPS);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        i++;
        Background.r=255;
        Background.g=255;
        Background.b=255;
        Background.a=255;


        int Rotation = i;
        CubeO.x= Start.x;
        CubeO.y= Start.y;

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))    //botão direito pressionado pinta em vermelho
        {
            Cube.r=GetRandomValue(0,255);
            Cube.g=GetRandomValue(0,255);
            Cube.b=GetRandomValue(0,255);
            Cube.a=255;
        }

        if(IsKeyDown(KEY_UP))    //seta para cima pressionada move cubo para cima
        {
            Start.y = Start.y-v;
        }
        if(IsKeyDown(KEY_DOWN))    //seta para baixo pressionada move cubo para baixo
        {
            Start.y = Start.y+v;
        }
        if(IsKeyDown(KEY_LEFT))    //seta para esq pressionada move cubo para esq
        {
            Start.x = Start.x-v;
        }
        if(IsKeyDown(KEY_RIGHT))    //seta para dir pressionada move cubo para dir
        {
            Start.x = Start.x+v;
        }

        BeginDrawing();     //começa a desenhar na janela

        ClearBackground(Background);      //cor do fundo

        //DrawRectangleRec(Start,GRAY);

        //DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color);
        DrawRectanglePro(Start, Origin, Rotation, Cube);

        DesenharOrigem(CubeO);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}


