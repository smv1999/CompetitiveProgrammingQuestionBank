// C++ program to demonstrate Public Inheritance

// Public Inheritance - It is defined as the inheritance in which public members of the base class becomes public members
// of the derived class and protected members of the base class becomes protected members of the derived class.

//Note : Private members are not inherited.

#include<bits/stdc++.h>
using namespace std;

// base class
class Animal{
   private:
   void info(){
       cout<<"I am an animal !!"<<endl;
   }
   protected:
   void sleep(){
        cout<<"I can sleep!"<<endl;
    }
   public:
    void eat(){
        cout<<"I can eat!"<<endl;
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
    // Note : We can't access the Protected members here. Protected members are not accessible outside the base or derived class.
    // Calling public members of the base class (also the public member of the derived class)
    cat1.eat();
    // Calling member of the derived class
    cat1.meow();
    return 0;
} 