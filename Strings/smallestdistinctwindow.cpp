//Two string given S and P, S being the main string and P being the substring or partial string.
//We need to find the window in main string S which has all the characters of P and display it.
//Time complexity - O(n^2)
//Space complexity - O(1)

#include<bits/stdc++.h>
using namespace std;

string smallestWindow(string s,string p){
    unordered_map<char,int> freqp;
    for(char c:p){
        freqp[c]++; //taking in every character of the partial string
    }
    int distinct=freqp.size();
    unordered_map<char,int> freqw;
    int count=0;

    int l=0,r=0,ans=INT_MAX,ri=-1,li=-1;
    bool flag=false;

    while(r<s.length()){
        while(r<s.length() && count<distinct){
            freqw[s[r]]++; //taking in the main string
            if(freqp.find(s[r])!=freqp.end() && freqw[s[r]]==freqp[s[r]]){
                count++; //if the char matches than count increased
            }
            r++; //increment uptil the main string length
        }
        while(l<=r && count==distinct){
            if(ans>r-l){
                ans=r-l;
                li=l;
                ri=r;
                flag=true; //setting the flag  true if window found
            }
            freqw[s[l]]--;
            if(freqp.find(s[l])!=freqp.end()&& freqw[s[l]]<freqp[s[l]]){
                count--; 
            }
            l++;
        }
    }
    if(!flag){
        return "";
    }
    string res=s.substr(li,ri-li);
    return res;
}

int main(){
    string s="timetopractice";
    string p="toc";
    cout<<smallestWindow(s,p);
    return 0;
}
