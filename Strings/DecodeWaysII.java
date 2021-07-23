/*
 * Implementation of Decode Ways II problem from LeetCode(Hard)
 * 
 * Problem link: https://leetcode.com/problems/decode-ways-ii/
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

import java.util.*;
import java.io.*;

class DecodeWaysII 
{
    public int numDecodings(String s) 
    {
        long[] dp=new long[s.length()+1];
        dp[0]=1;
        dp[1]= decodeChar(s.charAt(0));
        for(int i=2;i<=s.length();i++)
        {
            
            char prev=s.charAt(i-2);
            char curr=s.charAt(i-1);
            
            //single character decoding
            dp[i] += dp[i-1]*decodeChar(curr);
            
            //double character decoding
            dp[i] += dp[i-2]*decodeTwoChars(prev, curr);
            
            dp[i] = dp[i]%1000000007;
        }
        return (int)dp[s.length()];
    }
    
    private int decodeChar(char c)
    {
        if(c=='*')
            return 9;
        else if(c=='0')
            return 0;
        
        return 1;
    }
    
    private int decodeTwoChars(char first, char second)
    {
        switch(first)
        {
            case '*':
                if(second == '*')
                    return 15;
                else if(second>='0' && second<='6')
                    return 2;
                else
                    return 1;
            
            case '1':
                if(second == '*')
                    return 9;
                else
                    return 1;
            
            case '2':
                if(second == '*')
                    return 6;
                else if(second >= '0' && second <= '6')
                    return 1;
                else
                    return 0;
            default:
                return 0;
        }
    }
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        DecodeWaysII ob = new DecodeWaysII();
        System.out.println(ob.numDecodings(str));
    }
}

/*
 * Example 1:

   Input: s = "*"
   Output: 9
   Explanation: The encoded message can represent any of the encoded messages "1", "2", "3", "4", "5", "6", "7", "8", or "9".
   Each of these can be decoded to the strings "A", "B", "C", "D", "E", "F", "G", "H", and "I" respectively.
   Hence, there are a total of 9 ways to decode "*".
   
   Example 2:

   Input: s = "1*"
   Output: 18
   Explanation: The encoded message can represent any of the encoded messages "11", "12", "13", "14", "15", "16", "17", "18", or "19".
   Each of these encoded messages have 2 ways to be decoded (e.g. "11" can be decoded to "AA" or "K").
   Hence, there are a total of 9 * 2 = 18 ways to decode "1*".
   
   Example 3:

   Input: s = "2*"
   Output: 15
   Explanation: The encoded message can represent any of the encoded messages "21", "22", "23", "24", "25", "26", "27", "28", or "29".
   "21", "22", "23", "24", "25", and "26" have 2 ways of being decoded, but "27", "28", and "29" only have 1 way.
   Hence, there are a total of (6 * 2) + (3 * 1) = 12 + 3 = 15 ways to decode "2*".
 */