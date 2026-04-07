#include <iostream>
#include <cmath>
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
        // нэр буцаах getter функц
        void getter() {
        cout<< name<< endl;
        }
        //talbai oloh
        virtual float findArea() = 0;
};

// TwoDShape эх функцийг Shape функцээс удамшуулан авна:
class TwoDShape : public Shape {
    public:
        virtual float findPerimeter() = 0;
};

class Circle : public TwoDShape{
    private:
        float center_coor[2];
        float radius;
    public:
        //perimeter oloh function oloh: 2*rad*PI
        float findPerimeter(){
            return (2 * radius * PI);
        }
        //toirgiin talbai oloh: rad^2 * PI
        float findArea(){
            return (radius * radius) * PI;
        }

        //garaas toirgiin tuv tseg bolon, radius utgiig avah
        void setter(float _rad, float _center[]){
            radius = _rad;
            center_coor[0] = _center[0];
            center_coor[1] = _center[1];
        }
        //oruulsan utguudiig harah
        void getter(){
            cout<< "Radius = " << radius << endl;
            cout<< "Tuv tseg = " << center_coor[0] << ", "<< center_coor[1] << endl; 
        }

};

// Квадрат хэмээх классыг TwoDShape функцээс удамшуулав
class Square : public TwoDShape {
protected:
    float taliin_urt;
    float deed_zvvn[2];     // top-left
    float deed_baruun[2];   // top-right
    float dood_baruun[2];   // bottom-right
    float dood_zvvn[2];     // bottom-left

public:
    // Getters
    float get_taliin_urt() {
        return taliin_urt;
    }

    float get_deed_zvvn_x() { return deed_zvvn[0]; }
    float get_deed_zvvn_y() { return deed_zvvn[1]; }

    float get_deed_baruun_x() { return deed_baruun[0]; }
    float get_deed_baruun_y() { return deed_baruun[1]; }

    float get_dood_baruun_x() { return dood_baruun[0]; }
    float get_dood_baruun_y() { return dood_baruun[1]; }

    float get_dood_zvvn_x() { return dood_zvvn[0]; }
    float get_dood_zvvn_y() { return dood_zvvn[1]; }

    // Setters
    void set_taliin_urt(float t) {
        if (t > 0)
            taliin_urt = t;
    }

    void set_deed_zvvn(float x, float y) {
        deed_zvvn[0] = x;
        deed_zvvn[1] = y;
    }

    void set_deed_baruun(float x, float y) {
        deed_baruun[0] = x;
        deed_baruun[1] = y;
    }

    void set_dood_baruun(float x, float y) {
        dood_baruun[0] = x;
        dood_baruun[1] = y;
    }

    void set_dood_zvvn(float x, float y) {
        dood_zvvn[0] = x;
        dood_zvvn[1] = y;
    }

    // Талбай
    float findArea()  {
        return taliin_urt * taliin_urt;
    }

    // Периметр 
    float findPerimeter()  {
        return 4 * taliin_urt;
    }

    // Бусад оройг бодох
    float find_deed_baruun_x() {
        return deed_zvvn[0] + taliin_urt;
    }
    float find_deed_baruun_y() {
        return deed_zvvn[1];
    }

    float find_dood_baruun_x() {
        return deed_zvvn[0] + taliin_urt;
    }
    float find_dood_baruun_y() {
        return deed_zvvn[1] - taliin_urt;
    }

    float find_dood_zvvn_x() {
        return deed_zvvn[0];
    }
    float find_dood_zvvn_y() {
        return deed_zvvn[1] - taliin_urt;
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
            name = n;
        }

        // ашиглахгүй код:
/*
        void set_zuun_dood_coor(float z1, float z2){
                zuun_dood_coor[0] = z1;
                zuun_dood_coor[1] = z2;
        }
        void set_baruun_dood_coor(float b1, float b2){
                baruun_dood_coor[0] = b1;
                baruun_dood_coor[1] = b2;
        }
*/

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
            return deed_coor[0]-(taliin_urt/2);
        }
        float find_zuun_dood_coor_y(){
            return deed_coor[1]-(taliin_urt*sqrt(3)/2);
        }
        float find_baruun_dood_coor_x(){
            return deed_coor[0]+(taliin_urt/2);
        }
        float find_baruun_dood_coor_y(){
            return deed_coor[1]-(taliin_urt*sqrt(3)/2);
        }

        // дээрх функцуудын нэгдэл
        float find_coordinates(){
            find_zuun_dood_coor_x();
            find_zuun_dood_coor_y();
            find_baruun_dood_coor_x();
            find_baruun_dood_coor_y();
        }

};

int main() {
    Square s;

    float tal;
    float x, y;

    cout << "Kvadratiin taliin urtiig oruulna uu: ";
    cin >> tal;

    cout << "Deed zuun oroin koordinat (x y) oruulna uu: ";
    cin >> x >> y;

    // Утгуудыг тохируулна
    s.set_taliin_urt(tal);
    s.set_deed_zvvn(x, y);

    cout << "\nSquare Info" << endl;

    cout << "Taliin urt: " << s.get_taliin_urt() << endl;

    cout << "Deed zuun: ("
        << s.get_deed_zvvn_x() << ", "
        << s.get_deed_zvvn_y() << ")" << endl;

    cout << "Deed baruun: ("
        << s.find_deed_baruun_x() << ", "
        << s.find_deed_baruun_y() << ")" << endl;

    cout << "Dood baruun: ("
        << s.find_dood_baruun_x() << ", "
        << s.find_dood_baruun_y() << ")" << endl;

    cout << "Dood zuun: ("
        << s.find_dood_zvvn_x() << ", "
        << s.find_dood_zvvn_y() << ")" << endl;

    cout << "Area: " << s.area() << endl;
    cout << "Perimeter: " << s.perimeter() << endl;
    return 0;
}