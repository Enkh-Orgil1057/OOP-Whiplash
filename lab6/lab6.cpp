#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.14
using namespace std;

// Shape эх функцийг байгуулна:
class Shape {
    protected:
        string name;
    public:
        // constructor
        Shape(string n = "0") {
        name = n;
        }
        
        // setter
        void setter(string n) {
            name = n;
        }
        //gishuun ugugdul hevlej haruuldag function
        void print(){
            cout << "Ner: " << name<< endl;
        }
        // нэр буцаах getter функц
        string getter() {
        return name;
        }

        //talbai oloh
        virtual float findArea() = 0;
};

// TwoDShape
class TwoDShape : public Shape {
protected:
    float default_coor[2];
    float negj_utga;

public:
    // constructor
    TwoDShape(string n = "0", float x = 0, float y = 0, float t = 0)
        : Shape(n) {
        default_coor[0] = x;
        default_coor[1] = y;
        negj_utga = t;
    }

    // setter
    void setter(float x, float y, float t) {
        default_coor[0] = x;
        default_coor[1] = y;
        negj_utga = t;
    }

    virtual float findPerimeter() = 0;
};

class Circle : public TwoDShape{
    private:
        float center_coor[2];
        float radius;
    public:
        //perimeter oloh function oloh: 2*rad*PI
        float findPerimeter()  {
            return (2 * radius * PI);
        }
        //toirgiin talbai oloh: rad^2 * PI
        float findArea()  {
            return (radius * radius) * PI;
        }

        //garaas toirgiin tuv tseg bolon, radius utgiig avah
        void setter(float _rad, float _center[], string n){
            radius = _rad;
            center_coor[0] = _center[0];
            center_coor[1] = _center[1];
            name = n;
        }
        //oruulsan utguudiig harah
        void print(){
            cout<< "Radius = " << radius << endl;
            cout<< "Tuv tseg = " << center_coor[0] << ", "<< center_coor[1] << endl; 
        }
        //radius butsaah function
        float get_rad(){
            return radius;
        }
        //tuv tseg butsaah function
        float* get_center(){
            return center_coor; 
        }

};

// Квадрат хэмээх классыг TwoDShape функцээс удамшуулав
// Square класс
// Square 
class Square : public TwoDShape {
protected:
    float deed_zvvn[2];
    float deed_baruun[2];
    float dood_baruun[2];
    float dood_zvvn[2];

    // changer
    void changer() {
        float x = default_coor[0];
        float y = default_coor[1];
        float t = negj_utga;

        deed_zvvn[0] = x;
        deed_zvvn[1] = y;

        deed_baruun[0] = x + t;
        deed_baruun[1] = y;

        dood_baruun[0] = x + t;
        dood_baruun[1] = y - t;

        dood_zvvn[0] = x;
        dood_zvvn[1] = y - t;
    }

public:
    // constructor
    Square(string n = "0", float x = 0, float y = 0, float t = 0)
        : TwoDShape(n, x, y, t) {
        changer();
    }

    // setter
    void setter(float t, float x, float y, string n) {
        Shape::setter(n);           // name
        TwoDShape::setter(x, y, t); // coord + length
        changer();                // update
    }

    float findArea() {
        return negj_utga * negj_utga;
    }

    float findPerimeter() {
        return 4 * negj_utga;
    }

    void print() {
        Shape::print();
        cout << "Taliin urt: " << negj_utga << endl;

        cout << "Deed zuun: (" << deed_zvvn[0] << ", " << deed_zvvn[1] << ")\n";
        cout << "Deed baruun: (" << deed_baruun[0] << ", " << deed_baruun[1] << ")\n";
        cout << "Dood baruun: (" << dood_baruun[0] << ", " << dood_baruun[1] << ")\n";
        cout << "Dood zuun: (" << dood_zvvn[0] << ", " << dood_zvvn[1] << ")\n";
    }
};


// Зөв гурвалжин классыг TwoDShape классаас удамшуулав
class Triangle : public TwoDShape{
    protected:
        float taliin_urt;
        float deed_coor[2];
        float zuun_dood_coor[2];
        float baruun_dood_coor[2];
    public: 
        // getter функцуудыг тодорхойлов:
        void print() {
        cout << "Taliin urt: " << fixed << setprecision(2) <<  taliin_urt << endl;

        cout << "Dood baruun: (" << fixed << setprecision(2) << find_baruun_dood_coor_x()<< ", " << fixed << setprecision(2) << find_baruun_dood_coor_y() << ")\n";

        cout << "Dood zuun: (" << fixed << setprecision(2) << find_zuun_dood_coor_x() << ", " << fixed << setprecision(2) << find_zuun_dood_coor_y() << ")\n";
    }
        
        //Orgil: Tailbariin daguu "deed oroin coordinat bolon taliin urtiig avaad nuguu 2 oroin bairshliig oldog baina"
        // setter функцуудыг тодорхойлов:
        void set_taliin_urt(float t){
            if (t > 0)
                taliin_urt = t;
        }

        void set_deed_coor(float d1, float d2){
                deed_coor[0] = d1;
                deed_coor[1] = d2;
        }
        // setter() функцээ set_taliin_urt ба set_deed_coor
        // функцийг дууддаг болгон дахин тодорхойлов
        void setter(float a, float b, float c, string n){
            set_taliin_urt(a); // талын урт авах
            set_deed_coor(b, c); // дээд координатыг авах
            find_zuun_dood_coor_x();
            find_zuun_dood_coor_y();
            find_baruun_dood_coor_x();
            find_baruun_dood_coor_y();
            name = n;
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

        // Shape эх функцийн талбай бодож гаргах
        // функцийг дахин тодорхойлов:
        float findArea(){
            return taliin_urt*taliin_urt/2;
        }

        // TwoDShape эх функцийн Периметрийг бодож
        // гаргах функцийг дахин тодорхойлов:
        float findPerimeter(){
            return taliin_urt*3;
        }

        // цэгийг бодож гаргах функц бүрийг тодорхойлов:
        // үүний доор нь нэгтгэв.
        float find_zuun_dood_coor_x(){
            return deed_coor[0]-(taliin_urt/2.0);
        }
        float find_zuun_dood_coor_y(){
            return deed_coor[1]-(taliin_urt*sqrt(3.0)/2.0);
        }
        float find_baruun_dood_coor_x(){
            return deed_coor[0]+(taliin_urt/2.0);
        }
        float find_baruun_dood_coor_y(){
            return deed_coor[1]-(taliin_urt*sqrt(3.0)/2.0);
        }

};

int main() {

    return 0;
}