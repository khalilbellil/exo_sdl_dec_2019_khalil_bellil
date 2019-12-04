#ifndef JOUR1_EXO2_IMAGE_H
#define JOUR1_EXO2_IMAGE_H
#include <iostream>
class Image{
private:
    int id;
    std::string name;

public:
    Image(){
        id = 0;
        name = "no name";
    }
    Image(int _id, std::string _name){
        if(_id >= 0 && _name != "" || _name != " "){
            id = _id;
            name = _name;
        }
        else{
            std::cout << "ERROR: Wrong id and/or name !";
        }
    }

    std::string GetName(){
        return name;
    }

    int GetId(){
        return id;
    }
    void SetId(int _id){
        id = _id;
    }
    void SetName(std::string _name){
        name = _name;
    }
};

#endif //JOUR1_EXO2_IMAGE_H
