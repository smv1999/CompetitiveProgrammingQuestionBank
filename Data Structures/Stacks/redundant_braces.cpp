// Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.
// Check whether A has redundant braces or not.

#include <bits/stdc++.h> 
using namespace std; 

int redundantBraces(string A) {
 
    int n= A.length();
    stack <char> s;
    
    for(int i=0; i< n; i++)
    {
        if(A[i]=='+' || A[i]=='-'|| A[i]=='/'|| A[i]=='*' || A[i]=='(' )
            s.push(A[i]);
            
        if(A[i]==')')
        { 
            if(s.top()=='(')
                return 1;
 
            int count=0;
            while(!s.empty() && s.top()!='(')
            {
                s.pop();
                count++;
            }
            if(count==0) 
                return 1;
            s.pop();
        }
    }
 
        return 0;
} 

int main() 
{
    string str;
    cin>>str;
    if(redundantBraces(str))
        cout<<str+" has redundant braces";
    else 
        cout<<str+" doesn't have any redundant braces";
return 0;

}  
