// C++ program to demonstrate Encapsulation

// Encapsulation - Encapsulation is an object oriented programming concept that binds together the data and
// functions that manipulate the data.

#include<bits/stdc++.h>
using namespace std;

// class 1 (binds data and functions for calculating area of a triangle)
class Triangle{
    public:
        int base,height;
        void AreaOfTriangle(){
            int AreaOfT=(base*height)/2;
            cout<<"Area of triangle with base "<<base<<" and height "<<height<<" is "<<AreaOfT<<endl;
        }
};

// class 2 (binds data and functions for calculating area of a rectangle)
class Rectangle{
    public:
        int length,breadth;
        void AreaOfRectangle(){
            int AreaOfR=length*breadth;
            cout<<"Area of rectangle with length "<<length<<" and breadth "<<breadth<<" is "<<AreaOfR<<endl;
        }
};

int main(){
    // Create an object of class Triangle
    Triangle t1;
    t1.base=10;
    t1.height=20;
    t1.AreaOfTriangle();
    
    // Create an object of class Rectangle
    Rectangle r1;
    r1.length=10;
    r1.breadth=20;
    r1.AreaOfRectangle();
    
    return 0;
}