/*
 Method overloading : If a class has multiple methods having same name but different in parameters or change in data type , it is known as Method Overloading.
*/

class method_overloading
{
    int res;
    void addition(int n1,int n2)
    {
        res = n1+n2;
        System.out.println("Addition with two parameters");
        System.out.println("Sum of "+n1+" and "+n2+" is "+res);
    }
    void addition(int n1,int n2,int n3)
    {
        res = n1+n2+n3;
        System.out.println("Addition with three parameters");
        System.out.println("Sum of "+n1+" , "+n2+" and "+n3+" is "+res);
    }
}
public class meth_ovel
{
    public static void main(String[] args)
    {
        method_overloading obj = new method_overloading();
        obj.addition(10,20);
        obj.addition(40,50,60);
    }
}
