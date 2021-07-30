// C++ program to demonstrate Default Constructor

// Default Constructor - A constructor which has no argument is known as Default Constructor. It is invoked
// at the time of creating object.

// Note : Even if we do not define any constructor explicitly, the compiler will automatically provide a 
// Default Constructor implicitly.

#include<bits/stdc++.h>
using namespace std;

// class with Default Constructor defined
class Person1{
    public:
        string name1;
        int age1;
        Person1(){
            name1="abc";
            age1=10;
        }
};

// class with no Default Constructor defined
class Person2{
    public:
        string name2;
        int age2;
};

int main(){
    // Creating an object of class Person1
    Person1 p1;
    cout<<"Name1 : "<<p1.name1<<endl;
    cout<<" Age1 : "<<p1.age1<<endl;
    
    // Creating an object of class Person2
    Person2 p2;
    cout<<"Name2 : "<<p2.name2<<endl;
    cout<<" Age2 : "<<p2.age2<<endl;
    return 0;
}