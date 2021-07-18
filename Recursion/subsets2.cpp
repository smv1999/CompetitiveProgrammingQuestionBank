/* 
The problem is to generate all the possible subsets of the given input vector and should not print any duplicate elements.


Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

The problem is given below
https://leetcode.com/problems/subsets-ii/

Below is the recursive appraoch of the problem-
*/


#include<bits/stdc++.h>             //input of the header files
using namespace std;
set<vector<int>> s;                 //declaing a set to store only the unique elements
void solve(vector<int> input, vector<int> & output)     //recursive function to generate the unique subsets
{
    if(input.size()==0)
    {
        vector<int> sum;                        //declaring a vector to store the combinations of the elements   
        sort(output.begin(),output.end());      //sorting it to make prevent duplicates entering the set
        for(auto it: output)
            sum.push_back(it);
        s.insert(sum);                          //inserting the unique elements in the set
        return;                                 //return to end the function
    }
    vector<int> out1=output;                    //declaring a vector to store the elements of the subset
    vector<int> out2=output;                    //declaring another vector to store the elements of the subset
        
    out2.push_back(input[0]);                   //inserting the first element in the second vector
    input.erase(input.begin()+0);               //erase function to delete the first element of the vector
    solve(input,out1);                          //recursive call to generate the subsets with the first vector
    solve(input,out2);                          //recursive call to generate the subsets with the second vector                   
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {                 //function which call the solve function to generate the subsets
    vector<int> output;
    solve(nums, output);
    vector<vector<int>> out;    
    for(auto it:s)
    {
        out.push_back(it);
    }
        
    return out;                             //returning the subsets after duplicates are removed
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
        vector<vector<int>> out=subsetsWithDup(nums);

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