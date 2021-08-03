/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int cs=0,ms=0; //cs for current sum and ms for maximum sum
int a[1000];
for (int i = 0; i < n; i++)
{
        cin>>a[i];
}
// Kadane's Algorithm for maximum Sub Array Sum
for (int i = 0; i < n; i++)
{
    cs+=a[i];
    if (cs<0)
    {
        cs=0;
    }
    ms=max(cs,ms);
}

cout<<"Maximum is:"<<ms<<endl;
return 0;
}