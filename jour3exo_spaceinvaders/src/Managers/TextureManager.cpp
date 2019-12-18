//
// Created by ASUS_BELLIL on 2019-04-15.
//
#include "TextureManager.h"

SDL_Texture* TextureManager::LoadtTexture(const char* fileName) {
    SDL_Surface* tempSurface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::ren, tempSurface);
    SDL_FreeSurface(tempSurface);

    return texture;
}
