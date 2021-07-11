/*
Problem Statement

Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter. 

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

Constraints:
1 <= pattern.length <= 20
1 <= words.length <= 50
words[i].length == pattern.length
pattern and words[i] are lowercase English letters.

*/

/*
Time Complexity: O(N∗K), where N is the number of words, and K is the length of each word.
Space Complexity: O(N∗K), the space used by the answer.
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    vector<string> ans;
    for (int i = 0; i < words.size(); i++)
    {
        bool flag = true;
        unordered_map<char, char> wordToPattern;
        unordered_map<char, char> patternToWord;
        for (int j = 0; j < pattern.length(); j++)
        {
            char wc = words[i][j];
            char pc = pattern[j];
            if (wordToPattern.count(wc) < 1)
                wordToPattern[wc] = pc;
            if (patternToWord.count(pc) < 1)
                patternToWord[pc] = wc;

            if (patternToWord[pc] != wc || wordToPattern[wc] != pc)
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
            ans.push_back(words[i]);
    }
    return ans;
}

int main()
{
    vector<string> words={"abc","deq","mee","aqq","dkd","ccc"};
    string pattern="abb";
    vector<string> ans=findAndReplacePattern(words,pattern);
    for(string str:ans)
    cout<<str<<" ";
    return 0;
}

