// C++ program to demonstrate Hierarchical Inheritance

// Hierarchical Inheritance - It is defined as the inheritance in which more that one derived classes 
// are inherited from a single base class.

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

// derived class 1
class Cat:public Animal{
   public:
    void meow(){
        cout<<"I can meow! meow! meow!"<<endl;
    }
};

// derived class 2
class Cow:public Animal{
   public:
    void moo(){
        cout<<"I can moo! moo! moo!"<<endl;
    }
};

int main(){
    // Create object of Cat class
    Cat cat1;
    cout<<"Cat Class:"<<endl;
    //Calling members of the base class
    cat1.eat();  
    cat1.sleep();
    //Calling members of the derived class
    cat1.meow();
    
    // Create object of Cow class
    Cow cow1;
    cout<<"\nCow Class:"<<endl;
    //Calling members of the base class
    cow1.eat();  
    cow1.sleep();
    //Calling members of the derived class
    cow1.moo();
    return 0;
}