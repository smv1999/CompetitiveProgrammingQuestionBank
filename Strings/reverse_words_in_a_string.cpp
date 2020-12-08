/*
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.
*/

#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << reverseWords(s) << endl;
    }
}

string reverseWords(string s)
{

    string res = "";
    reverse(s.begin(), s.end());
    int k = 0;
    for (int ind = 0; ind < s.length(); ind++)
    {
        if (s[ind] == '.')
        {
            for (int ctr = ind - 1; ctr >= k; ctr--)
                res += s[ctr];
            res += '.';
            k = ind + 1;
        }
    }
    for (int ctr = s.length() - 1; ctr >= k; ctr--)
        res += s[ctr];
    return res;
}