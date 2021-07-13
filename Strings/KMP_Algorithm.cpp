//KMP Algorithm - Pattern Searching Algorithm

#include <iostream>
using namespace std;

// Function to implement the KMP algorithm
void KMP(string t, string p)
{
    int tlen = t.length();
    int plen = p.length();

    // if `text` is an empty string
    if (plen == 0)
    {
        cout << "The pattern at index 0";
        return;
    }

    // if X's length is less than that of Y's
    if (tlen < plen)
    {
        cout << "Pattern not found";
        return;
    }

    // `next[i]` stores the index of the next best partial match
    int next[plen + 1];

    for (int i = 0; i < plen + 1; i++) {
        next[i] = 0;
    }

    for (int i = 1; i < plen; i++)
    {
        int j = next[i + 1];

        while (j > 0 && p[j] != p[i]) {
            j = next[j];
        }

        if (j > 0 || p[j] == p[i]) {
            next[i + 1] = j + 1;
        }
    }

    for (int i = 0, j = 0; i < tlen; i++)
    {
        if (t[i] == p[j])
        {
            if (++j == plen) {
                cout << "The pattern occurs at index " << i - j + 1 << endl;
            }
        }
        else if (j > 0)
        {
            j = next[j];
            i--;    // since `i` will be incremented in the next iteration
        }
    }
}

// Program to implement the KMP algorithm in C++
int main()
{
    string text;
    cout<<"Enter text: ";
    cin>>text;
    string pattern;
    cout<<"Enter pattern: ";
    cin>>pattern;
    KMP(text, pattern);
    return 0;
}
