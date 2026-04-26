#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>
using namespace std;

class Shape
{
    protected:
        string name;
        static int obj_num;
    public:
        Shape();
        Shape(string);
        void setter(string);
        void print();
        string get_name();
        static int get_obj_num();
};
#endif