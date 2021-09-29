// C++ program to demonstrate Abstraction

// Abstraction - An abstraction is a way of providing only essential details to the outside world and hiding
// the implemetation details which are unnecessary.

#include<bits/stdc++.h>
using namespace std;

// class 1 (binds data and functions for calculating area of a triangle)
class Triangle{
    private:
        // User doesn't needs to know how area is being calculated 
        int base,height;
        int AreaOfT;
        void AreaOfTriangle(){
            AreaOfT=(base*height)/2;
        }
    public:
        // User only needs to give input and get the result
        Triangle(int ibase,int iheight){
            base=ibase;
            height=iheight;
            AreaOfTriangle();
        }
        void displayT(){
           cout<<"Area of triangle with base "<<base<<" and height "<<height<<" is "<<AreaOfT<<endl;
        } 
};

// class 2 (binds data and functions for calculating area of a rectangle)
class Rectangle{
    private:
        // User doesn't needs to know how area is being calculated 
        int length,breadth;
        int AreaOfR;
        void AreaOfRectangle(){
            AreaOfR=length*breadth;
        }
    public:
        // User only needs to give input and get the result
        Rectangle(int ilength,int ibreadth){
            length=ilength;
            breadth=ibreadth;
            AreaOfRectangle();
        }
        void displayR(){
            cout<<"Area of rectangle with length "<<length<<" and breadth "<<breadth<<" is "<<AreaOfR<<endl;
        }
};

int main(){
    // Create an object of class Triangle
    Triangle t1(10,20);
    t1.displayT();
    
    // Create an object of class Rectangle
    Rectangle r1(10,20);
    r1.displayR();
    
    return 0;
}