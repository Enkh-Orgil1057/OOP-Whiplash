#include <iostream>
#include <cmath>
#include <iomanip>

#include "Shape.h"
#include "TwoDShape.h"

using namespace std;

void TwoDShape :: setter(string n, float negj, float x, float y){
            name = n;
            negj_utga = negj;
            default_coor[0] = x;
            default_coor[1] = y;
        }

float TwoDShape :: get_negj_utga(){
            return negj_utga;
        }

TwoDShape :: TwoDShape() : Shape(){
            negj_utga = 0;
            default_coor[0] = 0;
            default_coor[1] = 0;
        }

TwoDShape :: TwoDShape(string n, float negj, float x, float y) : Shape(n){
            setter(n, negj, x, y);
        }
