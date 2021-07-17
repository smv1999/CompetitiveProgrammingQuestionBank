/* Implementation of Isomorphic Strings problem
 * 
 * In this problem, we will be given two strings s and t, we need to determine if they
 * are isomorphic strings or not
 * 
 * Two strings s and t are isomorphic if the characters in s can be replaced to get t.

 * All occurrences of a character must be replaced with another character while preserving 
 * the order of characters. No two characters may map to the same character, but a character 
 * may map to itself.
 * 
 * Problem link: https://leetcode.com/problems/isomorphic-strings/
 * 
 */

import java.util.*;
import java.io.*;

class IsomorphicStrings
{    
    public boolean isIsomorphic(String s, String t) 
    {
         if(t.length() == s.length())
         {
             Map<Character, Character> sTMap = new HashMap<>();
             Map<Character, Character> tSMap = new HashMap<>();
             for(int i=0; i<t.length(); i++)
             {
                Character sChar = s.charAt(i);  
                Character tChar = t.charAt(i);
                 
                 if(sTMap.containsKey(sChar))
                 {
                     if(sTMap.get(sChar)!=tChar)
                        return false;
                 }
                 if(tSMap.containsKey(tChar))
                 {
                     if(tSMap.get(tChar)!=sChar)
                        return false;
                 }
                 sTMap.put(sChar, tChar);
                 tSMap.put(tChar, sChar);
             }
             return true;
         }
         //if s and t have different lengths they cannot be isomorphic
         else 
             return false;      
        }
        
    public static void main()
    {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        IsomorphicStrings obj = new IsomorphicStrings();
        System.out.println(obj.isIsomorphic(s,t));
    }
}

/*
Example 1:

Input: s = "egg", t = "add"
Output: true

Example 2:

Input: s = "foo", t = "bar"
Output: false

Example 3:

Input: s = "paper", t = "title"
Output: true

Time Complexity: O(n)
Space Complexity: O(n)

*/