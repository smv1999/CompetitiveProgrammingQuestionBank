/*
given an array find if there exists a subarray with sum equal to zero
Example:    [3,4,-1,4,3,-6,-7,2]
*/


// Time complexity: O(n^2)
import java.util.*;
public class HelloWorld{
public static void main(String []args){
    Scanner scan=new Scanner(System.in);
    int n=scan.nextInt();
    int []array=new int[n];
    boolean found=false;
    int i,j;
    for(i=0;i<n;i++)
        array[i]=scan.nextInt();
    for(i=0;i<n;i++)
    {
        int sum=0;
        for(j=i;j<n;j++)
        {
            sum=sum+array[j];
            if(sum==0)
            {
                found=true;
                break;
            }
        }
        if(found)
            break;
    }
    System.out.println("found"+found);
    }
}