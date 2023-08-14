/**
Com o exemplo dado pelo professor
tente animar a imagem

//DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);

    sprintf(nome, "./Texturas/Dog%dL.png", i);
    cachorro[i] = LoadTexture(nome);

**/

#include "raylib.h"
#include <stdio.h>
#include <math.h>
#define FPS 60

typedef enum {left = 0, right = 1, Lado_size} Lado;

void SetupWindow()
{
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Aula Texturas");
    SetTargetFPS(FPS);
    HideCursor();
    InitAudioDevice();
}

typedef struct
{
    Texture2D textures [Lado_size][3];
    Rectangle rec;
    int scale;
    Lado side;
    Texture2D *texture;
    double start_walking;
    Vector2 vel;
    Sound bark;
} dog;

void SetupDog(dog *Dog)
{
    char nome_end[40];
    for(int i = 0; i < 3; i++)
    {
        sprintf(nome_end, "./Texturas/Dog%dR.png", i + 1);
        Dog->textures[right][i] = LoadTexture(nome_end);
        sprintf(nome_end, "./Texturas/Dog%dL.png", i + 1);
        Dog->textures[left][i] = LoadTexture(nome_end);
    }
    Dog->texture = &Dog->textures[left][0];
    Dog->scale = 5;
    Dog->side = right;
    Dog->rec = (Rectangle)
    {
        x: 100,
        y: 100,
width:
        Dog->texture->width * Dog->scale,
height:
        Dog->texture->height * Dog->scale
    };
    Dog->vel = (Vector2)
    {
x:
        (float) 150 / FPS,
y:
        (float) 100 / FPS
    };
    Dog->bark = LoadSound("./Sons/Dog_bark.mp3");
}

Vector2 Dog_pos(dog Dog)
{
    return (Vector2)
    {
        Dog.rec.x, Dog.rec.y
    };
}

Vector2 cachorro_pos(dog cachorropos)
{
    return (Vector2)
    {
        cachorropos.rec.x = 200, cachorropos.rec.y = 200
    };
}

void Restaurar(dog *Dog)
{
    for(int i = 0; i < 3; i++)
    {
        UnloadTexture(Dog->textures[right][i]);
        UnloadTexture(Dog->textures[left][i]);
    }
    CloseAudioDevice();
}

void Draw(dog Dog, Rectangle Obstaculo)
{
    //BeginDrawing();
    ClearBackground(WHITE);
    DrawRectangleRec(Dog.rec, BLUE);
    DrawTextureEx(*Dog.texture, Dog_pos(Dog), 0, Dog.scale, WHITE);
    DrawRectangleRec(Obstaculo, RED);
    //EndDrawing();
}

void Anim_dog(dog *Dog)
{

    int i;
    i = (int)((GetTime() - Dog->start_walking)*4)%4;
    switch (i)
    {
    case 0:
        i = 0;
        break;
    case 1:
        i = 1;
        break;
    case 2:
        i = 0;
        break;
    case 3:
        i = 2;
        break;
    default:
        break;
    }
    if(Dog->side == left) Dog->texture = &Dog->textures[left][i];
    if(Dog->side == right) Dog->texture = &Dog->textures[right][i];

}

void MovingDog(dog *Dog,Rectangle Obstaculo)
{
    if(IsKeyUp(KEY_UP) && IsKeyUp(KEY_DOWN) && IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT))
    {
        if(Dog->side == left) Dog->texture = &Dog->textures[left][0];
        if(Dog->side == right) Dog->texture = &Dog->textures[right][0];
        Dog->start_walking = GetTime();
    }
    else
    {
        Anim_dog(Dog);
        if(IsKeyDown(KEY_UP))
        {
            Dog->rec.y -= Dog->vel.y;
        }
        while(CheckCollisionRecs(Dog->rec, Obstaculo))
        {
            Dog->rec.y++;
            Dog->rec.y = floor(Dog->rec.y);
        }
        if(IsKeyDown(KEY_DOWN))
        {
            Dog->rec.y += Dog->vel.y;
        }
        while(CheckCollisionRecs(Dog->rec, Obstaculo))
        {
            Dog->rec.y--;
            Dog->rec.y = ceil(Dog->rec.y);
        }
        if(IsKeyDown(KEY_LEFT))
        {
            Dog->rec.x -= Dog->vel.x;
            Dog->side = left;
        }
        while(CheckCollisionRecs(Dog->rec, Obstaculo))
        {
            Dog->rec.x++;
            Dog->rec.x = floor(Dog->rec.x);
        }
        if(IsKeyDown(KEY_RIGHT))
        {
            Dog->rec.x += Dog->vel.x;
            Dog->side = right;
        }
        while(CheckCollisionRecs(Dog->rec, Obstaculo))
        {
            Dog->rec.x--;
            Dog->rec.x = ceil(Dog->rec.x);
        }
    }
}

void BarkSound(dog Dog)
{
    if(IsKeyPressed(KEY_SPACE))
    {
        if(IsSoundPlaying(Dog.bark))
        {
            StopSound(Dog.bark);
        }
        PlaySound(Dog.bark);
    }
}

void AmbientSound(Sound Ambiente)
{
    if(!IsSoundPlaying(Ambiente))
    {
        PlaySound(Ambiente);
    }
}

void Prog(dog *Dog, Rectangle Obstaculo, Sound Ambiente)
{
    MovingDog(Dog, Obstaculo);
    BarkSound(*Dog);
    AmbientSound(Ambiente);
}

int main()
{
    SetupWindow();
    dog Dog;
    SetupDog(&Dog);
    int i=0;
    int t=0;
    Rectangle Obstaculo  = (Rectangle)
    {
        400, 400, 200, 200
    };

    //Texture2D cachorro = LoadTexture("./Texturas/cachorro.png");
    Texture2D cachorro[4]; //separa 4 slots para animação do cachorro
    char nome [40];
    for (i=1; i<4; i++)
    {
        sprintf(nome, "./Texturas/Dog%dL.png", i);
        cachorro[i] = LoadTexture(nome);
    }

    Sound Ambiente = LoadSound("./Sons/Farm.mp3");
    while(!WindowShouldClose())
    {
        // i+= 0.5;
        //Prog
        Prog(&Dog, Obstaculo, Ambiente);

        t = (int)(GetTime()*4)%4;//as imagens irão rodar em ordem 1->2->1->3 neutro->peD->neutro->peE
            switch (t)
        {
        case 0:
            t = 1;
            break;
        case 1:
            t = 2;
            break;
        case 2:
            t = 1;
            break;
        case 3:
            t = 3;
            break;
        default:
            break;
        }
        //Draw
        BeginDrawing();

        Draw(Dog, Obstaculo);

        //DrawTexture(cachorro[1],100,200,WHITE);   //imagem parada
        //DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);
        //DrawTextureEx(cachorro[0], (Vector2) {300,300}, 0, 5, WHITE);
        DrawTextureEx(cachorro[t], cachorro_pos(Dog), 0, 5, WHITE); //a cada loop passará para proxima imagem animando ela

        EndDrawing();
    }
    for(int i = 0; i < 3; i++)
    {
        UnloadTexture(cachorro[i]);
        UnloadTexture(cachorro[i]);
    }
    Restaurar(&Dog);
    CloseWindow();
    return 0;

}
