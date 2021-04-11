/*
Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, 
“(“, “)”, “[“, “]” are correct in exp.
*/
#include <bits/stdc++.h>
using namespace std;
bool isBalanced(string);

bool isBalanced(string expr)
{
    stack<int> st;
    int size = expr.length();

    for(int i=0;i<size;i++)
    {
        if(expr[i] == '(' || expr[i] == '[' || expr[i] == '{'){
            st.push(expr[i]);
        }
        else if(!st.empty() && ((st.top()=='(' && expr[i]==')') ||
        (st.top()=='[' && expr[i]==']') || (st.top()=='{' && expr[i]=='}'))){

            st.pop();
        }
        else return false;
    }

    return st.empty();
}

int main() {
	//code
	int t;
	string expr;
	cin>>t;
	while(t--)
	{
	    cin>>expr;
	    if(isBalanced(expr))
	        cout<<"balanced\n";
	    else cout<<"not balanced\n";
	}
	return 0;
}
