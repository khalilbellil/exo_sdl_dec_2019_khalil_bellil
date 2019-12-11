#ifndef JOUR2_EXO3_POINT_H
#define JOUR2_EXO3_POINT_H

#include <iostream>
#include "SDL2/SDL.h"
#include "vector"
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

class Point{
public:
    int x;
    int y;
    int x2;
    int y2;
    SDL_Color color{};

    Point(){
        x = 0;
        y = 0;
        x2 = 0;
        y2 = 0;
        color = {255,255,255,255};
    }

    Point(int _x, int _y, int _x2, int _y2, SDL_Color _color){
        x = _x;
        y = _y;
        x2 = _x2;
        y2 = _y2;
        color = _color;
    }
};

#endif //JOUR2_EXO3_POINT_H
