/*
    Inheritance : Inheritance in Java is a mechanism in which one object 
                  acquires all the properties and behaviors of a parent object. 
                  
    Multilevel Inheritance : When there is a chain of inheritance, it is known as multilevel inheritance.  
    
            class A
               ^
               |
               |
            class B
               ^
               |
               |
            class C
            
                   
*/

class base_class1
{
    int base_value;
    base_class1(int num)          // constructor
    {
        base_value = num;
    }
}

class base_class2 extends base_class1       
{
    int derived_value;
    base_class2(int base_val,int der_val)   // constructor
    {
        super(base_val);
        derived_value = der_val;
    }
    void base_display()
    {
        System.out.println("\nThis class derives base class 1");
        System.out.println("Base class variable value : "+ base_value);      // accessing base class variable
        System.out.println("Present class variable value : "+derived_value);
    }
}

class derived_class extends base_class2    
{
    int derived_value1;
    derived_class(int base_val1,int base_val2,int der_val)   // constructor
    {
        super(base_val1,base_val2);
        derived_value1 = der_val;
    }
    void display()
    {
       System.out.println("\nThis class derives base class 2 which inherits base class 1");
        System.out.println("Base class 1 variable value : "+ base_value);      // accessing base class variable
        System.out.println("Base class 1 variable value : "+ derived_value);      // accessing base class variable
        System.out.println("Present class variable value : "+derived_value1);
    }
}
public class Main
{
	public static void main(String[] args) {
	    
		derived_class obj = new derived_class(10,20,30);  // creating derived class object
		obj.base_display();
		obj.display();
	}
}
