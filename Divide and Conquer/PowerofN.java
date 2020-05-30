import java.util.*;
public class PowerofN
{
	public static void main(String args[])
	{
		int n,p;
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		p = sc.nextInt();
		
		int pow = 1;
		for(int i=1;i<=p;i++)
		{
			pow*=n;
		}
		System.out.println(pow);
	}
}