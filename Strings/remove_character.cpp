/*
Given two strings string1 and string2, remove those characters from first string(string1) which are present in second 
string(string2). Both the strings are different and contain only lowercase characters.

NOTE: Size of  first string is always greater than the size of  second string( |string1| > |string2|).
*/

// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPresent(string string2, char ch)
    {
        for (int i = 0; i < string2.length(); i++)
        {
            if (string2[i] == ch)
            {
                return true;
            }
        }
        return false;
    }
    string removeChars(string string1, string string2)
    {
        string res = "";
        for (int i = 0; i < string1.length(); i++)
        {
            if (!isPresent(string2, string1[i]))
                res += string1[i];
        }
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string string1, string2;
        cin >> string1;
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1, string2) << endl;
    }
    return 0;
}
