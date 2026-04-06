
#include <iostream>
#include <cmath>
using namespace std;
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

class TwoDShape : public Shape {
    public:
        virtual double area() = 0;
        virtual double perimeter() = 0;
};


// QUADRATE CLASS
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