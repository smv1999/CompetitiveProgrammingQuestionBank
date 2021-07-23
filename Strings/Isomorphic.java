// Java program to check if two strings are isomorphic.
/*Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character are replaced with another character while preserving the order of characters. No two characters map to the same character, but a character may map to itself. **/
import java.io.*;
import java.util.*;
// Time Complexity :- O(n) where n is the length of the string
class Isomorphic
{
    static int size = 256;
     
    // Function returns true if str1 and str2 are ismorphic
    static boolean areIsomorphic(String str1, String str2)
    {
        int m = str1.length();
        int n = str2.length();
         
        // Length of both strings must be same for one to one
        // corresponance
        if(m != n)
            return false;
             
        // To mark visited characters in str2
        Boolean[] marked = new Boolean[size];
        Arrays.fill(marked, Boolean.FALSE);
         
        // To store mapping of every character from str1 to
        // that of str2. Initialize all entries of map as -1.
        int[] map = new int[size];
        Arrays.fill(map, -1);
         
        // Process all characters one by on
        for (int i = 0; i < n; i++)
        {
            // If current character of str1 is seen first
            // time in it.
            if (map[str1.charAt(i)] == -1)
            {
                // If current character of str2 is already
                // seen, one to one mapping not possible
                if (marked[str2.charAt(i)] == true)
                    return false;
 
                // Mark current character of str2 as visited
                marked[str2.charAt(i)] = true;
 
                // Store mapping of current characters
                map[str1.charAt(i)] = str2.charAt(i);
            }
 
            // If this is not first appearance of current
            // character in str1, then check if previous
            // appearance mapped to same character of str2
            else if (map[str1.charAt(i)] != str2.charAt(i))
            return false;
        }
 
        return true;
    }
    // driver program
    public static void main (String[] args)
    {
        Scanner sc=new Scanner(System.in);
        String s,t;
        boolean res;
        System.out.println("Enter the strings");
        s=sc.nextLine();
        t=sc.nextLine();
        res = areIsomorphic(s,t);
        System.out.println(res);
    }
}
