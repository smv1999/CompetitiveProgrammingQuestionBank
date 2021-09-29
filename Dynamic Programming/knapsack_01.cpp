// Question: 

// 0 - 1 Knapsack Problem :
// You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
// Note that we have only one quantity of each item.

// Example 1:

// Input:
// N = 3
// W = 4
// values[] = {1,2,3}
// weight[] = {4,5,1}
// Output: 3
// Example 2:

// Input:
// N = 3
// W = 3
// values[] = {1,2,3}
// weight[] = {4,5,6}
// Output: 0

//Approch followed: memoization 


// Memoization: Make a choice digram for recursion,
//  this will consist of if you can include the element in the knapsack or not,
//   check if the weight of current item is less than or equal to toal weight,
//    if it is, return the max of recursive call of the same function including 
//    the element (reduce the max Weight and n) or don;t include the element,
//     this will oonly reduce n. And if the element's weight is more than current. don't include
//      and call the function again with onoly n-1. for the DP part, initialize a global matrix and memset it to -1 
//      in the main code. whenever you are going in any condition, make the matrix on basis of the dimension of the varibale 
//      inputs of the recurisie function. Here it will be W and n, make a matrix of W+1 and n+1 dimension and for every recurvie 
//      return, instead, store that value insdie that matrix,  before going into any call, check if 
//      the value foor that W and n is something else than the initalize mem set value of the matrix, if so directly return that   



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{   
    public:
    
    int  t[1001][1001];
    
    int solve(int W, int wt[], int val[], int n){
       if(t[n][W]!=-1){
            return t[n][W];
        }
       if(W==0 || n==0){
           t[n][W]=0;
           return 0;
       }
        
        
       if(wt[n-1]<=W){

           t[n][W]=max(val[n-1]+solve(W-wt[n-1],wt,val,n-1),solve(W,wt,val,n-1));
           return t[n][W];
       }
       else {
           t[n][W]=solve(W,wt,val,n-1);
           return t[n][W];
       } 
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
{      

       memset(t,-1,sizeof(t));
       
       return solve(W,wt,val,n); 
       // Your code here
       
    }
};


// Alternative Method for 0/1 Knapsack 
//Tabulation Method (Bottom-up Approach)
//Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[n+1][W+1];
       for(int i=0;i<n+1;i++)
       {
           for(int j=0;j<W+1;j++)
           if(i==0 || j==0)
               dp[i][j]=0;
           else if(wt[i-1]<=j)
               dp[i][j]= max(val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
           else
               dp[i][j]= dp[i-1][j];
       }
       return dp[n][W]; 
    }


// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends