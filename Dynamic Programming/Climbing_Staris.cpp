/*
ome observation
if n = 1 => 1 way
only take step of 1
if n = 2 => 2 way
take step of 2 or take step of 1 two time
if n = 3 => 3 way
take step of 1 three times or take step 1 of one time and step of 2 one time

n=1 => 1
1
n=2 => 2
1 + 1
2
n=3 => 3
1 + 1 + 1 
2 + 1
1 + 2
n=4 => 5
1 + 1 + 1 + 1
1 +  1 + 2
1 + 2 + 1
2 + 1 + 1
2 + 2
n = 5 => 8
1 + 1 + 1 + 1 + 1
1 + 1 + 1 + 2
1 + 1 + 2 + 1
1 + 2 + 1 + 1
2 + 1 + 1 + 1
1 + 2 + 2
2 + 1 + 2
2 + 2 + 1

*/

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        vector<int>dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
