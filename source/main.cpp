#include "Engine.hpp"
#include <cstdio>

int main(int argc, char* agrv[]){

    if(!Engine::Get().Init(640, 640, "TicTacToe"))
    {
        printf("program failed!\n");
        return -1;
    }

    while(Engine::Get().isRunning())
    {
        Engine::Get().HandleEvents();

        Engine::Get().ClearScreen();


        Engine::Get().Present();

    }

    return 0;
}
