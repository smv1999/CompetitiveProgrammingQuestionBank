import java.util.Scanner;

public class PowerMem
{
	public static int power(int a,int b)
	{ int halfpower;
		if(b==0)
			return 1;
		if(b%2==0)
		{   halfpower = power(a,b/2);
			return halfpower*halfpower;
		} 
		else {
			halfpower = power(a,b/2);
			return halfpower*halfpower*a;
		}
	}
	public static void main(String args[])
	{
		int a,b;
		Scanner sc = new Scanner(System.in);
		
		a = sc.nextInt();
		b = sc.nextInt();
		
		sc.close();
		
		System.out.println(power(a,b));
		
	}
}