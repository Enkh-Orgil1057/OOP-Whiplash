#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "TwoDShape.h"
#include <iostream>
#include <string>

using namespace std;

class Triangle : public TwoDShape
{
    protected:
        float dood_baruun[2]; // bottom-right
        float dood_zvvn[2]; //bottom-left
    public:
        Triangle();
        Triangle(string, float, float, float);
        float findPerimeter();
        float findArea();
        float* get_dood_baruun();
        float* get_dood_zvvn();
};
#endif