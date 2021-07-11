/*
  Given two strings. The task is to find the length of the longest common substring.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int len_subs[n+1][m+1];
        int i,j,maxLength=0;
        
        for(i=0;i<=n;i++)
            len_subs[i][0] = 0;             //first row
            
        for(i=0;i<=m;i++)
            len_subs[0][i] = 0;             // first column
            
        for(i = 1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    len_subs[i][j] = 1 + len_subs[i-1][j-1];
                    if(maxLength < len_subs[i][j])
                        maxLength = len_subs[i][j];
                }
                else
                    len_subs[i][j] = 0;
            }
        }
        return maxLength;
    }
};
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
