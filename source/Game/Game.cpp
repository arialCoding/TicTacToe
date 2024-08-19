#include "Game.hpp"

int Run()
{
    if(!Engine::Get().Init(640, 640, "TicTacToe"))
    {
        printf("program failed!\n");
        return -1;
    }

    init();

    while(Engine::Get().isRunning())
    {
        Engine::Get().HandleEvents();

        update(0.f);

        Engine::Get().ClearScreen();

        render();

        Engine::Get().Present();

    }

    return 0;
}

void init()
{

}

void update(float dt)
{


}

void render()
{

}