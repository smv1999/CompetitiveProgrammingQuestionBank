import java.util.*;
class Main{
public static int removePalindromeSub(String s) {
      
        char[] c=new char[s.length()];
        ArrayList<Character> al=new ArrayList<>();
        ArrayList<Character> bl=new ArrayList<>();
         
        for(int i=0;i<s.length();i++)
        {
            char a=s.charAt(i);
            al.add(a);
            bl.add(a);
            
        }
       
        Collections.reverse(bl);
        
        if(al.size()==0)
	{
            return 0;
	}
        
        else if(al.equals(bl))
        	{
           return 1;
        	}
        else
	{
            return 2;
	}         
}

	public static void main(String args[])
		{
			Scanner sc=new Scanner(System.in);
			System.out.println("Enter the string: ");
			int ans=0;
			String s=sc.next();
			ans=removePalindromeSub(s);
			System.out.println("Output: "+ans);

		}
	}