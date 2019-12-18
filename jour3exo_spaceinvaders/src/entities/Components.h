//
// Created by ASUS_BELLIL on 2019-04-16.
//

#ifndef JOUR3EXO_SPACEINVADERS_COMPONENTS_H
#define JOUR3EXO_SPACEINVADERS_COMPONENTS_H

#include "ECS.h"

class PositionComponent : public Component{
private:
    int xPos, yPos;

public:
     int GetX(){return xPos; }
     int GetY(){return yPos; }

     void Init() override{
         xPos = 0;
         yPos = 0;
     }

     void Update() override{
         xPos++;
         yPos++;
     }

     void setPos(int x, int y){
         xPos = x;
         yPos = y;
     }

};

#endif //JOUR3EXO_SPACEINVADERS_COMPONENTS_H
