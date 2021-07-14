//Link: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

/*
Knapsack with Duplicate Items : 
Given a set of N items, each with a weight and a value, and a weight limit W. Find the maximum value of a collection containing any of the N items any number of times so that the total weight is less than or equal to W.

 

Example 1:

Input: N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
Output: 3
Explaination: Pick the 2nd element thrice.
 

Example 2:

Input: N = 4, W = 8
val[] = {1, 4, 5, 7}
wt[] = {1, 3, 4, 5}
Output: 11
Explaination: The optimal choice is to 
pick the 2nd and 4th element.*/
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int dp[N+1][W+1];
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<N+1;i++)
        {
            for(int j=0;j<W+1;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
                //Here if weight is less than j it wont be considered processed and we will consider it multiple times. that's why we write val[i-1]+dp[i][j-wt[i-1]] instead of val[i-1]+dp[i-1][j-wt[i-1]]
                else if(wt[i-1]<=j){
                    dp[i][j]= max(val[i-1]+dp[i][j-wt[i-1]] , dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }   
        return dp[N][W];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends