#ifndef JOUR3EXO_SPACEINVADERS_UTILS_H
#define JOUR3EXO_SPACEINVADERS_UTILS_H

#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "SDL2/SDL.h"
#include "../entities/GameObject.h"

class Utils {

public:
    static const int WIDTH = 800;
    static const int HEIGHT = 600;
    static int generateRandomFloat();
    static bool Collision(SDL_Rect A, SDL_Rect B);
};

#endif //JOUR3EXO_SPACEINVADERS_UTILS_H
