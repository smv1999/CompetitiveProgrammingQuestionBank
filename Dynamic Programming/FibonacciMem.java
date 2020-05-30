import java.util.*;

public class FibonacciMem {
	final int max=100;
	int fib_array[]= new int[max];
	
	public void initialize()
	{
		fib_array[0]=0;
		fib_array[1]=1;
		for(int i=2;i<max;i++)
		{
			fib_array[i]=-1;
		}	
	}
	public int fibonacci(int n)
	{
		
		if(fib_array[n]!=-1)
			return fib_array[n];
		else
			{
			  fib_array[n] = fibonacci(n-1)+fibonacci(n-2);
			  return fib_array[n];
			}
		    
	}
	
	public static void main(String []args)
	{
		int n;
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		FibonacciMem fb = new FibonacciMem();
		fb.initialize();
		System.out.println("The nth fibonacci sequence is "+fb.fibonacci(n));
	}
}