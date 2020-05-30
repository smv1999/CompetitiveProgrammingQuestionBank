import java.util.*;

public class FibonacciTab{
	int fib_array[] = new int[100];
	public void initialize()
	{
	  fib_array[0]=0;
	  fib_array[1]=1;
	  for(int i=2;i<100;i++) {
		  fib_array[i]=-1;
	  }
	  
	}
	public int fibonacci(int n)
	{
	 for(int i=2;i<=n;i++)
	 {
		 fib_array[i] = fib_array[i-1]+fib_array[i-2];
	 }
	 return fib_array[n];
	}
	
	public static void main(String []args)
	{
		int n;
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		FibonacciTab fb = new FibonacciTab();
		fb.initialize();
		System.out.println("The nth fibonacci sequence is "+fb.fibonacci(n));
		
	}
}