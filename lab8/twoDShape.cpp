#include <iostream>
#include <cmath>
#include <iomanip>

#include "TwoDShape.h"

using namespace std;

void TwoDShape ::setter(string n, float negj, float x, float y)
{
    this->name = n;
    this->negj_utga = negj;
    this->coordinate[0] = x;
    this->coordinate[1] = y;
}

float TwoDShape ::get_negj_utga()
{
    return this->negj_utga;
}

float *TwoDShape ::get_coordinate()
{
    return this->coordinate;
}
/*
TwoDShapes-iin baguulagch nar ni sanah oi nuutsluhgui. Tus ajliig tuunii huuhed classuud guitsetgene.
Zuvhun negj utga bolon neriig avaad, NER-ee Shape-iin baguulagch ruu damjuulj, negj utgaa uurtoo onoono.
JICH: TwoDShapes ni hiisver class tul tuunii object uuseh anhnaas bolomjgui. Mun uunees udamshig class-uudiin coordinate-uud ni uur hemjeetei tul eh class dotor tuunii hemjeeg oruulah bolomjgui bolno.
*/
TwoDShape ::TwoDShape() : Shape()
{
    this->negj_utga = 0;
}
TwoDShape ::TwoDShape(string n, float negj) : Shape(n)
{
    this->negj_utga = negj;
}
TwoDShape ::~TwoDShape()
{
    delete[] this->coordinate;
}
