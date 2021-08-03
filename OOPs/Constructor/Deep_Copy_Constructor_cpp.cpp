// C++ program to demonstrate Deep Copy Constructor

// Deep Copy Constructor - Deep copy Constructor allocates separate memory for copied information. So the source and copy 
// are different. Any changes made in one memory location will not affect the other location. 

#include<bits/stdc++.h>
using namespace std;

// class with a Deep Copy Constructor
class Person{
    
    private:
        char *name;
        
    public:
        // Constructor
        Person(const char *iname){ 
            name=new char[20];
            strcpy(name,iname);
        }
        // Deep Copy Constructor
        Person(const Person &p1){
            name=new char[20];
            strcpy(name,p1.name);
        }
        void concatenate(const char *str){
            strcat(name,str);
        }
        void display(){
            cout<<"Name : "<<name<<endl;
        }
};

int main(){
    // Creating an object of class Person (initializing it using Parameterized Constructor)
    cout<<"Object 1 initialization - "<<endl;
    Person p1("abc");
    p1.display();
    cout<<endl;
    
    // Creating an object of class Person (initializing it using Deep Copy Constructor)
    cout<<"Object 2 initialization using Deep Copy Constructor - "<<endl;
    Person p2=p1;
    p2.display();
    cout<<endl;
    
    // Making some changes to original object (Object 1)
    p1.concatenate("xyz");
    
    cout<<"Object 1 after making changes to Object 1 - "<<endl;
    p1.display();
    cout<<endl;
    
    cout<<"Object 2 after making changes to Object 1 - "<<endl;
    p2.display();
    
    return 0;
} 