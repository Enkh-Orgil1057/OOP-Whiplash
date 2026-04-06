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
        //ner butaah
        void getter() {
        cout<< name<< endl;
        }
        //talbai oloh
        float findArea();
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
            cout<< "Tuv tseg = " << center_coor[0] << ", "<< center_coor[0] << endl; 
        }

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

        float area() {
            return side * side;
        }

        float perimeter() {
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
        void set_zuun_dood_coor(float z1, float z2){
                zuun_dood_coor[0] = z1;
                zuun_dood_coor[1] = z2;
        }
        void set_baruun_dood_coor(float b1, float b2){
                baruun_dood_coor[0] = b1;
                baruun_dood_coor[1] = b2;
        }

        // Талбайг бодож гаргах функц тодорхойлов:
        float findArea(){
            return taliin_urt*taliin_urt/2;
        }

        // Периметрийг бодож гаргах функц тодорхойлов:
        float findPerimeter(){
            return taliin_urt*3;
        }

        // зүүн доод цэгийг бодож гаргах функц тодорхойлов:
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