/* 
Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
Example 1:
Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:
Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/
#include<bits/stdc++.h>
using namespace std;
    int longestSubstring(string s, int k) {
        unordered_map<int,int>m; // Keep Track of frequency of each character
        for(int i=0;i<s.length();i++)
            m[s[i]]+=1;
        int i=0,left=s.length(),rit=0;
        while( i < s.length() && k <= m[s[i]]){ // Sliding it till we need our first string
            i++;
        }
        if(i==(s.length()))
            return s.length();
        if(s.length()==0)
            return 0;
        if(i<s.length())
         left=longestSubstring(s.substr(0,i),k); 
        while(i<s.length() && m[s[i]]<k) // to check if more continious characters are having count less than k   
            i++;
        if((s.length()-i-1)>0)
         rit=longestSubstring(s.substr(i,s.length()),k);   
        int ans=max(left,rit);
        return ans;
    }
    int main(){
        string s;
        cin>>s;
        int k;
        cin>>k;
        cout<<longestSubstring(s,k);
        return 0;
    }