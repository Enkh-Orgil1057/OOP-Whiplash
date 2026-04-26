#include <iostream>
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;
void sortArea(TwoDShape* arr[], int n){

    TwoDShape* temp;
    int i, j;
    for(i = 1; i < n; i++){
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && temp->findArea() > arr[j]->findArea()){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main(){
    TwoDShape* arr[6] = 
    {
        new Circle("Circle1", 3, 2, 2),
        new Circle("Circle2", 2, 2, 2),
        new Square("Square1", 7, 0, 0),
        new Square("Square2", 5, 0, 0),
        new Triangle("Triangle1", 1, 1, 1),
        new Triangle("Triangle2", 2, 2, 2),
    };

    cout << "====== Эрэмбэлээгүй =======" << endl << endl;
    for (int i = 0; i < Shape::get_obj_num(); i++){
        cout << arr[i]->get_name() << " -> " << arr[i]->findArea() << endl;
    }

    sortArea(arr, Shape::get_obj_num());
    
    cout << "====== Эрэмбэлсэн =======" << endl << endl;
        for (int i = 0; i < Shape::get_obj_num(); i++){
        cout << arr[i]->get_name() << " -> " << arr[i]->findArea() << endl;
    }

    for (int i = 0; i < Shape::get_obj_num(); i++){
        delete arr[i];
    }
    
    return 0;
}