#include <iostream>
#include <cmath>
using namespace std;

// Shape эх функцийг байгуулна:
class Shape {
    protected:
        string name;
    public:
        void setName(string n) {
            name = n;
        }
        string getName() {
        return name;
        }
};

// TwoDShape эх функцийг Shape функцээс удамшуулан авна:
class TwoDShape : public Shape {
    public:
        virtual double area() = 0;
        virtual double perimeter() = 0;
};


// Дөрвөлжин хэмээх классыг TwoDShape функцээс удамшуулав
class Square : public TwoDShape {
    private:
        double x1, y1, x2, y2, x3, y3, x4, y4;
        double side;

    public:
        void input() {
            cout << "Square top-left (x y): ";
            cin >> x1 >> y1;
            cout << "Side length: ";
            cin >> side;

            x2 = x1 + side;
            y2 = y1;

            x3 = x1 + side;
            y3 = y1 - side;

            x4 = x1;
            y4 = y1 - side;
        }

        double area() {
            return side * side;
        }

        double perimeter() {
            return 4 * side;
        }

        void printVertices() {
            cout << "Vertices:\n";
            cout << "(" << x1 << ", " << y1 << ")\n";
            cout << "(" << x2 << ", " << y2 << ")\n";
            cout << "(" << x3 << ", " << y3 << ")\n";
            cout << "(" << x4 << ", " << y4 << ")\n";
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

        // setter функцуудыг тодорхойлов:
        void set_taliin_urt(float t){
            if (t > 0)
                taliin_urt = t;
        }

        void set_deed_coor(float d1, float d2){
                deed_coor[0] = d1;
                deed_coor[1] = d2;
        }
        void set_zuun_dood_coor(float z1, float z2){
                zuun_dood_coor[0] = z1;
                zuun_dood_coor[1] = z2;
        }
        void set_baruun_dood_coor(float b1, float b2){
                baruun_dood_coor[0] = b1;
                baruun_dood_coor[1] = b2;
        }
};

int main() {
    Square sq;
    sq.setName("Square");
    cout << "Shape: " << sq.getName() << endl;

    sq.input();
    cout << "Area: " << sq.area() << endl;
    cout << "Perimeter: " << sq.perimeter() << endl;
    sq.printVertices();

    return 0;
}