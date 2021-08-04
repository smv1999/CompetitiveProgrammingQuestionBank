/*
 * Implementation of Maximum Array XOR problem from CodeChef
 * 
 * Problem name: Maximum Array XOR problem
 * Problem code: MAXARXOR
 * Problem link: https://www.codechef.com/START7C/problems/MAXARXOR
 */
import java.util.*;
import java.lang.*;
import java.io.*;

class MaximumArrayXOR
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        
        while(t-->0)
        {
            long count=0;
            long N=sc.nextInt();
            long K=sc.nextInt();
            
            count=(long)Math.pow(2,N);
            
            if(K>=count/2)
            K=count/2;
            
            count=(count-1)*K*2;
        
            System.out.println(count);
            
        }
    }
}
/*
 * Sample Input 1 
 * 3
 * 2 0
 * 2 1
 * 10 100
 * 
 * Sample Output 1 
 * 0
 * 6
 * 204600
 * 
 * Time complexity: O(n)
 */