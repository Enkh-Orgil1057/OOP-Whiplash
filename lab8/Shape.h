#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>
using namespace std;

class Shape
{
    protected:
        string name;
    public:
        Shape();
        Shape(string);
        void setter(string);
        void print();
        string get_name();
};
#endif