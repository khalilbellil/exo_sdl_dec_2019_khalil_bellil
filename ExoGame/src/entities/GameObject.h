//
// Created by ASUS_BELLIL on 2019-04-18.
//

#ifndef EXOGAME_GAMEOBJECT_H
#define EXOGAME_GAMEOBJECT_H

#include <iostream>
#include "SDL2/SDL.h"
#include "../utils/Vector.h"

class GameObject{
private:
    std::string name;
    Vector position;
    int speed;
    SDL_Rect rect;
    SDL_Color color;
    bool moving;
    Vector direction;
    Vector destination;
public:
    GameObject(){}
    GameObject(const std::string &name, int speed, const SDL_Rect &rect, const SDL_Color &color) {
        this->name = name;
        this->speed = speed;
        this->rect = rect;
        this->color = color;

        this->position.x = rect.x;
        this->position.y = rect.y;
    }
    virtual ~GameObject(){}

    void Move(std::string direction);
    void MoveToPos(Vector pos);
    void Update();
    void Render(SDL_Renderer* renderer);
    void Clean();

    //GETTER SETTER
    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        GameObject::name = name;
    }

    int getSpeed() const {
        return speed;
    }

    void setSpeed(int speed) {
        GameObject::speed = speed;
    }

    const SDL_Rect &getRect() const {
        return rect;
    }

    void setRect(const SDL_Rect &rect) {
        GameObject::rect = rect;
    }

    const SDL_Color &getColor() const {
        return color;
    }

    void setColor(const SDL_Color &color) {
        GameObject::color = color;
    }
};

#endif //EXOGAME_GAMEOBJECT_H
