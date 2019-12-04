#include <iostream>
#include "SDL2/SDL.h"
#include "vector"
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
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

void Draw(SDL_Renderer* _renderer, vector<Point*> _points){
    DrawRect(0,0,WIDTH/10, HEIGHT, _renderer, { 211, 211, 211, 255 });
    DrawRect((WIDTH/10)/3, HEIGHT/16, (WIDTH/10)/3, (WIDTH/10)/3, _renderer, {255,0,0,255});
    DrawRect((WIDTH/10)/3, (HEIGHT/16) * 2, (WIDTH/10)/3, (WIDTH/10)/3, _renderer, {0,0,255,255});
    DrawRect((WIDTH/10)/3, (HEIGHT/16) * 3, (WIDTH/10)/3, (WIDTH/10)/3, _renderer, {0,255,0,255});
    DrawRect((WIDTH/10)/3, (HEIGHT/16) * 4, (WIDTH/10)/3, (WIDTH/10)/3, _renderer, {0,255,255,255});

    for (int i = 0; i < _points.size(); ++i) {
        SDL_RenderDrawLine(_renderer, _points[i]->x, _points[i]->y, _points[i]->x2, _points[i]->y2);
    }

    SDL_RenderPresent(_renderer);//mise a jour de la vue
    SDL_Delay(15);
};

void Clear(SDL_Renderer *_renderer){
    //effacer
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderClear(_renderer);
}

int main(int argc, char **argv) {
    //region VARIABLES:
    bool end = false;
    vector<Point*> points;
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
                case SDL_MOUSEBUTTONDOWN: // if the event is mouse click , event.motion.x >= 100
                    x1 = event.motion.x;
                    y1 = event.motion.y;
                case SDL_MOUSEBUTTONUP: // if the event is mouse click , event.motion.x >= 100
                    points.push_back(new Point(x1, y1, event.motion.x, event.motion.y, {255,0,0,255}));
            }
        }
        Draw(renderer, points);

    }
    //endregion

    //region SDL QUIT:
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    //endregion
    return 0;
}