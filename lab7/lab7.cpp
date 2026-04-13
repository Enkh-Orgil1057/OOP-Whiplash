// Лаб 6-д хийсэн circle, square, triangle классуудаас 
// олон объект үүсгэж дүрс хооронд талбайгаар нь эрэмбэл. 
// Мөн эх классуудад байгуулагч функц тодорхойлж удамшлын үед
// эх классын параметертэй байгуулагчыг дуудаж ажиллуулах ба давуу сул талыг харьцуулан дүгнэлт бичээрэй.
#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.14
using namespace std;

//--------------------------------------------------------
//--------------------SHAPE CLASS------------------------
//--------------------------------------------------------
// Shape эх функцийг байгуулна:
class Shape {
    protected:
        string name;
    public:
        void setter(string n) {
            name = n;
        }
        //gishuun ugugdul hevlej haruuldag function
        void print(){
            cout << "Ner: " << name << endl;
        }
        // нэр буцаах getter функц
        string get_name() {
            return name;
        }
        //anhdagch baiguulagch
        Shape(){
            name = "hooson";
        }
        //parametertei baiguulagch
        Shape(string n){
            name = n;
        }
};
//--------------------------------------------------------
//--------------------TWODSHAPE CLASS------------------------
//--------------------------------------------------------
// TwoDShape эх функцийг Shape функцээс удамшуулан авна:
class TwoDShape : public Shape {
    protected:
        float negj_utga;
        float default_coor[2];
    public:
        //setter function
        void setter(string n, float negj, float x, float y){
            name = n;
            negj_utga = negj;
            default_coor[0] = x;
            default_coor[1] = y;
        }
        //getter functionnuud
        float get_negj_utga(){
            return negj_utga;
        }
        virtual float findPerimeter() = 0;
        //talbai oloh
        virtual float findArea() = 0;
        // anhdagch baiguulagch
        TwoDShape() : Shape()
        {
            negj_utga = 0;
            default_coor[0] = 0;
            default_coor[1] = 0;
        }
        // parametertei baiguulagch
        TwoDShape(string n, float negj, float x, float y) : Shape(n)
        {
            negj_utga = negj;
            default_coor[0] = x;
            default_coor[1] = y;
        }
        
};
//--------------------------------------------------------
//--------------------CIRCLE CLASS------------------------
//--------------------------------------------------------
class Circle : public TwoDShape{
    public:
        //perimeter oloh function oloh: 2*rad*PI
        float findPerimeter()  {
            return (2 * negj_utga * PI);
        }
        //toirgiin talbai oloh: rad^2 * PI
        float findArea()  {
            return (negj_utga * negj_utga) * PI;
        }

        //garaas toirgiin tuv tseg bolon, negj_utga utgiig avah
        void setter(string n, float _rad, float x, float y){
            negj_utga = _rad;
            default_coor[0] = x;
            default_coor[1] = y;
            name = n;
        }
        //oruulsan utguudiig harah
        void print(){
            cout<< "negj_utga = " << negj_utga << endl;
            cout<< "Tuv tseg = " << default_coor[0] << ", "<< default_coor[1] << endl; 
        }
        //negj_utga butsaah function
        float get_rad(){ return negj_utga; }
        //tuv tseg butsaah function
        float* get_center(){ return default_coor; }
        //anhdagch baiguulagch
        Circle() : TwoDShape(){}
        
        //parametertei baiguulagch
        Circle(string n, float negj, float x, float y) : TwoDShape(n, negj, x, y){}
};

//--------------------------------------------------------
//--------------------SQUARE CLASS------------------------
//--------------------------------------------------------
// Квадрат хэмээх классыг TwoDShape функцээс удамшуулав
// Square класс
class Square : public TwoDShape {
protected:
    float deed_baruun[2]; //top-right#include <iostream>
    float dood_baruun[2]; // bottom-right
    float dood_zvvn[2]; //bottom-left

public:

    //anhdagch baiguulagch
    Square() : TwoDShape(){}
        
    //parametertei baiguulagch
    Square(string n, float negj, float x, float y) : TwoDShape(n, negj, x, y){

            deed_baruun[0] = 0;
            deed_baruun[1] = 0;
            dood_baruun[0] = 0;
            dood_baruun[1] = 0;
            dood_zvvn[0] = 0;
            dood_zvvn[1] = 0;
    }
    
    // setter
    void setter(float t, float x, float y) {
        if (t > 0) {
            negj_utga = t;
            default_coor[0] = x;
            default_coor[1] = y;
            deed_baruun[0] = default_coor[0] + negj_utga;
            deed_baruun[1] = y;
            dood_baruun[0] = deed_baruun[0];
            dood_baruun[1] = y - negj_utga;
            dood_zvvn[0] = x;
            dood_zvvn[1] = default_coor[1] - negj_utga;
          }
          else {
            cout << "Taliin urt 0-s ih baih yostoi!" << endl;
          }
    }

