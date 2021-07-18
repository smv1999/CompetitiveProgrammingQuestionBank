/* Title : Operations on matrices .

   Description : User need to enter the elements of the matrix A and B .
                 Operations will be done on the matrices : 1.To add  2.To Subtract
                 3.To multiply . User need to choose it.
                 The maximum limit of total number of rows and columns : 8
                 You can't generate the matrices having more than 8 number of rows and columns .

                 Here , if the both matrices are of square matrix only then the multiplication can be
                 done . i.e Rows(A)==Columns(B) equal fOR BA multiplication
                     and    Rows(B)==Columns(A) equal fOR BA multiplication . multiplication rule.
                 This is done here to maintain the formate of the code and to maintain the
                 multiplication of matices .
                 Addition and subtraction are done as the Matrix A and B both are having same number of rows and columns .
*/
import java.util.Scanner;
public class matrices
{
    public final static int MAXLIMIT=8;
	public static void main(String[] args)
 {
	Scanner input=new Scanner (System.in);
	int opt ;

	 do                                                      // Enter the data needed  .
	   {
	System.out.println(" Enter the number of rows and columns (Maximum limit is 8 ) : \n");
	int row=input.nextInt();
	int col=input.nextInt();
	double a[][]=new double[row][col];
	double b[][]=new double[row][col];


	if((row>MAXLIMIT)||(col>MAXLIMIT)||(row<1)||(col<1))
	{ System.out.println("\n Invalid Enteries !! \n Please try again later .");
	  System.exit(0);
	}
	else
		 { System.out.println("\n ENTER THE ELEMENTS OF MATRIX A ");                 // Enter Matrix A

       	   for(int i=0;i<row;i++)
     {
		    for(int j=0;j<col;j++)

		    { a[i][j]=input.nextDouble();

		    } }


	  System.out.println("\n ENTER THE ELEMENTS OF MATRIX B");                      // Enter Matrix B

 	   for(int i=0;i<row;i++)
{
	    for(int j=0;j<col;j++)

	    { b[i][j]=input.nextDouble(); } }

   }

      System.out.println();

	 System.out.println(" ELEMENTS OF MATRIX A");            // Matrix A
	   for(int i=0;i<row;i++)
    {
		    for(int j=0;j<col;j++)
		    { System.out.print( a[i][j]+ "\t");  }
		      System.out.println("\n");
     }

        System.out.println();

	   System.out.println(" ELEMENTS OF MATRIX B");           // Matrix B
	   for(int i=0;i<row;i++)
	    {
			    for(int j=0;j<col;j++)
			    { System.out.print( b[i][j]+ "\t");  }
			      System.out.println("\n");
	     }



	   int i, j ;
	   System.out.println("\n1.Add \n2.Subtraction \n3.Multiplication   ");
	   opt=input.nextInt();
	   System.out.println();

	   switch(opt)
	   {
         case 1	:   double add[][]=new double [row][col];                  // Addition of matrices A and B .
	                System.out.println("Addition of matrix A and B : ");
	                for(i=0;i<row;i++)
                    {
	                      for(j=0;j<col;j++)
	                {     add[i][j]=a[i][j] + b[i][j];
	                      System.out.print(add[i][j] +"\t");  }
	                       System.out.println(); }
	               System.out.println();
        break ;

        case 2	:    double sub1[][]=new double [row][col];             // Subtraction of matrix A from B .
	                 System.out.println("Subtraction of matrix A from B : ");
	                 for(i=0;i<row;i++)
                   {
	                     for(j=0;j<col;j++)
	               {       sub1[i][j]= -a[i][j] + b[i][j];
	                       System.out.print(sub1[i][j] +"\t");  }
	                       System.out.println(); }

	                  System.out.println();

                        double sub2[][]=new double [row][col];              // Subtraction of matrix B from A .
	                    System.out.println("Subtraction of matrix B from A : ");
	                    for(i=0;i<row;i++)
                   {
	                    for(j=0;j<col;j++)
	               {    sub2[i][j]= a[i][j] - b[i][j];
	                    System.out.print(sub2[i][j] +"\t");  }
	                    System.out.println();  }
	               System.out.println();
	     break ;


	    case 3 :
	                    System.out.println("Matrix multiplication is not commutative always.\n i.e A*B is not equals to B*A. \n");
	                   if(row==col)
	               {
	                   // Multiply  matrix A and B . i.e : AB
	                    int k;
	                    double sum=0 ;
	                    double mul1[][]=new double [row][col];
	                    System.out.println(" Multiplication of matrices A and B : AB ");
	                    for(i=0;i<row;i++)
                     {
	                    for(j=0;j<col;j++)
	                   {
	                    for(k=0;k<col;k++)
	                   {  mul1[i][j]=mul1[i][j] + a[i][k]*b[k][j]; }
	                      }
	                    System.out.println();     }

	                 for(i=0;i<col;i++)
	                   {
	                    for(j=0;j<col;j++)
	                    {  System.out.print(mul1[i][j] +"\t");  }
	                        System.out.println();
	                   }
	                 System.out.println();


	                 // Multiply matrix B and A . i.e : BA

	                 double mul2[][]=new double [row][col];
	                 System.out.println(" Multiplication of matrices A and B : BA  ");
	                 for(i=0;i<row;i++)
                     {
	                    for(j=0;j<col;j++)
	                   {
	                    for(k=0;k<col;k++)
	                   {  mul2[i][j]=mul2[i][j] + b[i][k]*a[k][j]; }
	                      }
	                    System.out.println();     }

	                 for(i=0;i<col;i++)
	                   {
	                    for(j=0;j<col;j++)
	                    {  System.out.print(mul2[i][j] +"\t");  }
	                        System.out.println();
	                   }
	               }
	                 else
	                     {
	                         System.out.println(" Multiplication is not valid . \n");
	                     }
	                System.out.println();
	          break ;
	   }

	   System.out.println(" Do you wish to continue ? \n1.Yes 2.No\n" );
	   opt=input.nextInt();
	   }while(opt!=2);

}}


