/*

    Inheritance : Inheritance in Java is a mechanism in which one object 
                  acquires all the properties and behaviors of a parent object. 
                  
    Single Inheritance : When a class inherits another class, it is known as a single inheritance.
    
            class A
               ^
               |
               |
            class B
                   

*/

class base_class
{
    int base_value;
    base_class(int num)          // constructor
    {
        base_value = num;
    }
}

class derived_class extends base_class       // single inheritance
{
    int derived_value;
    derived_class(int der_val,int base_val)   // constructor
    {
        super(base_val);                      //calling base class constructor 
        derived_value = der_val;
    }
    void display()
    {
        System.out.println("Base class variable value : "+ base_value);      // accessing base class variable
        System.out.println("Derived class variable value : "+derived_value);
    }
}
public class Main
{
	public static void main(String[] args) {
	    
		derived_class obj = new derived_class(10,20);  // creating derived class object
		obj.display();
	}
}
