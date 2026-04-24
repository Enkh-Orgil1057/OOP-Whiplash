#include <iostream>
#include <cmath>
#include <iomanip>

#include "Shape.h"
#include "TwoDShape.h"

using namespace std;

// Анхдагч байгуулагч
Triangle() : TwoDShape(){
    coordinate[0] = 0; // зүүн доод x
    coordinate[1] = 0; // зүүн доод y
    coordinate[2] = 0; // баруун доод x
    coordinate[3] = 0; // баруун доод y
}
//параметртэй байгуулагч
Triangle(string n, float negj, float x, float y) : TwoDShape(n ,negj, x ,y) {
    zuun_dood_coor[0] = x -(negj/2.0);
    zuun_dood_coor[1] = y -(negj*sqrt(3.0)/2.0);
    baruun_dood_coor[0] = x +(negj/2.0);
    baruun_dood_coor[1] = y -(negj*sqrt(3.0)/2.0);
}

//гараас талын урт, нэр болон дээд цэгийн координатыг авах 
void setter(string n, float negj, float x, float y){
    negj_utga = negj;
    default_coor[0] = x;
    default_coor[1] = y;
    name = n;
    zuun_dood_coor[0] = default_coor[0]-(negj_utga/2.0);
    zuun_dood_coor[1] = default_coor[1]-(negj_utga*sqrt(3.0)/2.0);
    baruun_dood_coor[0] = default_coor[0]+(negj_utga/2.0);
    baruun_dood_coor[1] = default_coor[1]-(negj_utga*sqrt(3.0)/2.0);
}

//getter funcionuud
float* get_deed_coor(){ return default_coor; }
float* get_zuun_dood_coor(){ return zuun_dood_coor;}
float* get_baruun_dood_coor(){ return baruun_dood_coor;}

// координатын утгуудыг хэвлэдэг функц:
void print(){
    cout << "Taliin urt: " << fixed << setprecision(2) <<  negj_utga << endl;
    cout << "Deed: (" << fixed << setprecision(2) << default_coor[0] << "," << fixed << setprecision(2) << default_coor[1] << ")\n";
    cout << "Dood baruun: (" << fixed << setprecision(2) << baruun_dood_coor[0]<< ", " << fixed << setprecision(2) << baruun_dood_coor[1] << ")\n";
    cout << "Dood zuun: (" << fixed << setprecision(2) << zuun_dood_coor[0] << ", " << fixed << setprecision(2) << zuun_dood_coor[1] << ")\n";
}

// периметрийг хэвлэдэг функц
void printPerimeter(){
        cout << "Perimeter: " << fixed << setprecision(2) << findPerimeter() << endl;
}

// талбайг хэвлэдэг функц
void printArea(){
        cout << "Area: " << fixed << setprecision(2) << findArea() << endl;
}

// талбай бодож гаргах функц
float findArea(){
        return negj_utga*negj_utga*sqrt(3.0)/4;
}

// периметрийг бодож гаргах функц
float findPerimeter(){
        return negj_utga*3;
}