// C++ program to demonstrate Hybrid Inheritance

// Hybrid Inheritance - It is a combination of more than one type of Inheritance.

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

// derived class 1 from Animal
class Cat:public Animal{
   public:
    void meow(){
        cout<<"I can meow! meow! meow!"<<endl;
    }
};

// derived class 2 from Animal
class Cow:public Animal{
   public:
    void moo(){
        cout<<"I can moo! moo! moo!"<<endl;
    }
};

// derived from class Cat
class Kitten:public Cat{
   public:
    void info(){
        cout<<"I am a Kitten."<<endl;
    }
};

// Here in this code, we have Inherited Cow and Cat classes from Animal class; which is an example of 
// Hierarchical Inheritance. 

// Also we have Inherited Kitten class from Cat class which itself is Inherited from Animal 
// class; so, this is an example of Multilevel Inheritance. 

// So, we can say that together they(Hierarchical Inheritance & Multilevel Inheritance) form Hybrid 
// Inheritance

int main(){
    // Create object of Animal class
    Animal a1;
    cout<<"Animal Class:"<<endl;
    //Calling members of the Animal class
    a1.eat();  
    a1.sleep();
    
    // Create object of Cat class
    Cat cat1;
    cout<<"\nCat Class:"<<endl;
    //Calling members of the Animal class
    cat1.eat();  
    cat1.sleep();
    //Calling members of the Cat class
    cat1.meow();
    
    // Create object of Cow class
    Cow cow1;
    cout<<"\nCow Class:"<<endl;
    //Calling members of the Animal class
    cow1.eat();  
    cow1.sleep();
    //Calling members of the Cow class
    cow1.moo();
    
    // Create object of Kitten class
    Kitten k1;
    cout<<"\nKitten Class:"<<endl;
    //Calling members of the Animal class
    k1.eat();
    k1.sleep();
    //Calling members of the Cat class
    k1.meow();
    //Calling members of the Kitten class
    k1.info();
    return 0;
}