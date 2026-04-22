#ifndef TWODSHAPE_H
#define TWODSHAPE_H

#include "Shape.h"
#include <iostream>
#include <string>

using namespace std;

class TwoDShape : public Shape {
    protected:
        float negj_utga;
        float default_coor[2];
    public:
        void setter(string, float, float, float);
        float get_negj_utga();
        virtual float findPerimeter() = 0;
        virtual float findArea() = 0;
        TwoDShape();
        TwoDShape(string, float, float, float);
};
#endif