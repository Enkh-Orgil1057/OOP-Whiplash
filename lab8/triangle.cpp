#include <iostream>
#include <cmath>
#include <iomanip>
//zuvhun uuriin classiig duudahad bolno~
//COMMENT = GETTER FUNCITONUUDIIG USTGASAN. gants TwoDshapes-iin getter() eer coordinate husnegtiig butsaana.
#include "Triangle.h"

using namespace std;

void Triangle :: updateCoor(float negj, float x, float y)
{
    this->coordinate[0] = x; //oroi x
    this->coordinate[1] = y; //oroi y
    this->coordinate[2] = x -(negj/2.0); // зүүн доод x
    this->coordinate[3] = y -(negj*sqrt(3.0)/2.0); // зүүн доод y
    this->coordinate[4] = x +(negj/2.0); // баруун доод x
    this->coordinate[5] = y -(negj*sqrt(3.0)/2.0); // баруун доод y
}
// Анхдагч байгуулагч
Triangle :: Triangle() : TwoDShape()
{
    this->coordinate = new float[6]{0};
}
//параметртэй байгуулагч
Triangle :: Triangle(string n, float negj, float x, float y) : TwoDShape(n ,negj) 
{
    this->coordinate = new float[6];
    this->updateCoor(negj, x, y);
}

//гараас талын урт, нэр болон дээд цэгийн координатыг авах 
void Triangle :: setter(string n, float negj, float x, float y)
{
    this->negj_utga = negj;
    this->name = n;
    this->updateCoor(negj, x, y);
}

// координатын утгуудыг хэвлэдэг функц:
void Triangle :: print(){
    cout << "Taliin urt: " << fixed << setprecision(2) <<  this->negj_utga << endl;
    cout << "Deed: (" << fixed << setprecision(2) << this->coordinate[0] << "," << fixed << setprecision(2) << this->coordinate[1] << ")\n";
    cout << "Dood baruun: (" << fixed << setprecision(2) << this->coordinate[2]<< ", " << fixed << setprecision(2) << this->coordinate[3] << ")\n";
    cout << "Dood zuun: (" << fixed << setprecision(2) << this->coordinate[4] << ", " << fixed << setprecision(2) << this->coordinate[5] << ")\n";
}

// талбай бодож гаргах функц
float Triangle :: findArea(){
        return (this->negj_utga)*(this->negj_utga)*sqrt(3.0)/4;
}

// периметрийг бодож гаргах функц
float Triangle :: findPerimeter(){
        return (this->negj_utga)*3;
}