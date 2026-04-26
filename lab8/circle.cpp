#include "Circle.h"
#define PI 3.14
using namespace std;

void Circle :: updateCoor(float x, float y)
{
    this->coordinate[0] = x;
    this->coordinate[1] = y;
}
//anhdagch baiguulagch ni coordinate-nd zoriulj shine husnegt nuutslunu
Circle :: Circle() : TwoDShape()
{
    this->coordinate = new float[2]{0};
};
/*
parametertei baiguulagc ni mun sanah oig nuutslunu
"name" bolon "negj" 2 iig TwoDShape iin baiguulagch ruu damjuulna
coordinate-daa x, y utguudaa onooj ugnu.
*/
Circle :: Circle(string name, float negj, float x, float y) : TwoDShape(name, negj)
{
    this->coordinate = new float[2];
    this->updateCoor(x, y);
};

void Circle :: setter(string n, float negj, float x, float y)
{
    this->name = n;
    this->negj_utga = negj;
    this->updateCoor(x, y);
}

float Circle :: findPerimeter()
{
    return (2 * (this->negj_utga) * PI);
}

float Circle :: findArea()  
{
    return ((this->negj_utga) * (this->negj_utga)) * PI;
}

void Circle :: print() 
{
    cout<< "negj_utga = " << this->negj_utga << endl;
    cout<< "Tuv tseg = " << this->coordinate[0] << ", "<< this->coordinate[1] << endl; 
}