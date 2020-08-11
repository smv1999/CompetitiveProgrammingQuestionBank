// Given a string of parantheses, braces and square brackets. We need to check whether they are balanced.

#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

bool isbalanced(string s)
{  stack<char> st;
    char x;

    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            st.push(s[i]);
            continue;
        }
         if (s.empty()) 
         {
           return false;
         }
           
        switch (s[i])
        {
        case ')':
            x = st.top();
            st.pop();
            if(s[i]=='{' || s[i]=='[')
                return false;
            break;
        case '}':
            x = st.top();
            st.pop();
            if(s[i]=='(' || s[i]=='[')
                return false;
            break;
        case ']':
            x = st.top();
            st.pop();
            if(s[i]=='(' || s[i]=='{')
                return false;
            break;
        }
    }
     return st.empty();

}

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    
    cout<<(isbalanced(s) ? "Yes" : "No");
    
    return 0;
}
