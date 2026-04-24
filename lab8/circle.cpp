#include "Circle.h"
#define PI 3.14
using namespace std;

void Circle :: updateCoor(float x, float y)
{
    coordinate[0] = x;
    coordinate[1] = y;
}
//anhdagch baiguulagch ni coordinate-nd zoriulj shine husnegt nuutslunu
Circle :: Circle() : TwoDShape()
{
    coordinate = new float[2]{0};
};
/*
parametertei baiguulagc ni mun sanah oig nuutslunu
"name" bolon "negj" 2 iig TwoDShape iin baiguulagch ruu damjuulna
coordinate-daa x, y utguudaa onooj ugnu.
*/
Circle :: Circle(string name, float negj, float x, float y) : TwoDShape(name, negj)
{
    coordinate = new float[2];
    updateCoor(x, y);
};

void Circle :: setter(string n, float negj, float x, float y)
{
    name = n;
    negj_utga = negj;
    updateCoor(x, y);
}

float Circle :: findPerimeter()
{
    return (2 * negj_utga * PI);
}

float Circle :: findArea()  
{
    return (negj_utga * negj_utga) * PI;
}

void Circle :: print() 
{
    cout<< "negj_utga = " << negj_utga << endl;
    cout<< "Tuv tseg = " << coordinate[0] << ", "<< coordinate[1] << endl; 
}