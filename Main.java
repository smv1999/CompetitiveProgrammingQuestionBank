/* Title : To find the prime numbers present in the range . 
   Description : User need to enter the input number till which prime present can be printed.
*/
import java.util.Scanner ;
class Main 
{
public static void main(String[] ags)
{ Scanner read = new Scanner(System.in);
  int i, n;
  System.out.println("Enter the number till which you wish to finad all the prime no.s : ");   
  n=read.nextInt();                                                                              /* Prime number will be printed from 2 to n */
  System.out.println(" Prime numbers from 1 to "+n+ " are : ");
   for(i=2;i<=n;i++)
   { if((i==2)||(i==3)||(i==5)||(i==7)||(i==11)||(i==13)||(i==17))
      { System.out.println(i+"\t"); }
      else
      {  if((i%2!=0)&&(i%3!=0)&&(i%5!=0)&&(i%7!=0)&&(i%11!=0)&&(i%13!=0)&&(i%17!=0))
              System.out.println(i+"\t");  }
    }

} 
}
