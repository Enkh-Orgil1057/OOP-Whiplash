#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "TwoDShape.h"
#include <iostream>
#include <string>

using namespace std;

class Triangle : public TwoDShape
{
    public:
        Triangle();
        Triangle(string, float, float, float);
        float findPerimeter();
        float findArea();
        void setter(string, float, float, float);
        void print();

    private:
        void updateCoor(float, float, float);
};
#endif