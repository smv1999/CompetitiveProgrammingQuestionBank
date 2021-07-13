//Link : https://www.interviewbit.com/problems/minimum-difference-subsets/
/*
Problem Description

Given an integer array A containing N integers.

You need to divide the array A into two subsets S1 and S2 such that the absolute difference between their sums is minimum.

Find and return this minimum possible absolute difference.

NOTE:

Subsets can contain elements from A in any order (not necessary to be contiguous).
Each element of A should belong to any one subset S1 or S2, not both.
It may be possible that one subset remains empty.


Problem Constraints
1 <= N <= 100

1 <= A[i] <= 100



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the minimum possible difference among the sums of two subsets.



Example Input
Input 1:

 A = [1, 6, 11, 5]


Example Output
Output 1:

 1


Example Explanation
Explanation 1:

 Subset1 = {1, 5, 6}, sum of Subset1 = 12
 Subset2 = {11}, sum of Subset2 = 11*/

int Solution::solve(vector<int> &A) {
    int sum = 0,N=A.size();
    for (int i = 0; i < A.size(); i++)
        sum += A[i];

    bool dp[N+1][sum+1];
        
        for(int i=0;i<N+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                 
                if(j==0) dp[i][j]= true;
                else if(i==0) dp[i][j]= false;
                 
                else if(A[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-A[i-1]] || dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
            // Initialize difference of two sums.
        int diff = INT_MAX;
        
        // Find the largest j such that dp[n][j]
        // is true where j loops from sum/2 t0 0
        for (int j=sum/2; j>=0; j--)
        {
            // Find the
            if (dp[N][j] == true)
            {
                diff = sum-2*j;
                break;
            }
        }
        return diff;
}
