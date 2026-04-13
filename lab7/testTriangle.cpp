#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#define PI 3.14
using namespace std;

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
        //talbai oloh
        virtual float findArea() = 0;
        
        //anhdagch baiguulagch
        Shape(){
            name = "hooson";
        }
        //parametertei baiguulagch
        Shape(string n){
            name = n;
        }
};

// TwoDShape эх функцийг Shape функцээс удамшуулан авна:
class TwoDShape : public Shape {
    protected:
        float negj_utga;
        float default_coor[2];
    public:
        //setter function
        void setter(string n, float negj, float coor[]){
            name = n;
            negj_utga = negj;
            default_coor[0] = coor[0];
            default_coor[1] = coor[1];
        }
        //getter functionnuud
        virtual float findPerimeter() = 0;
        // anhdagch baiguulagch
        TwoDShape() : Shape()
        {
            negj_utga = 0;
            default_coor[0] = 0;
            default_coor[1] = 0;
        }
        // parametertei baiguulagch
        TwoDShape(string n, float negj, float coor[]) : Shape(n)
        {
            negj_utga = negj;
            default_coor[0] = coor[0];
            default_coor[1] = coor[1];
        }
};

// Зөв гурвалжин классыг TwoDShape классаас удамшуулав
class Triangle : public TwoDShape{
    protected:
        float taliin_urt;
        float deed_coor[2];
        float zuun_dood_coor[2];
        float baruun_dood_coor[2];
        float perimeter;
        float area;
    public: 

        // анхдагч байгуулагч
        Triangle() : TwoDShape() {
            taliin_urt = 0;
            deed_coor[0] = 0;
            deed_coor[1] = 0;
            zuun_dood_coor[0] = 0;
            zuun_dood_coor[1] = 0;
            baruun_dood_coor[0] = 0;
            baruun_dood_coor[1] = 0;
            area = findArea();
            perimeter = findPerimeter();
        }

        //параметртэй байгуулагч
        Triangle(string n, float negj_utga, float x, float y) : TwoDShape() {
            name = n;
            taliin_urt = negj_utga;
            deed_coor[0] = x;
            deed_coor[1] = y;
            zuun_dood_coor[0] = deed_coor[0]-(taliin_urt/2.0);
            zuun_dood_coor[1] = deed_coor[1]-(taliin_urt*sqrt(3.0)/2.0);
            baruun_dood_coor[0] = deed_coor[0]+(taliin_urt/2.0);
            baruun_dood_coor[1] = deed_coor[1]-(taliin_urt*sqrt(3.0)/2.0);
            area = findArea();
            perimeter = findPerimeter();
        }

        //гараас талын урт, нэр болон дээд цэгийн координатыг авах 
        void setter(string n, float negj_utga, float x, float y){
            taliin_urt = negj_utga;
            deed_coor[0] = x;
            deed_coor[1] = y;
            name = n;
            zuun_dood_coor[0] = deed_coor[0]-(taliin_urt/2.0);
            zuun_dood_coor[1] = deed_coor[1]-(taliin_urt*sqrt(3.0)/2.0);
            baruun_dood_coor[0] = deed_coor[0]+(taliin_urt/2.0);
            baruun_dood_coor[1] = deed_coor[1]-(taliin_urt*sqrt(3.0)/2.0);
            area = findArea();
            perimeter = findPerimeter();
        }

        float get_taliin_urt(){
            return taliin_urt;
        }
        float get_deed_coor_x(){
            return deed_coor[0];
        }
        float get_deed_coor_y(){
            return deed_coor[1];
        }
        float get_zuun_dood_coor_x(){
            return zuun_dood_coor[0];
        }
        float get_zuun_dood_coor_y(){
            return zuun_dood_coor[1];
        }
        float get_baruun_dood_coor_x(){
            return baruun_dood_coor[0];
        }
        float get_baruun_dood_coor_y(){
            return baruun_dood_coor[1];
        }

        // координатын утгуудыг хэвлэдэг функц:
        void print(){
        cout << "Taliin urt: " << fixed << setprecision(2) <<  taliin_urt << endl;

        cout << "Dood baruun: (" << fixed << setprecision(2) << baruun_dood_coor[0]<< ", " << fixed << setprecision(2) << baruun_dood_coor[1] << ")\n";

        cout << "Dood zuun: (" << fixed << setprecision(2) << zuun_dood_coor[0] << ", " << fixed << setprecision(2) << zuun_dood_coor[1] << ")\n";
        }

        // периметрийг хэвлэдэг функц
        void printPerimeter(){
            cout << "Perimeter: " << fixed << setprecision(2) << findPerimeter() << endl;
        }

        // талбай бодож гаргах функц
        float findArea(){
            return taliin_urt*taliin_urt*sqrt(3.0)/4;
        }

        // периметрийг бодож гаргах функц
        float findPerimeter(){
            return taliin_urt*3;
        }

};

// гурвалжны периметр харьцуулдаг функцийг тодорхойлов
bool compareTriangle(Triangle a, Triangle b) {
    return a.findPerimeter() < b.findPerimeter(); // өсөх дараалал
}

int main(){
    Triangle arr1[3];

    arr1[0].setter("Tri1", 1, 1, 1);
    arr1[1].setter("Tri2", 2, 2, 2);
    arr1[2].setter("Tri3", 3, 3, 3);

    cout << endl;

    arr1[0].printPerimeter();
    arr1[1].printPerimeter();
    arr1[2].printPerimeter();

    sort(arr1, arr1 + 3, compareTriangle);

    cout << endl;


    arr1[0].printPerimeter();
    arr1[1].printPerimeter();
    arr1[2].printPerimeter();

    return 0;

}