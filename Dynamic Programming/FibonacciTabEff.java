import java.util.*;

public class FibonacciTabEff{
	
	public static int fibonacci(int n)
	{
		int a,b,c=0;
		a=0;
		b=1;
		for(int i=2;i<=n;i++)
		{
			c = a + b;
			a = b;
			b = c;
			
		}
		return c;
	}
	public static void main(String args[])
	{
		int n;
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		System.out.println("The nth fibonacci sequence is "+fibonacci(n));
	}
}