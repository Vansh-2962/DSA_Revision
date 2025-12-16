#include<iostream>
#include<stdio.h>

using namespace std;

// DECLARING AN ABSTRACT CLASS.
class Shape {
    public:
        virtual void area() = 0; // VIRTUAL FUNCTION
        virtual void perimeter() = 0;
};


// DECLARING A DERIVED CLASS.
class Square:public Shape{
    private:
        int side; // encapsulation
    public:
        Square(int s){
            side = s;
        }
        void area(){
            cout << "Area of square is " << side*side << endl;
        }
        void perimeter(){
            cout << "Perimeter of square is " << 4*side << endl;
        }
};

class Rectangle:public Shape{
    private:
        int length;         // encapsulation
        int breadth;        // encapsulation
    public:
        Rectangle(int l, int b){
            length = l;
            breadth = b;
        }
        void area(){
            cout << "Area of rectangle is " << length*breadth << endl;
        }
        void perimeter(){
            cout << "Perimeter of rectangle is " << 2*(length+breadth) << endl;
        }
};


// --------------------------------------------------------------------------------------------------------

int main(){

    Square s(5);
    s.area();
    s.perimeter();

    Rectangle r(3, 19);
    r.area();
    r.perimeter();

    return 0;
}