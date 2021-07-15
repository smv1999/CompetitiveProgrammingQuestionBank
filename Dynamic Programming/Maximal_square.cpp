/*
	Question => https://leetcode.com/problems/maximal-square/
	
	Description:
	Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

	Eg: 
    m = 4 and n = 5

	1 0  1 0  0
	1 0 |1 1| 1
	1 1 |1 1| 1 
	1 0  0 1  0
    
	The answer here is: 4 (2x2) shown here

	Soltuion:

	The approach is to  use dynamic programming.
	We use another matrix to store the maximal square possible using the (i,j)-th element of matrix
	as the bottom-left corner of the matrix.
	Base cases :
	a) Fill the left-most column with 1 and (0 where matrix is 0) dp[i][n-1]=1 or 0
	b) Fill the bottom-most row with 1 and (0 where matrix is 0). dp[m-1][i]=1 or 0
	Then for general case:
	dp[i][j] = 0 => if matrix[i][j]=0
	dp[i][j] = 1 + min(dp[i+1][j], dp[i+1][j+1], dp[i][j+1])
	for matrix[i][j]=> dp[i][j] is 1 + minimum of cell on right, bottom and diagonally right

	The answer is the max. value in the dp matrix.
    
*/

// The code for the solution => 

#include<bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>dp(n, vector<int>(m, 0)); // dp matrix
    dp[n-1][m-1] = matrix[n-1][m-1]-'0';  // dp[n-][m-1] is same as matrix[n-1][m-1]
    int ans = dp[n-1][m-1];
    //last column is 1 or 0
    for(int i=0;i<n-1;i++){
        dp[i][m-1]=matrix[i][m-1]-'0';
        ans = max(ans, dp[i][m-1]);
    } 
    //last row is 1 or 0
    for(int j=0;j<m-1;j++){
        dp[n-1][j]=matrix[n-1][j]-'0';
        ans = max(ans, dp[n-1][j]);
    }    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            // dp[i][j] is 0 when matrix[i][j] is 0
            if(matrix[i][j]=='0')
                dp[i][j]=0; 
            //dp[i][j] is 1 + min(right_hand, diagonally_down, down)  
            else
                dp[i][j] = 1+min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]));
            // ans is max of all values in dp
            ans =  max(dp[i][j], ans);
        }
    }
    return ans*ans;
}

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<char>>matrix(m, vector<char>(n, 0));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>matrix[i][j];
        }
    }
    //max. area of 1s
    int ans = maximalSquare(matrix);
    cout<<ans<<"\n";
}