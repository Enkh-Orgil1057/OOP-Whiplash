#include <iostream>
#include <cmath>
#include <iomanip>
#include "Square.h"
using namespace std;
//jishee
void setter(float t, float x, float y) {
        if (t > 0) {
            negj_utga = t;
            coordinate[0] = x;
            coordinate[1] = y;
            coordinate[2] = default_coor[0] + negj_utga;
            coordinate[3] = y;
            coordinate[4] = deed_baruun[0];
            coordinate[5] = y - negj_utga;
            coordinate[6] = x;
            coordinate[7] = default_coor[1] - negj_utga;
          }
          else {
            cout << "Taliin urt 0-s ih baih yostoi!" << endl;
          }
    }