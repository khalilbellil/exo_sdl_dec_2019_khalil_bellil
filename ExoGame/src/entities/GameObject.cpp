//
// Created by ASUS_BELLIL on 2019-04-18.
//
#include "GameObject.h"

void GameObject::Move(std::string direction){
    if(direction == "up"){
        this->position.y -= this->speed;
    }
    if(direction == "down"){
        this->position.y += this->speed;
    }
    if(direction == "left"){
        this->position.x -= this->speed;
    }
    if(direction == "right"){
        this->position.x += this->speed;
    }
}

void GameObject::MoveToPos(Vector pos){
    this->destination = pos;
    Vector dir = Vector::Direction(this->position, pos);
    this->direction = dir;
    this->moving = true;
}

void GameObject::Update() {
    this->rect.x = this->position.x;
    this->rect.y = this->position.y;
    this->rect.w = 32 ;
    this->rect.h = 32 ;

    if(this->moving) {


        if (this->direction.x > 0)
            this->position.x += this->speed;
        if (this->direction.x < 0)
            this->position.x -= this->speed;
        if (this->direction.y > 0)
            this->position.y += this->speed;
        if (this->direction.y < 0)
            this->position.y -= this->speed;
    }

    if (this->position.x >= this->destination.x && this->position.y >= this->destination.y){
        this->moving = false;
    }
}

void GameObject::Render(SDL_Renderer* renderer) {
    int r = this->color.r;
    int g = this->color.g;
    int b = this->color.b;
    int a = this->color.a;
    SDL_SetRenderDrawColor(renderer,r,g,b,a);
    SDL_RenderFillRect(renderer, &(this->rect));
}

void GameObject::Clean() {

}
