/* Title : Check whether the year entered is leap or not .
           If the entered year passes the conditions then it is considered to be as leap
           otherwise not .

*/
import java.util.Scanner ;
class   leap
{    int leap_year;

    leap (int a)   // Constructor
    {
        leap_year=a;
    }
    void check ()
    {
        if(leap_year%4==0)

        {
            if(leap_year%100==0)
            {
                if(leap_year%400==0)
                    {   System.out.println( " Leap year .");
                        System.out.println( " \n 366 days in " +leap_year+ " year . \n 29 days in month of Feb . \n"); }
                else
                    {
                        System.out.println( " Not Leap year "); }
            }
            else
            {   System.out.println( " Leap year .");
                System.out.println( " \n 366 days in " + leap_year+ " year . \n 29 days in month of Feb . \n");}
        }

        else
         {   System.out.println( " Not Leap year ");  }

    }

    public static void main (String[] args)
    {
        int year ;
        Scanner in=new Scanner(System.in);
        year=in.nextInt();
        leap Y = new leap(year);
        Y.check();

    }
}
/*
 1900
 Not Leap year .

 2000
 Leap year .

 366 days in year 2000 .
 29 days in month of Feb .

 */
