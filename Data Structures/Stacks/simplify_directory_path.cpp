// Given a string A representing an absolute path for a file (Unix-style).
// Return the string A after simplifying the absolute path.
// Note:
// Absolute path always begin with  ( root directory ).
// Path will not have whitespace characters.

#include <bits/stdc++.h> 
using namespace std; 

string simplifyPath(string A)
{

    A+="/";
    string loc="", ans="";
    vector<string> v;
    stack<string>s;
    int n= A.length();
    
    // spliting the path with / as delimeter
    for(int i=0; i<n; i++)
    {
        if(A[i]=='/')
        {
            if(loc!="" )
                v.push_back(loc);
            loc="";
        }
        else 
        {
            loc+= A[i];
        }
    }
    
    //simplifying the path ans storing in stack
    for(auto x: v) 
    {
        if(x!="." && x!="..")
            s.push(x);
        else if( x==".." && s.size()!=0)
            s.pop();

    }
    if(s.empty()) 
        ans="/";
        
    //since the path is reversed in stack s, we are reversing it again using fs stack
    stack< string > fs;
    while(!s.empty()) 
        {
            fs.push(s.top());
            s.pop();
        }
        
    //printing the simplified path 
    while (!fs.empty() ) 
    {
        ans+="/"+fs.top();
        fs.pop();
    }
    return ans;
}


int main() 
{
    string str;
    cin>>str;
    cout<<simplifyPath(str);
return 0;

}  
