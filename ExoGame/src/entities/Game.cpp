//
// Created by ASUS_BELLIL on 2019-04-18.
//

#include "Game.h"
using namespace std;

void Game::Init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        cout << "INFO: SDL initialized ..." << endl;

        this->win = SDL_CreateWindow(title,xPos,yPos,width,height, flags);
        if (this->win){
            cout << "INFO: WINDOW created..." << endl;
        }

        this->ren = SDL_CreateRenderer(this->win,-1,0);
        if (this->ren){
            SDL_SetRenderDrawColor(this->ren,255,255,255,255);
            cout << "INFO: RENDERER created..." << endl;
        }
        this->isRunning = true;
    } else{
        cout << "! ERROR ! : INITIALISATION failed !" << endl;
        this->isRunning = false;
    }

    SDL_Rect playerRect;
    playerRect.x = 50;
    playerRect.y = 50;
    playerRect.w = 32;
    playerRect.h = 32;
    SDL_Color playerColor;
    playerColor.r = 255 ;
    playerColor.g = 0 ;
    playerColor.b = 0 ;
    playerColor.a = 255 ;
    this->player = new GameObject("player", 2, playerRect, playerColor);

}

void Game::HandleEvents() {
    if (SDL_PollEvent(&this->evt) == 1)
    {
        if(this->evt.type == SDL_QUIT)
            this->isRunning = false;
        if(this->evt.type == SDL_MOUSEMOTION){
            this->mousePos.x = this->evt.motion.x;
            this->mousePos.y = this->evt.motion.y;
        }
        if(this->evt.type == SDL_MOUSEBUTTONDOWN){
            if(evt.button.button == SDL_BUTTON_LEFT){
                cout << "LEFT CLIC" << endl;
                player->MoveToPos(Vector(evt.motion.x, evt.motion.y));
            }
        }
        if (this->evt.type == SDL_KEYDOWN){
            if(this->evt.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                this->isRunning = false;
            if(this->evt.key.keysym.scancode == SDL_SCANCODE_W){
                this->player->Move("up");
            }
            if(this->evt.key.keysym.scancode == SDL_SCANCODE_A){
                this->player->Move("left");
            }
            if(this->evt.key.keysym.scancode == SDL_SCANCODE_S){
                this->player->Move("down");
            }
            if(this->evt.key.keysym.scancode == SDL_SCANCODE_D){
                this->player->Move("right");
            }
        }


    }
}

void Game::Update() {

    this->player->Update();

}

void Game::Render() {
    SDL_SetRenderDrawColor(this->ren,255,255,255,255);
    SDL_RenderClear(this->ren);

    //RENDER STUFF HERE...
    this->player->Render(this->ren);

    SDL_RenderPresent(this->ren);
}

void Game::Clean() {
    SDL_DestroyRenderer(this->ren);
    SDL_DestroyWindow(this->win);
    SDL_Quit();
}