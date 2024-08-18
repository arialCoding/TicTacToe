#pragma once

#include <SDL2/SDL.h>

class Engine
{
public:

    static Engine& Get(){
        return instance;
    }

    bool Init(int w, int h, const char* title);
    void HandleEvents();
    void ClearScreen();
    void Draw(SDL_Texture* tex, SDL_Rect* src, SDL_Rect* dest);
    void Present();

    bool isRunning() { return running; }

private:
    Engine() {}

    static Engine instance;

    SDL_Renderer* renderer;
    SDL_Window* window;

    SDL_Event event;

    bool running = false;

};
