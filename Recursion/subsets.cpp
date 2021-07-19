/* 
The problem is to generate all the possible subsets of the given input vector

Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

The problem is given below
https://leetcode.com/problems/subsets/

Below is the recursive appraoch of the problem-
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> op;    //global vector to store the output

void solve(vector<int> input, vector<int> & output)
{
    if(input.size()==0)         //when the size of the input vector is 0, we have to add the output to the global vector
    {
        vector<int> sum;
        for(auto it: output)        
            sum.push_back(it);  //we have to convert the vector to a vector of integers
        op.push_back(sum);     //push the vector to the global vector
        return;              //exit the function
    }
    vector<int> out1=output;          //first output vector will store our choice one of the recursive tree
    vector<int> out2=output;          //second output vector will store our choice two of the recursive tree
                                      //we do not push anything in the first vector                          
    out2.push_back(input[0]);         //push the first element to the second output vector
    input.erase(input.begin()+0);     //erase the first element of the input vector
    solve(input,out1);      //recursive call            
    solve(input,out2);   //recursive call
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> output;
    solve(nums, output);
    vector<vector<int>> out=op;
    return out;
}
int main()
{
    int t=0;
    cin>>t;
    while(t--) {
        int n=0;        //input of the vector length
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++) {
            cin>>nums[i];
        }
        vector<vector<int>> out=subsets(nums);

        //printing the output vector
        for(auto it:out) {
            for(auto it1:it) {
                cout<<it1<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}