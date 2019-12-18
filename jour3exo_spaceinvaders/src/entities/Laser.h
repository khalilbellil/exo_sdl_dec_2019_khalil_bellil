//
// Created by ASUS_BELLIL on 2019-04-16.
//

#ifndef JOUR3EXO_SPACEINVADERS_LASER_H
#define JOUR3EXO_SPACEINVADERS_LASER_H

#include "../utils/Utils.h"

class Laser{
public:
    Laser(GameObject* player) {
        posX = player->getXPos();
        posY = player->getXPos();
    }

    virtual ~Laser() {}

    void Update(){
        if(isActive){
            laserRect.w = 10;
            laserRect.h = 30;
            laserRect.x = posX;
            laserRect.y = posY;
            posY --;

            if (posY <= 5){
                isActive = false;
            }
        }
    }
    void Render(){
        if (isActive)
            SDL_SetRenderDrawColor(Game::ren,255,255,255,255);
            SDL_RenderFillRect(Game::ren, &laserRect);
            SDL_SetRenderDrawColor(Game::ren,0,0,0,255);
    }


//GETTER AND SETTER
    int getPosX() const {
        return posX;
    }

    void setPosX(int posX) {
        Laser::posX = posX;
    }

    int getPosY() const {
        return posY;
    }

    void setPosY(int posY) {
        Laser::posY = posY;
    }

    bool isIsActive() const {
        return isActive;
    }

    void setIsActive(bool isActive) {
        Laser::isActive = isActive;
    }

    const SDL_Rect &getLaserRect() const {
        return laserRect;
    }

    void setLaserRect(const SDL_Rect &laserRect) {
        Laser::laserRect = laserRect;
    }

private:
    int posX;
    int posY;
    bool isActive;
    SDL_Rect laserRect;

};

#endif //JOUR3EXO_SPACEINVADERS_LASER_H
