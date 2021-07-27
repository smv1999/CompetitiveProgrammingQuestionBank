/*
   Title : Find the transpose of the matrix .
           User needs to provide the number of rows and columns .
           And the user needs to provide the elements of the matrix .
           User will get the transpose of the matrix .
           i.e Row elements become the column elements and vice- versa .
           **** Maximum 10 number of rows and columns can be only entered .
   */
import java.util.Scanner;
import java.lang.*;
class transpose
{
    final static int MAXLIMIT=10 ;
    private int row;
    private int col;
    int i ,j ;
    private double a[][];

    transpose(int rows , int cols)      //Constructor
    {
        row=rows ;
        col=cols ;
        a=new double[row][col] ;

    }

    Scanner in=new Scanner(System.in);

    public void get ()
    {
       System.out.println("\n Enter the elements : \n");
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                a[i][j]=in.nextDouble();
            }
        }

    }

    public void display ()
    {
        System.out.println( "\n Matrix A  " + row + " * " + col + " : \n") ;

        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                System.out.print(a[i][j]+ "\t") ;
            }
            System.out.println("\n") ;
        }
    }

     public void trans()
    {
        System.out.println( "\n\n The transpose of the given matrix : \n");
        System.out.println( "\n Matrix AT " + col + " * " + row+ " : \n") ;

        for(i=0;i<col;i++)
        {
            for(j=0;j<row;j++)
            {
                System.out.print(a[j][i]+ "\t") ;
            }
            System.out.println("\n") ;
        }
    }

    public static void main (String [] args  )
    {
      int rows , cols ;
      int opt;
      Scanner in=new Scanner(System.in);
      do
      { opt=0;
      System.out.println("\n Enter the total number of rows and columns respectively : \n");
       rows=in.nextInt();
       cols=in.nextInt();
       if(rows>MAXLIMIT|| cols>MAXLIMIT|| rows<1||cols<1)
       {
           System.out.println("\n  Invalid enteries ! \n  Remember ,  Maximum limit of rows and columns is 10 .\n");
           System.out.println("  Do you wish to continue ? \n  Press 1  if yes otherwise any to stop . \n");
           opt=in.nextInt();
       }

       else
       {

       transpose A = new transpose(rows , cols);
       A.get();
       A.display();
       A.trans();


       }
      } while(opt==1);

    }

}

/*

Enter the total number of rows and columns respectively :

13
1

  Invalid enteries !
  Remember ,  Maximum limit of rows and columns is 10 .

  Do you wish to continue ?
  Press 1  if yes otherwise any to stop .

1

 Enter the total number of rows and columns respectively :

3
2

 Enter the elements :

1
2
3
5
5
5

 Matrix A  3 * 2 :

1.0     2.0

3.0     5.0

5.0     5.0


 The transpose of the given matrix : \n");

 Matrix AT 2 * 3 :

1.0     3.0     5.0

2.0     5.0     5.0

*/
