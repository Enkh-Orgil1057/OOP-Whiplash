// Лаб 6-д хийсэн circle, square, triangle классуудаас 
// олон объект үүсгэж дүрс хооронд талбайгаар нь эрэмбэл. 
// Мөн эх классуудад байгуулагч функц тодорхойлж удамшлын үед
// эх классын параметертэй байгуулагчыг дуудаж ажиллуулах ба давуу сул талыг харьцуулан дүгнэлт бичээрэй.
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
        void setter(float _rad, float _center[], string n){
            negj_utga = _rad;
            default_coor[0] = _center[0];
            default_coor[1] = _center[1];
            name = n;
        }
        //oruulsan utguudiig harah
        void print(){
            cout<< "negj_utga = " << negj_utga << endl;
            cout<< "Tuv tseg = " << default_coor[0] << ", "<< default_coor[1] << endl; 
        }
        //negj_utga butsaah function
        float get_rad(){
            return negj_utga;
        }
        //tuv tseg butsaah function
        float* get_center(){
            return default_coor; 
        }
        //anhdagch baiguulagch
        Circle() : TwoDShape(){}
        
        //parametertei baiguulagch
        Circle(string n, float negj, float coor[]) : TwoDShape(n, negj, coor){}
};

// Квадрат хэмээх классыг TwoDShape функцээс удамшуулав
// Square класс
class Square : public TwoDShape {
protected:
    float deed_baruun[2]; //top-right
    float dood_baruun[2]; // bottom-right
    float dood_zvvn[2]; //bottom-left

public:

    //anhdagch baiguulagch
    Square() : TwoDShape(){

    }
        
    //parametertei baiguulagch
    Square(string n, float negj, float coor[]) : TwoDShape(n, negj, coor){
            default_coor[0] = default_coor[0];
            default_coor[1] = default_coor[1];
            deed_baruun[0] = default_coor[0] + negj_utga;
            deed_baruun[1] = default_coor[1];
            dood_baruun[0] = deed_baruun[0];
            dood_baruun[1] = default_coor[1] - negj_utga;
            dood_zvvn[0] = default_coor[0];
            dood_zvvn[1] = default_coor[1] - negj_utga;
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

    //taliin urt butsaah function
    float get_tal(){
        return negj_utga;
    }
    //oroinuudiig coordinatruudig butsaah funcitonuud
    float* get_deed_zvvn(){ return default_coor;}
    float* get_dood_zvvn(){ return dood_zvvn;}
    float* get_deed_baruun(){ return deed_baruun;}
    float* get_dood_baruun(){ return dood_baruun;}
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
 
}