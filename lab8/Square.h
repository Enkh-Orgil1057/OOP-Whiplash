#ifndef SQUARE_H
#define SQUARE_H

#include "TwoDShape.h"
#include <iostream>
#include <string>

class Square : TwoDShape {
    public:
        Square();
        //parametertei baiguulagch
        Square(string, float, float, float );
        // setter
        void setter(string, float, float, float);
        // Талбай
        float findArea();
        // Периметр
        float findPerimeter();
        // Бүх мэдээлэл хэвлэх
        void print();

    private:
        void updateCoor(float, float, float);
}
;
#endif