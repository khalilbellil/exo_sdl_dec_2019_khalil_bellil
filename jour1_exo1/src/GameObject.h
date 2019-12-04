#ifndef JOUR1_EXO1_GAMEOBJECT_H
#define JOUR1_EXO1_GAMEOBJECT_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class GameObject{
    int x,y;

public:
    GameObject(){

    }

    GameObject(int x, int y) : x(x), y(y) {}

    int getX() const {
        return x;
    }

    void setX(int x) {
        GameObject::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        GameObject::y = y;
    }
    string ToString(){
        string s;
        s = "$";
        s += to_string(this->x);
        s += "," + to_string(this->y);
        return s;
    }
};

#endif //JOUR1_EXO1_GAMEOBJECT_H
