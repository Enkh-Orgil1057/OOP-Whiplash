#include <iostream>
#include <cmath>
#include <iomanip>

#include "Shape.h" // !!!! ymr header file-aas ajilaj bgaga sain zaaj uguure

using namespace std;
//Anhdagch baiguulagch
Shape :: Shape()
{
    name = "0";
}
//Parametertei baiguulagch
Shape :: Shape(string n)
{
    name = n;
}
//setter function
void Shape :: setter(string n)
{
    name = n;
}
//ner hevleh function
void Shape :: print()
{
    cout << "Ner: " << name << endl;
}
//ner butsaah
string Shape :: get_name(){
    return name;
}




