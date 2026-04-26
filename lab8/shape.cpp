#include <iostream>
#include <cmath>
#include <iomanip>

#include "Shape.h" // !!!! ymr header file-aas ajilaj bgaga sain zaaj uguure

using namespace std;

//static ugugdul
int Shape :: obj_num = 0;
int Shape :: get_obj_num()
{
    return obj_num;
}

//Anhdagch baiguulagch
Shape :: Shape()
{
    this->name = "0";
    obj_num++;
}
//Parametertei baiguulagch
Shape :: Shape(string n)
{
    this->name = n;
    obj_num++;
}
//setter function
void Shape :: setter(string n)
{
    this->name = n;
}
//ner hevleh function
void Shape :: print()
{
    cout << "Ner: " << this->name << endl;
}
//ner butsaah
string Shape :: get_name()
{
    return this->name;
}




