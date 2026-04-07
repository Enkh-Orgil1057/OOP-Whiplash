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
// Square класс
class Square : public TwoDShape {
protected:
    float taliin_urt;
    float deed_zvvn[2]; // top-left
    float deed_baruun[2]; //top-right
    float dood_baruun[2]; // bottom-right
    float dood_zvvn[2]; //bottom-left

public:
    // setter
    void setter(float t, float x, float y) {
        if (t > 0) {
            taliin_urt = t;
            deed_zvvn[0] = x;
            deed_zvvn[1] = y;
            deed_baruun[0] = deed_zvvn[0]+taliin_urt;
            deed_baruun[1] = y;
            dood_baruun[0] = deed_baruun[0];
            dood_baruun[1] = y - taliin_urt;
            dood_zvvn[0] = x;
            dood_zvvn[1] = deed_zvvn[1] - taliin_urt;
          }
    }

    // Талбай
    float findArea() {
        return taliin_urt * taliin_urt;
    }

    // Периметр
    float findPerimeter() {
        return 4 * taliin_urt;
    }

    // Бүх мэдээлэл хэвлэх
    void getter() {
        cout << "Taliin urt: " << taliin_urt << endl;

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
        void getter() {
        cout << "Taliin urt: " << fixed << setprecision(2) << taliin_urt << endl;

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
    Square s;

    float tal, x, y;

    cout << "\nKvadratiin taliin urtiig oruulna uu: ";
    cin >> tal;

    cout << "\nDeed zuun oroin koordinat (x y) oruulna uu: ";
    cin >> x >> y;

    // setter ашиглана
    s.setter(tal, x, y);

    cout << "\nSquare Info\n";

    // getter (print хийж байгаа)
    s.getter();

    cout << "\nArea: " << s.findArea() << endl;
    cout << "\nPerimeter: " << s.findPerimeter() << endl;

    Triangle T1;

    cout << "\nGurvaljingiin taliin urtiig oruulna uu: ";
    cin >> tal;

    cout << "\nDeed oroin koordinat (x y) oruulna uu: ";
    cin >> x >> y;

    T1.setter(tal, x, y, "Гурвалжин");

    
    // дэлгэцэд хэвлэнэ
    T1.getter();

    cout << "\nArea: " << T1.findArea() << endl;
    cout << "\nPerimeter: " << T1.findPerimeter() << endl;

    return 0;
}