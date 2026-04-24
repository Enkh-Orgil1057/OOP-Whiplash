#include <iostream>
#include <cmath>
#include <iomanip>
#include "Square.h"
using namespace std;

void Square :: updateCoor(float negj, float x, float y)
{
  coordinate[0] = x;            //deed zuun x
  coordinate[1] = y;            //deed zuun y
  coordinate[2] = x + negj;     //deed baruun x
  coordinate[3] = y;            //deed baruun y
  coordinate[4] = coordinate[2]; //dood baruun x
  coordinate[5] = y - negj;      //dood baruun y
  coordinate[6] = x;            //dood zuun x
  coordinate[7] = coordinate[5]; //dood zuun y
}
Square :: Square() : TwoDShape()
{
  coordinate = new float[8]{0};
}

Square :: Square(string n, float negj, float x, float y) : TwoDShape(name, negj)
{
  coordinate = new float[8];
  updateCoor(negj, x, y);
}

void Square :: setter(string n, float negj, float x, float y)
{
  name = n;
  negj_utga = negj;
  updateCoor(negj, x, y);
}

float Square :: findArea()
{
  return (negj_utga * negj_utga);
}

float Square :: findPerimeter()
{
  return (negj_utga * 4);
}

void Square :: print() {
  cout << "Taliin urt: " << negj_utga << endl;
  cout << "Deed zuun: (" << coordinate[0] << ", " << coordinate[1] << ")\n";
  cout << "Deed baruun: (" << coordinate[2] << ", " << coordinate[3] << ")\n";
  cout << "Dood baruun: (" << coordinate[4] << ", " << coordinate[5] << ")\n";
  cout << "Dood zuun: (" << coordinate[6] << ", " << coordinate[7] << ")\n";
}