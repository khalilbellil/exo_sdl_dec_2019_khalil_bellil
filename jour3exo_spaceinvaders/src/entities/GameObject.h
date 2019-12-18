//
// Created by ASUS_BELLIL on 2019-04-15.
//

#ifndef JOUR3EXO_SPACEINVADERS_GAMEOBJECT_H
#define JOUR3EXO_SPACEINVADERS_GAMEOBJECT_H

#include "Game.h"
#include "../utils/Utils.h"

class GameObject{

public:

    GameObject(const char* texturesheet, int _xPos, int _yPos, bool isEnemy, bool isActive);
    ~GameObject();

    void Update();
    void Render();

    void Shoot();

    //GETTER AND SETTER
    int getXPos() const;

    void setXPos(int xPos);

    int getYPos() const;

    void setYPos(int yPos);

    SDL_Texture *getObjTexture() const;

    void setObjTexture(SDL_Texture *objTexture);

    const SDL_Rect &getSrcRect() const;

    void setSrcRect(const SDL_Rect &srcRect);

    const SDL_Rect &getDstRect() const;

    void setDstRect(const SDL_Rect &dstRect);

    bool isIsEnemy() const;

    void setIsEnemy(bool isEnemy);

    bool isIsActive() const;

    void setIsActive(bool isActive);

private:

    int xPos;
    int yPos;
    bool isEnemy;
    bool isActive;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, dstRect;
};

#endif //JOUR3EXO_SPACEINVADERS_GAMEOBJECT_H
