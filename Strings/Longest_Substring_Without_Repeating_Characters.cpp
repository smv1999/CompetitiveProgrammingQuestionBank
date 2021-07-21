/*  Longest substring without repeating characters 
    Given a string s, find the length of the longest substring without repeating characters. 
    Solution is to use sliding window concept */
#include<bits/stdc++.h>
using namespace std;
    int lengthOfLongestSubstring(string s) {  // Function to implement length Of Longest Substring
        int i=0,j=0,f=1,ans=0;
        unordered_map<int,int>m;
        while(j<s.length()){
            auto it=m.find(s[j]);
            if(it==m.end()){
                m.insert(pair<int,int>(s[j],1)); //  insert new characters in the map 
                j+=1;
            }
            else{
                if(f==1){  
                m[s[j]]+=1; // As a sliding window increase frequency of the character 
                }
                if(m[s[j]]>1){ // If frequency is grater then 1 move starting point of window 
                    m[s[i]]-=1; 
                    i+=1;
                    f=0;
                }
                else{
                    j+=1; // Move ending point of window
                    f=1;
                }
            }
            ans=max(ans,j-i); 
        }
            return ans;
    }
int main(){
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s);
}