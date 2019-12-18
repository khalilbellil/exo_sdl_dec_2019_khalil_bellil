#include <iostream>
#include "entities/Game.h"
#include "entities/GameObject.h"

int main(int argc, char **argv) {
    //region VARIABLES:
    static const int FPS = 60;
    static const int frameDelay = 1000 / FPS;
    Uint32  frameStart;
    int frameTime;

    const int WIDTH = 800;
    const int HEIGHT = 600;
    bool end = false;

    Game *game;
    game = new Game();
    //endregion

    game->Init("ExoGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,WIDTH, HEIGHT, false);

    //region GAME LOOP:
    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game->HandleEvents();
        game->Update();
        game->Render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
    //endregion

    game->Clean();

    return 0;
}