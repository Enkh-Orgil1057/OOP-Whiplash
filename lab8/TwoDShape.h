#ifndef TWODSHAPE_H
#define TWODSHAPE_H

#include "Shape.h"
#include <iostream>
#include <string>

using namespace std;

class TwoDShape : public Shape {
    protected:
        float negj_utga;
        float* coordinate;
    public:
        void setter(string, float, float, float);
        float get_negj_utga();
        float* get_coordinate();

        virtual float findPerimeter() = 0;
        virtual float findArea() = 0;

        ~TwoDShape();
        TwoDShape();
        TwoDShape(string, float);
};
#endif

