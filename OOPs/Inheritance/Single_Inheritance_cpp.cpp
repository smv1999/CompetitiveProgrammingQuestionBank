// C++ program to demonstrate Single Inheritance

// Single Inheritance - It is defined as the inheritance in which a derived class is inherited 
// from a single base class.

#include<bits/stdc++.h>
using namespace std;

// base class
class Animal{
   public:
    void eat(){
        cout<<"I can eat!"<<endl;
    }
    void sleep(){
        cout<<"I can sleep!"<<endl;
    }
};

// derived class
class Cat:public Animal{
   public:
    void meow(){
        cout<<"I can meow! meow! meow!"<<endl;
    }
};

int main(){
    // Create object of the Cat class
    Cat cat1;
    // Calling members of the base class
    cat1.eat();
    cat1.sleep();
    // Calling member of the derived class
    cat1.meow();
    return 0;
}