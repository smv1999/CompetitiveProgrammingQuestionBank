import java.io.*;
public class SquareRoot
{
    /* Time Comeplexity:-O(lg(n))
    Space Complexity:- O(1)**/
    public static void main(String args[])throws IOException
    {
        InputStreamReader read=new InputStreamReader(System.in);
        BufferedReader in=new BufferedReader(read);
        System.out.println("Enter your number");
        int n=Integer.parseInt(in.readLine());
        int x=n;
            if(x<=1)
                System.out.println(x);
            int sqrt=x/2;
            int quotient=x/sqrt;
            while(sqrt>quotient)
            {
                sqrt=(sqrt+quotient)>>1;//bitwise operator used to make the process faster
                quotient=x/sqrt;   
            }
            System.out.println("The square root of the number "+n+" is = "+sqrt);
        }
    }