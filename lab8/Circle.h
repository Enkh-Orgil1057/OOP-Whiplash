#ifndef CIRCLE_H
#define CIRCLE_H
#include "TwoDShape.h"
#include <iostream>
#include <string>

using namespace std;

class Circle : public TwoDShape
{
    public:
        Circle();
        Circle(string, float, float, float);
        float findPerimeter();
        float findArea();
        void print();
        void setter(string, float, float, float);

    private:
        void updateCoor(float, float);
};
#endif