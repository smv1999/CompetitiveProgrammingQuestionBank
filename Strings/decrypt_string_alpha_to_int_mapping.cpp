/*
Src : LeetCode
--------------

Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:

1. Characters ('a' to 'i') are represented by ('1' to '9') respectively.
2. Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.
*/

class Solution {
public:
    string freqAlphabets(string s) {
        string ans="";
        for(int i=0;i<s.length();i++) {
            if(i+2<s.length() && s[i+2]=='#') {
                int ss=(s[i]-'0')*10+(s[i+1]-'0');
                ans+=char(ss+'a'-1);
                i+=2;
            }
            else  ans+=char(s[i]-'0'-1+'a');
        }
        return ans;
    }
};