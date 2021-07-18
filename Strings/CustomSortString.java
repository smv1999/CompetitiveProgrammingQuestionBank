/* Implementation of Custom Sort String program code using java
 * 
 * You are given two strings order and str. All the words of order are unique and 
 * were sorted in some custom order previously.

 * Permute the characters of str so that they match the order that order was sorted. 
 * More specifically, if a character x occurs before a character y in order, then x 
 * should occur before y in the permuted string.

 * Return any permutation of str that satisfies this property.
 * 
 * Problem link: https://leetcode.com/problems/custom-sort-string/
 * 
 */

import java.util.*;
import java.io.*;

class CustomSortString 
{
    // this function will return any permutation of str so that they match the order that
    // order is sorted
    public String customSortString(String order, String str) 
    {
       int []freq =new int[26];
        
        // determining the frequency of each character
        for(char c: str.toCharArray())
            freq[c-'a']++;
        
        StringBuilder ans = new StringBuilder();
        
        // appending the characters in order to ans
        for(char orderChar: order.toCharArray()) 
        {
            while(freq[orderChar-'a']>0)
            {
                ans.append(orderChar);
                freq[orderChar-'a']--;
            }
        }
        
        //Adding the rest of the characters
        for(int i=0;i<26;i++)
        {
            int freqC = freq[i];
            while(freqC>0)
            {
                ans.append((char)(i+'a'));
                freqC--;
            }
        }
        // returning the resultant string
        return ans.toString();
    }
    
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        CustomSortString obj = new CustomSortString();
        System.out.println(obj.customSortString(s,t));
    }
}

/*
 * Example 1:
 * 
 * Input: order = "cba", s = "abcd"
 * Output: "cbad"
 * Explanation: 
 * "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
 * Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
 * 
 * Example 2:
 * 
 * Input: order = "cbafg", s = "abcd"
 * Output: "cbad"
 * 
 * Time Complexity: O(order.length + str.length)
 */