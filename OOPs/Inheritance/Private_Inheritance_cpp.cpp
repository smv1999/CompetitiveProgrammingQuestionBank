// C++ program to demonstrate Private Inheritance

// Private Inheritance - It is defined as the inheritance in which public members of the base class becomes private members
// of the derived class and also the protected members of the base class becomes private members of the derived class.

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
class Cat:private Animal{
   public:
    void animal_info(){
       sleep();
       eat();
    }
    void meow(){
        cout<<"I can meow! meow! meow!"<<endl;
    }
};

int main(){
    // Create object of the Cat class
    Cat cat1;
    // Calling public and protected members of the base class through derived class function (because they are private members in derived class)
    cat1.animal_info();
    // Calling member of the derived class
    cat1.meow();
    return 0;
}