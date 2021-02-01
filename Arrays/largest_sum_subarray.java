/*
Subsequence is that array in which eements are missing in between two elements but continuous subarray
in which any element is not missing.
Problem:    We have to find continuous subarray whose sum is largest.
Example:    [-3,2,4,-1,2,3,-2]
            Max subarray=[2,4,-1,2,3]
            sum=10
*/


// Time complexity --> O(n^2)

import java.util.*;
public class HelloWorld{
public static void main(String []args){
    int n;
    Scanner scan=new Scanner(System.in);
    n=scan.nextInt();
    int []ar=new int[n];
    int []sum=new int[n];
    int i,j,count=0,k,max;
    max=Integer.MIN_VALUE;
    for(i=0;i<n;i++)
        ar[i]=scan.nextInt();        
    sum[0]=ar[0];
    for(i=1;i<n;i++)
        sum[i]=sum[i-1]+ar[i];
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            count=0;
            count=sum[j]-sum[i]+ar[i];
            if(max<count)
                max=count;
        }
    }
    System.out.println(max);
    }
}