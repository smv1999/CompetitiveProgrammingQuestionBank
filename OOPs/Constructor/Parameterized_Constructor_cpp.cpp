// C++ program to demonstrate Parameterized Constructor

// Parameterized Constructor - A constructor which has parameters is known as Parameterized Constructor. It is
// used to provide different values to distinct objects.

#include<bits/stdc++.h>
using namespace std;

// class with Parameterized Constructor
class Person{
    private:
        string name;
        int age;
    public:
        Person(string iname,int iage){
            name=iname;
            age=iage;
        }
        void display(){
            cout<<"Name : "<<name<<endl;
            cout<<"Age : "<<age<<endl;
        }
};

int main(){
    // Creating an object of class Person
    Person p("abc",10);
    p.display();
    return 0;
}