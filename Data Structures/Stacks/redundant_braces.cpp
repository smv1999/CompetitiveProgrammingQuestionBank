// Given a string A of length n denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.
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

// Test Cases
// Input 1:
//     A = "((a + b))"
// Output 1:
//     1
//     Explanation 1:
//         ((a + b)) has redundant braces so answer will be 1.
// Input 2:
//     A = "(a + (a + b))"
// Output 2:
//     0
//     Explanation 2:
//         (a + (a + b)) doesn't have have any redundant braces so answer will be 0.

// Time complexity: O(n)
