import java.util.*;

// Find the number of binary digits in binary representation of a positive decimal number.
class NumberofBinDigits {
    
    public static void main(String[] args) {
        int n,count=0;
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();

        while(n>0)
        {
            count+=1;
            n = n/2;
        }

        System.out.println(count);
        sc.close();
    }
}