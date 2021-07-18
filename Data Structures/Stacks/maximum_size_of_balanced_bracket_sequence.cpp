/*
Given a sequence of brackets as a string, find maximum possible length of balanced bracket sequence.
string consists only two characters , one is '(' another is ')'
can be solved this with the help of stack data structure.
*/

#include <bits/stdc++.h>
using namespace std;

int balanced_bracket_sequence(string s, int string_size)
{
    int max_possible_balanced_bracket_sequence = 0;
    stack < char > st;
    for(int i = 0 ; i < string_size; i++)
    {
        /* Here if the current character of string is ' ( ' we will push it to stack
          and if the current character of string is ' ) ' and
          stack is not empty we will pop from the top of the stack
          increment the max_possible_balanced_bracket_sequence by 2
          every time.
        */
        if(s[i] == '(' )
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(!st.empty())
            {
                if(st.top()=='(')
                {
                    st.pop();
                    max_possible_balanced_bracket_sequence += 2;
                }
            }
        }
    }
    return max_possible_balanced_bracket_sequence;
}

int main()
{
    cout << "Enter the string : \n";
    string s;
    cin >> s;
    int string_size = (int)s.size();
    int max_balanced_bracket_sequence = balanced_bracket_sequence(s, string_size);
    cout << "Maximum possible length of balanced bracket sequence is : \n";
    cout << max_balanced_bracket_sequence << endl;
}

/*
Input and Output
Enter the string :
((()())
Maximum possible length of balanced bracket sequence is :
6
Time Complexity : O(N)
Space Complexity : O(N)
*/