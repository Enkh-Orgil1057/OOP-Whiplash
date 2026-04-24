#ifndef CIRCLE_H
#define CIRCLE_H
#include "TwoDShape.h"
#include <iostream>
#include <string>

using namespace std;

class Circle : public TwoDShape
{
    public:
        Circle(){
            coordinate = new float[2];
        };

        Circle(string, float, float x, float y){
            coordinate = new float[2];
            coordinate[0] = x;
            coordinate[1] = y;
        };
        float findPerimeter();
        float findArea();
        float* get_center();
};
#endif