/*
 Method overriding : If derived class has the same method as declared in the base class, it is known as method overriding.
*/

class base
{
    void display()
    {
        System.out.println("This is base class display method");
    }
}
class derived extends base
{
    void display()  //overriding base class display method
    {
        System.out.println("This is derived class display method");
    }
    
}
public class meth_overiding {
    public static void main(String[] args)
    {
       derived dob = new derived();
       base bob = new base();
       dob.display();
    }
}
