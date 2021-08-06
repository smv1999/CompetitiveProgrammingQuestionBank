/*
 * Implementation of Maximum Array XOR problem from CodeChef
 * 
 * Problem name: Maximum Array XOR problem
 * Problem code: MAXARXOR
 * Problem link: https://www.codechef.com/START7C/problems/MAXARXOR
 * 
 * Approach:
 * 
 * Value of an array A  is defined as the sum of (A(i)⊕i) for all 0≤i<L, where ⊕ denotes bitwise xor operation.
 * You are given an integer N and an array A consisting of 2^N integers where A(i)=i for all 0≤i<2^N.
 * Example :
 *     - For N=1, you have an array A of length 2^1=2 and A=[0,1].
 *     - For N=2, you have an array A of length 2^2=4 and A=[0,1,2,3].
 * 
 * You can do at most K operations on this array. In one operation, you can choose 
 * two indices i and j (0≤i,j<2^N) and swap A(i) and A(j) (i.e. A(i) becomes A(j) and vice versa).
 *  
 * In this problem, we need to find the maximum value of array A after at most K operations.
 * Maximum value is only possible when the value (A(i)⊕i) is 2^N - 1 for each index. So to get maximum value for each index
 * we have to swap values according to the condition. But to get the solution of this problem we don't really need to swap.
 * We can find the maximum value of array without actually swapping them.
 * 
 * For every single swap we will maximize the value of two indexes in the array, so for K operations we can
 * maximize 2*K cells. But it is also possible that 2*K cells can be greater than 2^N so that's why
 * we will reduce it. It's given in the question that atmost K operations are allowed. So now we need
 * to multiply 2*K to 2^N - 1, to get the maximum value.
 * 
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
            
            //maximum value each cell of the array should have
            count=(long)Math.pow(2,N);
            
            //reducing value of K if it is greater than count/2
            //count/2 is the maximum number of swaps that can be performed to get the maximum value of Array
            if(K>=count/2)
            K=count/2;
            
            //finding out the maximum value of Array
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