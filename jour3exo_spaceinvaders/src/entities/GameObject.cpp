//
// Created by ASUS_BELLIL on 2019-04-15.
//
#include "GameObject.h"
#include "../Managers/TextureManager.h"
#include "../utils/Utils.h"
#include "Laser.h"

GameObject::GameObject(const char *texturesheet, int _xPos, int _yPos, bool _isEnemy, bool _isActive) {
    GameObject::objTexture = TextureManager::LoadtTexture(texturesheet);
    xPos = _xPos;
    yPos = _yPos;
    isEnemy = _isEnemy;
    isActive = _isActive;
}

void GameObject::Update() {
    if (isActive){
    srcRect.h = 50;
    srcRect.w = 50;
    srcRect.x = 0;
    srcRect.y = 0;

    dstRect.x = xPos;
    dstRect.y = yPos;
    dstRect.w = srcRect.w + 14;
    dstRect.h = srcRect.h + 14;

    if (isEnemy){
        yPos += 1;
    }
    }

}

void GameObject::Render() {
    if (isActive)
    SDL_RenderCopy(Game::ren,GameObject::objTexture,&(GameObject::srcRect),&(GameObject::dstRect));
}

//GETTER AND SETTER
int GameObject::getXPos() const {
    return xPos;
}

void GameObject::setXPos(int xPos) {
    GameObject::xPos = xPos;
}

int GameObject::getYPos() const {
    return yPos;
}

void GameObject::setYPos(int yPos) {
    GameObject::yPos = yPos;
}

SDL_Texture *GameObject::getObjTexture() const {
    return objTexture;
}

void GameObject::setObjTexture(SDL_Texture *objTexture) {
    GameObject::objTexture = objTexture;
}

const SDL_Rect &GameObject::getSrcRect() const {
    return srcRect;
}

void GameObject::setSrcRect(const SDL_Rect &srcRect) {
    GameObject::srcRect = srcRect;
}

const SDL_Rect &GameObject::getDstRect() const {
    return dstRect;
}

void GameObject::setDstRect(const SDL_Rect &dstRect) {
    GameObject::dstRect = dstRect;
}

bool GameObject::isIsEnemy() const {
    return isEnemy;
}

void GameObject::setIsEnemy(bool isEnemy) {
    GameObject::isEnemy = isEnemy;
}

bool GameObject::isIsActive() const {
    return isActive;
}

void GameObject::setIsActive(bool isActive) {
    GameObject::isActive = isActive;
}