/*

Enter the number of rows and columns (Maximum limit is 8 ) :

2
2

 ENTER THE ELEMENTS OF MATRIX A
1
2
3
4

 ENTER THE ELEMENTS OF MATRIX B
2
2
2
2

 ELEMENTS OF MATRIX A
1.0     2.0

3.0     4.0

 ELEMENTS OF MATRIX B
2.0     2.0

2.0     2.0


1.Add
2.Subtraction
3.Multiplication
1

Addition of matrix A and B :
3.0     4.0
5.0     6.0

 Do you wish to continue ?
1.Yes 2.No
1

 Enter the number of rows and columns (Maximum limit is 8 ) :

3
3

 ENTER THE ELEMENTS OF MATRIX A
12
13
14
15
16
17
18
19
20

 ENTER THE ELEMENTS OF MATRIX B
2
2
2
2
2
2
2
2
2

 ELEMENTS OF MATRIX A
12.0    13.0    14.0

15.0    16.0    17.0

18.0    19.0    20.0

 ELEMENTS OF MATRIX B
2.0     2.0     2.0

2.0     2.0     2.0

2.0     2.0     2.0


1.Add
2.Subtraction
3.Multiplication
2

Subtraction of matrix A from B :
-10.0   -11.0   -12.0
-13.0   -14.0   -15.0
-16.0   -17.0   -18.0

Subtraction of matrix B from A :
10.0    11.0    12.0
13.0    14.0    15.0
16.0    17.0    18.0

 Do you wish to continue ?
1.Yes 2.No
1

 Enter the number of rows and columns (Maximum limit is 8 ) :

2
2

 ENTER THE ELEMENTS OF MATRIX A
1
2
44
45

 ENTER THE ELEMENTS OF MATRIX B
2
2
3
33

 ELEMENTS OF MATRIX A
1.0     2.0

44.0    45.0

 ELEMENTS OF MATRIX B
2.0     2.0

3.0     33.0


1.Add
2.Subtraction
3.Multiplication
3

Matrix multiplication is not commutative always.
 i.e A*B is not equals to B*A .

 Multiplication of matrices A and B : AB


8.0     68.0
223.0   1573.0

 Multiplication of matrices A and B : BA


90.0    94.0
1455.0  1491.0

 Do you wish to continue ?
1.Yes 2.No
2
*/
