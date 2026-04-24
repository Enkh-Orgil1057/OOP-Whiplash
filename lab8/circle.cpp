#include "Circle.h"
#define PI 3.14
using namespace std;
//anhdagch baiguulagch ni coordinate-nd zoriulj shine husnegt nuutslunu
Circle :: Circle() : TwoDShape()
{
    coordinate = new float[2];
    coordinate[0] = 0; 
    coordinate[1] = 0; 
};
/*
parametertei baiguulagc ni mun sanah oig nuutslunu
"name" bolon "negj" 2 iig TwoDShape iin baiguulagch ruu damjuulna
coordinate-daa x, y utguudaa onooj ugnu.
*/
Circle :: Circle(string name, float negj, float x, float y) : TwoDShape(name, negj)
{
    coordinate = new float[2];
    coordinate[0] = x;
    coordinate[1] = y;
};

float Circle :: findPerimeter()
{
    return (2 * negj_utga * PI);
}

float Circle :: findArea()  {
    return (negj_utga * negj_utga) * PI;
}
