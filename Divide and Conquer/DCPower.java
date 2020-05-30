import java.util.Scanner;

public class DCPower
{
	public static int power(int a,int b)
	{
		if(b==0)
			return 1;
		if(b%2==0)
		{
			return power(a,b/2)*power(a,b/2);
		}
		else {
			return power(a,b/2)*power(a,b/2)*a;
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
