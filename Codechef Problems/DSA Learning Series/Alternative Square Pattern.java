/* You're given a number N. Print the first N lines of the below-given pattern.

1 2 3 4 5
10 9 8 7 6
11 12 13 14 15
20 19 18 17 16
21 22 23 24 25
30 29 28 27 26
Input:
First-line will contain the number N.
Output:
Print the first N lines of the given pattern.

Constraints
1≤N≤200
Sample Input 1:
4
Sample Output 1:
1 2 3 4 5
10 9 8 7 6
11 12 13 14 15
20 19 18 17 16
Sample Input 2:
2
Sample Output 2:
1 2 3 4 5
10 9 8 7 6
EXPLANATION:
In the first example, we'll print the first 4 lines of the given pattern.
In the second example, we'll print the first 2 lines of the given pattern. */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc= new Scanner(System.in);
		int n= sc.nextInt();
		for (int i=1; i<=n; i++)
		{
		    if(i%2!=0)
		    {
		        for(int j=(5*(i-1)+1);j<=(5*i);j++)
		        {
		            System.out.print(j+" ");
		        }
		         System.out.println();
		    }
		    else{
		        for(int j=(5*i);j>=(5*(i-1)+1);j--)
		    {
		            System.out.print(j+" ");
		    }
		     System.out.println();
		    }
		   
		    
		}
	}
}
