// C++ program to demonstrate Shallow Copy Constructor

// Shallow Copy Constructor - Shallow Copy Constructor copies references to original objects. 
// The compiler provides a default copy constructor. Since, both objects refer to the same memory location, 
// the change made to one object will be reflected to the other object as well.

#include<bits/stdc++.h>
using namespace std;

class Person{
    
    private:
        char *name;
        
    public:
        // Parameterized Constructor
        Person(const char *iname){ 
            name=new char[20];
            strcpy(name,iname);
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
    
    // Creating an object of class Person (initializing it using Shallow Copy Constructor)
    cout<<"Object 2 initialization using Shallow Copy Constructor - "<<endl;
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