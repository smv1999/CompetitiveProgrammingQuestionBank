/* problem statement -> https://leetcode.com/problems/edit-distance/

Description ->
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character


Example -> word1 = "horse", word2 = "ros"
Output -> 3
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/

#include<bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        // dp array 
        int dp[n+1][m+1];    
        // empty string to empty -> no change
        dp[0][0]=0;

        //To convert a string to a empty string, or 
        //To convert empty string to string use (length => i or j) operations
        for(int j=1;j<m+1;j++)
            dp[0][j]=j;
        for(int i=1;i<n+1;i++)
            dp[i][0]=i;
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                // if word[i-1]==word[j-1]; dp[i][j] is same as dp[i-1][j-1]
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                // 3 cases of insert(dp[i-1][j]), delete(dp[i][j-1]), replace(dp[i-1][j-1])+1
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
            }
        }
        // ans is last element
        return dp[n][m];
    }

    int main()
    {
        string w1;
        string w2;
        cin>>w1>>w2;
        // calling the minDistance function
        int ans = minDistance(w1, w2);
        cout<<ans<<"\n";
        return 0;
    }