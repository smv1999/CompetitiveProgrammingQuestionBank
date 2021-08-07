// C++ program to demonstrate Friend Class

// Friend Class - A friend class can access the private and protected members of the class in which 
// it is declared as a friend.

#include<bits/stdc++.h>
using namespace std;

// class with Friend class
class Person{
    private:
        string name;
        int age;
    public:
        Person(string iname,int iage){
                name=iname;
                age=iage;
            }
        // class Introduce is a friend of class Person
        friend class Introduce;
};

// Friend class
class Introduce{
    public:
        void display(Person& x){
            cout<<"Name : "<<x.name<<endl;
            cout<<"Age : "<<x.age<<endl;
        }
};

int main(){
    // Creating an object of class Person
    Person p("abc",10);
    
    // Creating an object of class Introduce
    Introduce i;
    
    // Accessing private members of class Person through class Introduce
    i.display(p);
    return 0;
}