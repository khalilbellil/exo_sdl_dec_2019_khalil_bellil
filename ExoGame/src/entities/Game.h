//
// Created by ASUS_BELLIL on 2019-04-18.
//

#ifndef EXOGAME_GAME_H
#define EXOGAME_GAME_H

#include <iostream>
#include "SDL2/SDL.h"
#include "GameObject.h"

class Game{
private:
    bool isRunning;
    SDL_Window *win;
    SDL_Renderer *ren;
    SDL_Event evt;

    GameObject* player;

    Vector mousePos;

public:
    Game(){}
    virtual ~Game(){}
    void Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();
    bool running(){return isRunning;};

};

#endif //EXOGAME_GAME_H
