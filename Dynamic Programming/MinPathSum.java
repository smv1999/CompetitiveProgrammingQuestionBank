import java.util.*;
import java.lang.Math;

public class MinPathSum
{
	//to find the minimum path
	public static  int minPathSum(int a[][])
	{  
		for (int i = 1; i < 4; i++) 
            a[i][0] = a[i-1][0] + a[i][0]; 
  
        for (int j = 1; j < 4; j++) 
            a[0][j] = a[0][j-1] + a[0][j];
        
		for(int i=1;i<4;i++)
		{
			for(int j=1;j<4;j++)
			{
				a[i][j] = Math.min(a[i-1][j], a[i][j-1]) + a[i][j]; 
			}
		}
		
		return a[3][3];
	}
	public static void main(String args[])
	{
		int a[][] = new int[4][4];
		Scanner sc = new Scanner(System.in);
		
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				a[i][j] = sc.nextInt();
			}
		}
		
		System.out.println("The sum of the minimum path is "+minPathSum(a));
		
	}
}