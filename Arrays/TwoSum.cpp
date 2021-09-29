/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/
#include<bits/stdc++.h>
using namespace std;
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                v.push_back(m[target-nums[i]]);
                v.push_back(i);
                return v;
            }
            m[nums[i]]=i;
        }
        return v;
    }
int main(){
vector<int> nums;//to store elements
int n,element,target;
cin>>n;
 for (int i = 0; i < n; i++)
    {
        cin>>element;
       nums.push_back(element);//storing the elements
    }
    cin>>target;
vector<int> result=twoSum(nums,target);
for (int i = 0; i < result.size(); i++)
{
    cout<<result[i]<<",";//print the elements
}

return 0;
}