#include "Engine.hpp"
#include <cstdio>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

Engine Engine::instance;

bool Engine::Init(int w, int h, const char* title)
{
    if(SDL_Init(SDL_INIT_EVERYTHING))
    {
        printf("failed to init SDL. Err: %s\n", SDL_GetError());
        return false;
    }
    if(!IMG_Init(IMG_INIT_PNG))
    {
        printf("failed to init SDL_image. Err: %s\n", SDL_GetError());
        return false;
    }
    if(TTF_Init())
    {
        printf("failed to init SDL_ttf. Err: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow(title, 300, 300, w, h, SDL_WINDOW_RESIZABLE);
    if(!window)
    {
        printf("failed to Create window. Err: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer)
    {
        printf("failed to Create renderer. Err: %s\n", SDL_GetError());
        return false;
    }

    running = true;

    return true;
}

void Engine::HandleEvents()
{
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                running = false;
                break;
            default:
                break;
        }
    }
}

void Engine::ClearScreen()
{
    SDL_RenderClear(renderer);
}

void Engine::Draw(SDL_Texture* tex, SDL_Rect* src, SDL_Rect* dest)
{
    SDL_RenderCopy(renderer, tex, src, dest);
}

void Engine::Present()
{
    SDL_RenderPresent(renderer);
}