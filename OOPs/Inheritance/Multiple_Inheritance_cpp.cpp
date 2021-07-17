// C++ program to demonstrate Multiple Inheritance

// Multiple Inheritance - It is defined as the inheritance in which a derived class is inherited 
// from two or more base classes.

#include<bits/stdc++.h>
using namespace std;

// base class 1
class TerrestrialAnimals{
   public:
    void walk(){
        cout<<"I can walk on land!"<<endl;
    }
};

// base class 2
class Birds{
   public:
    void fly(){
        cout<<"I can fly!"<<endl;
    }
};

// base class 3
class AquaticBirds{
   public:
    void swim(){
        cout<<"I can swim!"<<endl;
    }
};

// derived class
class Duck:public TerrestrialAnimals,public Birds,public AquaticBirds{
   public:
    void introduce(){
        cout<<"I am a Duck."<<endl;
    }
};

int main(){
    // Create object of the Duck class
    Duck d1;
    // Calling member of the derived class
    d1.introduce();
    // Calling members of the base class
    d1.walk();
    d1.fly();
    d1.swim();
    return 0;
}