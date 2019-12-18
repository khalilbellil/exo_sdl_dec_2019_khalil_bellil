//
// Created by ASUS_BELLIL on 2019-04-18.
//

#ifndef EXOGAME_VECTOR_H
#define EXOGAME_VECTOR_H

#include <math.h>

class Vector{
private:

public:
    float x;
    float y;

    Vector() {}

    Vector(float x, float y) : x(x), y(y) {}


    float Lenght(){
        float a = sqrt((this->x * this->x) + (this->y * this->y));
        return a;
    }

    Vector Normalized(){
        return Vector(this->x/this->Lenght(),this->y/this->Lenght());
    }

    static float Distance(Vector v1, Vector v2){
        return Vector(v2.x - v1.x, v2.y - v1.y).Lenght();
    }

    static Vector Direction(Vector v1, Vector v2){
        Vector v = Vector(v2.x - v1.x, v2.y - v1.y);
        return  v.Normalized();
    }

};

#endif //EXOGAME_VECTOR_H
