// Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k).
//  For example, our function should return 6 for n = 4 and k = 2, and it should return 10 for n = 5 and k = 2.

// The idea we have used here is inspired by the pascal triangle.
/*
                    1
                 1     1
               1  2  2  1
             1   3  4  3  1  */

#include <bits/stdc++.h>
using namespace std;

int binomial(int n, int r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;

    int dp[n + 1][r + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            if (i == j || j == 0) // Base Condition
                dp[i][j] = 1;
            else
            { //  we have taken a mod, so that higher results can be calculted too.
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10000007;
            }
        }
    }
    return dp[n][r];
}

int main()
{
    int n;
    int r;
    cin >> n >> r;
    return binomial(n, r);
}