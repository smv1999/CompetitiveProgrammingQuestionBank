// C++ program to demonstrate Copy Constructor

// Copy Constructor - It is a member function that initializes an object using another object of same class.

#include<bits/stdc++.h>
using namespace std;

// class with a Copy Constructor
class Person{
    private:
        string name;
        int age;
    public:
        // Default Constructor
        Person(){
            name="abc";
            age=20;
        }
        // Copy Constructor
        Person(const Person &p1){
            name=p1.name;
            age=p1.age;
        }
        void display(){
            cout<<"Name : "<<name<<endl;
            cout<<"Age : "<<age<<endl;
        }
};

int main(){
    // Creating an object of class Person (initializing it using Default Constructor)
    Person p1;
    p1.display();
    cout<<endl;
    
    // Creating an object of class Person (initializing it using Copy Constructor)
    Person p2=p1;
    p2.display();
    
    return 0;
} 