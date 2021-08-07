  
/*
    Inheritance : Inheritance in Java is a mechanism in which one object 
                  acquires all the properties and behaviors of a parent object. 
                  
    Hierarchical Inheritance : When two or more classes inherits a single class, it is known as hierarchical inheritance. 
    
            class A
               ^
               |
   -----------------------------
   |                           |
class B                      class B
            
                   
*/

class base_class
{
    int base_value;
    base_class()          // constructor
    {
        base_value = 10;
    }
}

class derived_class1 extends base_class    
{
    int derived_value;
    derived_class1(int der_val)   // constructor
    {
        derived_value = der_val;
    }
    void display()
    {
        System.out.println("\nThis is derived class 1");
        System.out.println("Base class variable value : "+ base_value);      // accessing base class variable
        System.out.println("Derived class variable value : "+derived_value);
    }
}

class derived_class2 extends base_class      
{
    int derived_value;
    derived_class2(int der_val)   // constructor
    {
        derived_value = der_val;
    }
    void display()
    {
        System.out.println("\nThis is derived class 2");
        System.out.println("Base class variable value : "+ base_value);      // accessing base class variable
        System.out.println("Derived class variable value : "+derived_value);
    }
}
public class Main
{
	public static void main(String[] args) {
	    
		derived_class1 obj1 = new derived_class1(20);  // creating derived class1 object
		derived_class2 obj2 = new derived_class2(40);  // creating derived class2 object
		obj1.display();
		obj2.display();
	}
}
