/* Rabin Karp Algorithm for pattern searching in C++

Rabin-Karp algorithm is an algorithm used for searching/matching patterns in the text using a hash function. 
It does not travel through every character in the initial phase rather it filters the characters that do not match
and then performs the comparison.

Working - 
A sequence of characters is taken and checked for the possibility of the presence of the required string. 
If the possibility is found then, character matching is performed.
f the hash values are unequal, the algorithm will determine the hash value for next plen-character sequence. If the hash values are equal, 
the algorithm will analyze the pattern and the plen-character sequence. 
In this way, there is only one comparison per text subsequence, and character matching is only required when the hash values match.

Features - 
Like naive algorithm we slide the pattern over the string one by one and compare every character in pattern with the text.
To reduce the number of comparisons, we use hashing. 
We compare the hash values of the pattern and the current text window if the hash value match, 
then only we proceed to compare individual characters of pattern and the text window.
To calculate the hash value of the current window we use the concept of rolling hash. 
In rolling hash we compute hash value of current window using the hash value of the previous window.

Time Complexity - 
Assuming n is length of text and m is length of pattern.
Its worst-case time is O(nm). 
Worst case of Rabin-Karp algorithm occurs when all characters of pattern and text are same as the hash values
of all the substrings of text[] match with hash value of pattern[].

Example - 
text – “abdabc”
pattern – “abc”

a b c d 
1 2 3 4 

text – “a  b  d  a  b  c”
plen = pattern length = 3
t  =  4

hash_0  =  1 * 4^2  +  2 * 4^1  +  4 * 4^0  =  28
hash_1  =  4 * {hash_0 – 1 * 4^2} + 1  =  49
hash_2  =  4 * {hash_1 – 2 * 4^2} + 2  =  70
hash_3  =  4 * {hash_2 – 4 * 4^2} + 3  =  27

Hence in general
hash_i+1  =  t * {hash_i  –  text[i] * t^(plen-1)} + text[i+plen]

*/

//Program

#include <bits/stdc++.h>
using namespace std;
const int t = 256;                    //number of characters in the character set
const int w = 1283;                   //a prime number (a prime number of find hash location)
void Rabin_Karp_Algo(string text,string pattern)
{

    //Length of text string.
    int tlen = text.length();       //length of string

    //Length of pattern string.
    int plen = pattern.length();    //length of pattern

    int flag;
    int c=1,i=0;

    // Calculate the hash value of pattern(hash_p) and first window of text(hash)
    int hash_p=0,hash=0; 

    //for all character index i of pattern 
    for(int i=0;i<plen;i++)
    {
        hash_p=(hash_p*t + pattern[i])%w;     //formula to calculate hash function 
        hash=(hash*t + text[i])%w;

    }

     //Calculate (t^(plen-1))%w
    for(int i=1;i<=plen-1;i++)
        c=(c*t)%w;

    i=0;

    // Slide the pattern over text one by one
    while(i<=tlen-plen)
    {
       // Check the hash values of current window of text and pattern. 
       //If the hash values match then only
       // check for characters on by one
       if(hash_p==hash)
       {
            flag=1;
            /* Check for characters one by one */
            for(int j=0;j<plen;j++)
            {
                // if pattern == text and pattern[0...plen - 1] = text[i, i+1, ...i+tlen - 1]
                if(pattern[j]==text[i+j])
                {
                    continue;
                }
                else{
                    flag = 0;   //if flag is zero break the loop
                    break;
                }
           }
            if(flag==1)
            cout<<"Index of occurrence is "<<i<<" ";
       }


       
       // Calculate hash value for next window of text: Remove leading digit, add trailing digit
       if(i<tlen-plen)
       {
           //Calculate hash value of next window
           //hash_i+1 = t * {hash_i - text[i] * t^(plen-1)} + text[i+plen]
           hash=((t*(hash-text[i]*c))+text[i+plen])%w;

           // We might get negative value of t, converting it to positive 
            if(hash<0){
                hash = hash + w;
            }
       }
       i++;
    }
}

int main()
{
    string text;                         //text
    cout<<"Enter the text: ";
    cin>>text;
    string pattern;                      //pattern to be searched
    cout<<"Enter the pattern: ";
    cin>>pattern;
    Rabin_Karp_Algo(text,pattern);         //call to function Rabin_Karp_Algo
    return 0;
}
