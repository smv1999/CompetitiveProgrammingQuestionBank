// Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.
// Check whether A has redundant braces or not.

#include <bits/stdc++.h> 
using namespace std; 

int redundantBraces(string A) {
 
    int n= A.length();
    stack <char> s;
    
    for(int i=0; i< n; i++)
    {
        //we'll push the operators and opening braces in the stack
        if(A[i]=='+' || A[i]=='-'|| A[i]=='/'|| A[i]=='*' || A[i]=='(' )
            s.push(A[i]);
        
     //when we encounter closing braces, we need to start popping
        if(A[i]==')')
        { 
         //if there are no operators, it means we have redundant braces for eg. ()
            if(s.top()=='(')
                return 1;
         
         //else we start popping till we encounter opening braces
         //count variable will keep count of number of operators enclosed within the braces
            int count=0;
            while(!s.empty() && s.top()!='(')
            {
                s.pop();
                count++;
            }
         //count=0 means we have something like (a) which has redundant braces
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
