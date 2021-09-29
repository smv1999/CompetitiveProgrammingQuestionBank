// C++ program to demonstrate Destructor

// Destructor - A destructor is function which is called automatically when an object goes out of scope.
// It destructs the objects of classes.

#include<bits/stdc++.h>
using namespace std;

// class with Destructor
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
        // We don't need to call Destructor as it will be invoked automatically when the object goes out of scope
        ~Person(){
            cout<<"Destructor Called"<<endl;
        }
};

int main(){
    // Creating an object of class Person
    Person p("abc",10);
    p.display();
    return 0;
}