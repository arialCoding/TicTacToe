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

SDL_Texture* boardTex;
SDL_Texture* X_O_Tex;

enum Cell{
    EMPTY,
    X,
    O
};

Cell board[3][3];

Cell currentTurn, nextTurn;

bool playing;

int plays;

void reset()
{
    system("cls");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = EMPTY;
        }
    }

    currentTurn = X;
    nextTurn = O;

    plays = 0;
    playing = true;
}

void init()
{
    boardTex = Engine::Get().loadTexture("resource/board.png");
    X_O_Tex = Engine::Get().loadTexture("resource/X_O.png");

    reset();
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentTurn && board[i][1] == currentTurn && board[i][2] == currentTurn) {
            return true;
        }
        if (board[0][i] == currentTurn && board[1][i] == currentTurn && board[2][i] == currentTurn) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == currentTurn && board[1][1] == currentTurn && board[2][2] == currentTurn) {
        return true;
    }
    if (board[0][2] == currentTurn && board[1][1] == currentTurn && board[2][0] == currentTurn) {
        return true;
    }

    return false;
}

void update(float dt)
{
    if(Engine::Get().getInput()[SDL_SCANCODE_ESCAPE].pressed)
        Engine::Get().Quit();

    if(Engine::Get().getInput()[SDL_SCANCODE_R].pressed)
        reset();

    if(Engine::Get().getMouseState().LMBpressed && playing)
    {
        int row = Engine::Get().getMouseState().y / 200;
        int col = Engine::Get().getMouseState().x / 200;
        if(board[row][col] == EMPTY)
        {
            board[row][col] = currentTurn;
            plays++;

            if(checkWin())
            {
                printf("player %i won!\n");
                playing = false;
            }
            else if(plays == 9)
            {
                printf("draw!\n");
            }
            else{    
                Cell temp = currentTurn;
                currentTurn = nextTurn;
                nextTurn = temp;
            }
        }
    }



}

void render()
{
    Engine::Get().Draw(boardTex, NULL, NULL);

    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            if(board[row][col] != EMPTY)
            {
                SDL_Rect src = {
                    .x = (board[row][col] - 1)*32,
                    .y = 0,
                    .w = 32,
                    .h = 32
                };
                SDL_Rect dest = {
                    .x = col*220,
                    .y = row*220,
                    .w = 200,
                    .h = 200
                };
                Engine::Get().Draw(X_O_Tex, &src, &dest);
            }
        }
    }
}