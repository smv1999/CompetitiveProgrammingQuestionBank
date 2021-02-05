/*
Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an 
anagram of each other or not. An anagram of a string is another string that contains the same characters, only the 
order of characters can be different. For example, “act” and “tac” are an anagram of each other.
*/

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        unsigned long int lena = a.length();
        unsigned long int lenb = b.length();

        if (lena != lenb)
        {
            cout << "NO\n";
        }
        else
        {
            signed int cnt[26] = {0};
            for (int i = 0; i < lena; i++)
            {
                cnt[a[i] - 'a']++;
            }
            for (int i = 0; i < lenb; i++)
            {
                cnt[b[i] - 'a']--;
            }

            if (count(cnt, cnt + 26, 0) == 26)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }
    return 0;
}