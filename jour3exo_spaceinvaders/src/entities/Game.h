//
// Created by ASUS_BELLIL on 2019-04-15.
//

#ifndef JOUR3EXO_SPACEINVADERS_GAME_H
#define JOUR3EXO_SPACEINVADERS_GAME_H

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"


class Game{
public:
    Game();
    virtual ~Game();
    void Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();
    bool running(){return isRunning;};

    static SDL_Renderer *ren;

private:
    bool isRunning;
    SDL_Window *win;

    int frames;
};

#endif //JOUR3EXO_SPACEINVADERS_GAME_H
