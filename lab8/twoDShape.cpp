#include <iostream>
#include <cmath>
#include <iomanip>

#include "Shape.h"
#include "TwoDShape.h"

using namespace std;

void TwoDShape :: setter(string n, float negj, float x, float y){
    name = n;
    negj_utga = negj;
    coordinate[0] = x;
    coordinate[1] = y;
}

float TwoDShape :: get_negj_utga(){
    return negj_utga;
}

float* TwoDShape :: get_coordinate()
{
    return coordinate;
}

TwoDShape :: TwoDShape() : Shape(){
    negj_utga = 0;
}

TwoDShape :: TwoDShape(string n, float negj) : Shape(n){
    negj_utga = negj;
}
TwoDShape :: ~TwoDShape(){
    delete coordinate;
}

