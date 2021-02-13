// We can give as much input as we want to display it on output screen



import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int i=1;
        while(scan.hasNext())
        {
            System.out.println(i+" "+scan.nextLine());
            i++;
        }
    }
}