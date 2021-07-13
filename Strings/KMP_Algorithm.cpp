/*KMP Algorithm - Pattern Searching Algorithm

KMP Algorithm is also called as Knuth, Morris, and Pratt string searching algorithm
This algorithm uses the previous comparison data.
It uses a partial match table to analyze the pattern structure. 
The goal of the table is to allow the algorithm not to match any character of pattern more than once. 
The basic idea behind KMP’s algorithm is: 
whenever we detect a mismatch (after some matches), we already know some of the characters in the text of the next window.
We take advantage of this information to avoid matching the characters that we know will anyway match. 
We need to know about proper prefixes and proper suffixes first.

Proper prefix - All the characters in a string, with one or more cut off the end. 
“C”, “Co”, “Cod”, and “Codi” are all the proper prefixes of “Coding”.

Profer suffix - All the characters in a string, with one or more cut off the beginning. 
“adrid”, “drid”, “rid”, “id”, and “d” are all proper suffixes of “Madrid”.

The value of the partial table is the "length of the longest proper prefix that matches a proper suffix".

Pseudocode - 
if table[partial_match_length] > 1:
    skip ahead by partial_match_length - table[partial_match_length - 1] characters
else:
    don’t get to skip ahead by partial_match_length - table[partial_match_length - 1] characters. See next partial match.

Let’s say we’re matching the pattern “abababca” against the text “bacbababaabcbab”.
Here’s our partial match table again for easy reference

char:  | a | b | a | b | a | b | c | a |
index: | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 
value: | 0 | 0 | 1 | 2 | 3 | 4 | 0 | 1 |

Example - 
1. The first match is at index 1.
bacbababaabcbab
 |
 abababca
Hence partial_match_length = 1
See the next partial match and so on.
Repeat the steps till the last partial match is found.

Time Complexity :
Assuming n is the length of text and m is the length of pattern.
It can search for a pattern in O(n) time as it never re-compares a text symbol that has matched a pattern symbol. 
Construction of a partial match table takes O(m) time. 
Therefore, the overall time complexity of the KMP algorithm is O(m + n).
*/

#include <iostream>
using namespace std;

// Function to implement the KMP algorithm
void KMP(string t, string p)
{
    int tlen = t.length();                       //tlen is length of text
    int plen = p.length();                       //plen is length of pattern

    // if `text` is an empty string
    if (plen == 0)
    {
        cout << "The pattern at index 0";
        return;
    }

    // if text's length is less than that of pattern's length then print pattern not found.
    if (tlen < plen)
    {
        cout << "Pattern not found";
        return;
    }

    // `next[i]` stores the index of the next best partial match
    int next[plen + 1];

    for (int i = 0; i < plen + 1; i++) {
        next[i] = 0;          //initialize all the characters of array as zero.
    }

    for (int i = 1; i < plen; i++)     //iterate through pattern 
    {
        int j = next[i + 1];           //initialise j as next[i+1]

        while (j > 0 && p[j] != p[i]) {     //while (j>0 and (pattern[j]!=pattern[i] )
            j = next[j];              //initialize the value of j as next[j]
        }

        if (j > 0 || p[j] == p[i]) {       //if (j>0 or (the j th and i th index of pattern are equal))
            next[i + 1] = j + 1;          //move to next position
        }
    }

    for (int i = 0, j = 0; i < tlen; i++)       //iterate in text to search for a pattern in text.
    {
        if (t[i] == p[j])                      //if the letter in text matches with the letter in pattern then
        {
            if (++j == plen) {                 //move ahead and see if the next letter matches 
                cout << "The pattern occurs at index " << i - j + 1 << endl;
            }
        }
        else if (j > 0)                       //else if j>0
        {
            j = next[j];                     
            i--;    // since `i` will be incremented in the next iteration
        }
    }
}

// Program to implement the KMP algorithm in C++
int main()
{
    string text;                  //text 
    cout<<"Enter text: ";
    cin>>text;
    string pattern;               //pattern whose index of occurrence is to be searched. 
    cout<<"Enter pattern: ";
    cin>>pattern;
    KMP(text, pattern);           //call to KMP function
    return 0;
}
