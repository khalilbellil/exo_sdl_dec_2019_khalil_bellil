#include <iostream>
#include "SDL2/SDL.h"
#include "vector"
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char **argv) {
    //region VARIABLES:
    const int WIDTH = 500;
    const int HEIGHT = 500;
    bool end = false;
    //endregion

    //region SDL INITIALISATION :
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }
    SDL_Window* window;
    SDL_Renderer* renderer;
    if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer) != 0) {
        SDL_Log("Unable to create window and renderer SDL: %s", SDL_GetError());
        return 2;
    }
    SDL_SetWindowPosition(window, 500, 150);
    //endregion

    int colNb = 5;
    int rowNb = 5;

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = WIDTH/colNb;
    rect.h = HEIGHT/rowNb;

    vector<int> characters(30);

    bool goToLine = false;

    ifstream fichier("draw.data", ifstream::in);
    
    char c = fichier.get();
    for (int i = 0; i < ((colNb*rowNb) + 4); ++i) {
        characters[i] = c;
        if(characters[i] == 10){
            goToLine = true;
        }
        else if (characters[i] == 48){//0
            if(i == 0){
                SDL_SetRenderDrawColor(renderer, 255,255,255,255);
                SDL_RenderFillRect(renderer, &rect);
                SDL_RenderPresent(renderer);
            }else{
            if(goToLine){
                rect.y += HEIGHT/rowNb;
                rect.x = 0;
                goToLine = false;
            }else{
                rect.x += WIDTH/colNb;
            }
                SDL_SetRenderDrawColor(renderer, 255,255,255,255);
                SDL_RenderFillRect(renderer, &rect);
                SDL_RenderPresent(renderer);
            }

        }
        else if (characters[i] == 49){//1
            if(i == 0){
                SDL_SetRenderDrawColor(renderer, 0,0,0,255);
                SDL_RenderFillRect(renderer, &rect);
                SDL_RenderPresent(renderer);
            }else {
                if (goToLine) {
                    rect.y += HEIGHT / rowNb;
                    rect.x = 0;
                    goToLine = false;
                } else {
                    rect.x += WIDTH / colNb;
                }
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
                SDL_RenderPresent(renderer);
            }
        }
        c = fichier.get();
    }


    fichier.close();

    //region GAME LOOP:
    while (!end)
    {
        SDL_Event evt;
        if (SDL_PollEvent(&evt) == 1)
        {
            if (evt.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                end = true;
        }
    }
    //endregion

    //region SDL QUIT:
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    //endregion
    return 0;
}