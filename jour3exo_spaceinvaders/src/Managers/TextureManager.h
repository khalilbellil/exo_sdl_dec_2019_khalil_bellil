//
// Created by ASUS_BELLIL on 2019-04-15.
//

#ifndef JOUR3EXO_SPACEINVADERS_TEXTUREMANAGER_H
#define JOUR3EXO_SPACEINVADERS_TEXTUREMANAGER_H

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../entities/Game.h"

class TextureManager{
public:
    static SDL_Texture* LoadtTexture(const char* fileName);
};

#endif //JOUR3EXO_SPACEINVADERS_TEXTUREMANAGER_H
