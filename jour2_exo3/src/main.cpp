#include <iostream>
#include "SDL2/SDL.h"
#include "vector"
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "SDL2/SDL_image.h"
using namespace std;
const int WIDTH = 800;
const int HEIGHT = 600;

void DrawPoint(int _x, int _y, int _size, SDL_Renderer* _renderer, SDL_Color _color){
    SDL_SetRenderDrawColor(_renderer, _color.r, _color.g, _color.b, _color.a);

    SDL_Rect rect;

    rect.x = _x - _size / 2;
    rect.y = _y - _size / 2;
    rect.w = _size;
    rect.h = _size;

    SDL_RenderFillRect(_renderer, &rect);
}

void DrawRect(int _x, int _y, int _width, int _height, SDL_Renderer* _renderer, SDL_Color _color){
    SDL_SetRenderDrawColor(_renderer, _color.r, _color.g, _color.b, _color.a);

    SDL_Rect rect;

    rect.x = _x;
    rect.y = _y;
    rect.w = _width;
    rect.h = _height;

    SDL_RenderFillRect(_renderer, &rect);
}

void Draw(SDL_Renderer* _renderer){
    //Afficher l'image:


    //Afficher le carré pour la loupe:


    //Afficher le contenue zoomé dans la loupe:


    SDL_RenderPresent(_renderer);//mise a jour de la vue
    SDL_Delay(15);
};

void Clear(SDL_Renderer *_renderer){
    //effacer
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderClear(_renderer);
}

void LoadImg(const char* path){
    SDL_Surface *image;
    image = IMG_Load(path);
    if(!image) {
        printf("IMG_Load: %s\n", IMG_GetError());
    }
}

int main(int argc, char **argv) {
    //region VARIABLES:
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

    //region SDL_Image INITIALISATION :
    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int initted = IMG_Init(flags);
    if ((initted & flags) != flags) { // handle error
        printf("IMG_Init: Failed to init required jpg and png support!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
    }
    //endregion

    LoadImg("/assets/image.png");

    int x1 = 0;
    int y1 = 0;

    //region GAME LOOP:
    while (!end)
    {
        Clear(renderer);

        SDL_Event event;
        while(SDL_PollEvent(&event)) // check to see if an event has happened
        {
            switch (event.type) {
                case SDL_QUIT:
                    end = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    x1 = event.motion.x;
                    y1 = event.motion.y;
                //case SDL_MOUSEBUTTONUP:
            }
        }

        //Draw(renderer);

    }
    //endregion

    //region SDL QUIT:
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    //endregion
    return 0;
}