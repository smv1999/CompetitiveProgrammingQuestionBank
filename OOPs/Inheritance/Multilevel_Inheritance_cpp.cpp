// C++ program to demonstrate Multilevel Inheritance

// Multilevel Inheritance - It is defined as the inheritance in which the derived class is inherited 
// from a base class which itself is inherited from another base class.

#include<bits/stdc++.h>
using namespace std;

// base class for Cat
class Animal{
   public:
    void eat(){
        cout<<"I can eat!"<<endl;
    }
    void sleep(){
        cout<<"I can sleep!"<<endl;
    }
};

// base class for Kitten, and derived from class Animal
class Cat:public Animal{
   public:
    void meow(){
        cout<<"I can meow! meow! meow!"<<endl;
    }
};

// derived from class Cat
class Kitten:public Cat{
   public:
    void info(){
        cout<<"I am a Kitten."<<endl;
    }
};

int main(){
    // Create object of Kitten class
    Kitten k1;
    //Calling members of the Kitten class
    k1.info();
    //Calling members of the Cat class
    k1.meow();
    //Calling members of the Animal class
    k1.eat();
    k1.sleep();
    return 0;
}