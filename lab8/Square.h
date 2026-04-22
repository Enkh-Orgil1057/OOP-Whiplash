#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include "TwoDShape.h"
#include <iostream>
#include <string>

//--------------------------------------------------------
//--------------------SQUARE CLASS------------------------
//--------------------------------------------------------
// Квадрат хэмээх классыг TwoDShape функцээс удамшуулав
// Square класс
class Square : TwoDShape {
protected:
    float deed_baruun[2]; //top-right#include <iostream>
    float dood_baruun[2]; // bottom-right
    float dood_zvvn[2]; //bottom-left

public:
        
    //parametertei baiguulagch
    Square(string n, float negj, float x, float y);
    // setter
    void setter(float t, float x, float y);

    // Талбай
    float findArea();

    // Периметр
    float findPerimeter();

    // Бүх мэдээлэл хэвлэх
    void print();

    //oroinuudiig coordinatruudig butsaah funcitonuud
    float* get_deed_zvvn(){ return default_coor;}
    float* get_dood_zvvn(){ return dood_zvvn;}
    float* get_deed_baruun(){ return deed_baruun;}
    float* get_dood_baruun(){ return dood_baruun;}
}
;
#endif