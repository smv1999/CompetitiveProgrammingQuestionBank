// C++ program to demonstrate Constructor Overloading

// Constructor Overloading - It is defined as the concept of having more than one 
// constructors with different parameters in a class.

#include<bits/stdc++.h>
using namespace std;

// class with four Constructors (each with different parameters)
class Person{
    private:
        string name;
        int age;
    public:
        Person(){
            cout<<"Default Constructor"<<endl;
            name="no_name";
            age=0;
        }
        Person(string iname){
            cout<<"Constructor with name as parameter"<<endl;
            name=iname;
            age=0;
        }
        Person(int iage){
            cout<<"Constructor with age as parameter"<<endl;
            age=iage;
            name="no_name";
        }
        Person(string iname,int iage){
            cout<<"Constructor with name and age as parameter"<<endl;
            name=iname;
            age=iage;
        }
        void display(){
            cout<<"Name : "<<name<<endl;
            cout<<"Age : "<<age<<endl;
        }
};

int main(){
    // Creating an object of class Person (giving no parameter)
    Person p1;
    p1.display();
    cout<<endl;
    
    // Creating an object of class Person (giving name as parameter)
    Person p2("abc");
    p2.display();
    cout<<endl;
    
    // Creating an object of class Person (giving age as parameter)
    Person p3(10);
    p3.display();
    cout<<endl;
    
    // Creating an object of class Person (giving name and age as parameter)
    Person p4("abc",10);
    p4.display();
    
    return 0;
} 