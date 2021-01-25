/*
Src : LeetCode
--------------

You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b
be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s 
contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.
*/

class Solution
{
public:
    bool isVowel(char ch)
    {
        switch (ch)
        {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return true;
        default:
            return false;
        }
    }
    bool halvesAreAlike(string s)
    {
        int count1 = 0, count2 = 0;
        int n = s.length();
        int half = n / 2;
        for (int i = 0; i < half; i++)
        {
            if (isVowel(s[i]))
                count1++;
        }
        for (int i = half; i < n; i++)
        {
            if (isVowel(s[i]))
                count2++;
        }
        return count1 == count2;
    }
};