    // Талбай
    float findArea() {
        return negj_utga * negj_utga;
    }

    // Периметр
    float findPerimeter() {
        return 4 * negj_utga;
    }

    // Бүх мэдээлэл хэвлэх
    void print() {
        cout << "Taliin urt: " << negj_utga << endl;

        cout << "Deed zuun: (" << default_coor[0] << ", " << default_coor[1] << ")\n";

        cout << "Deed baruun: (" << deed_baruun[0] << ", " << deed_baruun[1] << ")\n";

        cout << "Dood baruun: (" << dood_baruun[0] << ", " << dood_baruun[1] << ")\n";

        cout << "Dood zuun: (" << dood_zvvn[0] << ", " << dood_zvvn[1] << ")\n";
    }

    //oroinuudiig coordinatruudig butsaah funcitonuud
    float* get_deed_zvvn(){ return default_coor;}
    float* get_dood_zvvn(){ return dood_zvvn;}
    float* get_deed_baruun(){ return deed_baruun;}
    float* get_dood_baruun(){ return dood_baruun;}
};

//--------------------------------------------------------
//--------------------TRIANGLE CLASS------------------------
//--------------------------------------------------------
// Зөв гурвалжин классыг TwoDShape классаас удамшуулав
class Triangle : public TwoDShape{
    protected:
        float zuun_dood_coor[2];
        float baruun_dood_coor[2];
    public: 

        // анхдагч байгуулагч
        Triangle() : TwoDShape() {
            zuun_dood_coor[0] = 0;
            zuun_dood_coor[1] = 0;
            baruun_dood_coor[0] = 0;
            baruun_dood_coor[1] = 0;
        }

        //параметртэй байгуулагч
        Triangle(string n, float negj, float x, float y) : TwoDShape(n ,negj, x ,y) {
            zuun_dood_coor[0] = x -(negj/2.0);
            zuun_dood_coor[1] = y -(negj*sqrt(3.0)/2.0);
            baruun_dood_coor[0] = x +(negj/2.0);
            baruun_dood_coor[1] = y -(negj*sqrt(3.0)/2.0);
        }

        //гараас талын урт, нэр болон дээд цэгийн координатыг авах 
        void setter(string n, float negj, float x, float y){
            negj_utga = negj;
            default_coor[0] = x;
            default_coor[1] = y;
            name = n;
            zuun_dood_coor[0] = default_coor[0]-(negj_utga/2.0);
            zuun_dood_coor[1] = default_coor[1]-(negj_utga*sqrt(3.0)/2.0);
            baruun_dood_coor[0] = default_coor[0]+(negj_utga/2.0);
            baruun_dood_coor[1] = default_coor[1]-(negj_utga*sqrt(3.0)/2.0);
        }
        //getter funcionuud
        float* get_deed_coor(){ return default_coor; }
        float* get_zuun_dood_coor(){ return zuun_dood_coor;}
        float* get_baruun_dood_coor(){ return baruun_dood_coor;}

        // координатын утгуудыг хэвлэдэг функц:
        void print(){
        cout << "Taliin urt: " << fixed << setprecision(2) <<  negj_utga << endl;

        cout << "Deed: (" << fixed << setprecision(2) << default_coor[0] << "," << fixed << setprecision(2) << default_coor[1] << ")\n";

        cout << "Dood baruun: (" << fixed << setprecision(2) << baruun_dood_coor[0]<< ", " << fixed << setprecision(2) << baruun_dood_coor[1] << ")\n";

        cout << "Dood zuun: (" << fixed << setprecision(2) << zuun_dood_coor[0] << ", " << fixed << setprecision(2) << zuun_dood_coor[1] << ")\n";
        }

        // периметрийг хэвлэдэг функц
        void printPerimeter(){
            cout << "Perimeter: " << fixed << setprecision(2) << findPerimeter() << endl;
        }

        // талбайг хэвлэдэг функц
        void printArea(){
            cout << "Area: " << fixed << setprecision(2) << findArea() << endl;
        }

        // талбай бодож гаргах функц
        float findArea(){
            return negj_utga*negj_utga*sqrt(3.0)/4;
        }

        // периметрийг бодож гаргах функц
        float findPerimeter(){
            return negj_utga*3;
        }

};

//--------------------------------------------------------
//--------------------busad function------------------------
//--------------------------------------------------------

//erembleh fnction
//TwoDShapes turliin n shirheg gishuuntei husnegt avaad tuunii elementuudiig insertion sort algorithm ashiglan eremblene
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
    for (int i = 0; i < 6; i++){
        cout << arr[i]->get_name() << "->" << arr[i]->findArea() << endl;
    }

    sortArea(arr, 6);
    
    cout << "====== Эрэмбэлсэн =======" << endl << endl;
        for (int i = 0; i < 6; i++){
        cout << arr[i]->get_name() << "->" << arr[i]->findArea() << endl;
    }

    for (int i = 0; i < 6; i++){
        delete arr[i];
    }
    
    return 0;
}