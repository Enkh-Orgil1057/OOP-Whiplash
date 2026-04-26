#include <iostream>
#include <cmath>
#include <iomanip>
#include "Square.h"
using namespace std;

void Square :: updateCoor(float negj, float x, float y)
{
  this->coordinate[0] = x;            //deed zuun x
  this->coordinate[1] = y;            //deed zuun y
  this->coordinate[2] = x + negj;     //deed baruun x
  this->coordinate[3] = y;            //deed baruun y
  this->coordinate[4] = coordinate[2]; //dood baruun x
  this->coordinate[5] = y - negj;      //dood baruun y
  this->coordinate[6] = x;            //dood zuun x
  this->coordinate[7] = coordinate[5]; //dood zuun y
}
Square :: Square() : TwoDShape()
{
  this->coordinate = new float[8]{0};
}

Square :: Square(string n, float negj, float x, float y) : TwoDShape(n, negj)
{
  this->coordinate = new float[8];
  this->updateCoor(negj, x, y);
}

void Square :: setter(string n, float negj, float x, float y)
{
  this->name = n;
  this->negj_utga = negj;
  this->updateCoor(negj, x, y);
}

float Square :: findArea()
{
  return ((this->negj_utga) * (this->negj_utga));
}

float Square :: findPerimeter()
{
  return ((this->negj_utga) * 4);
}

void Square :: print() {
  cout << "Taliin urt: " << this->negj_utga << endl;
  cout << "Deed zuun: (" << this->coordinate[0] << ", " << this->coordinate[1] << ")\n";
  cout << "Deed baruun: (" << this->coordinate[2] << ", " << this->coordinate[3] << ")\n";
  cout << "Dood baruun: (" << this->coordinate[4] << ", " << this->coordinate[5] << ")\n";
  cout << "Dood zuun: (" << this->coordinate[6] << ", " << this->coordinate[7] << ")\n";
}