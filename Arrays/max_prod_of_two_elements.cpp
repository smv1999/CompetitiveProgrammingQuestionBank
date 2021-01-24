/*
Src : LeetCode
--------------

Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value 
of (nums[i]-1)*(nums[j]-1).
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1, max2, ans = 0;
        max1 = max2 = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] > max1){
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2){
                max2 = nums[i];
            }
        }
        ans = (max1-1)* (max2-1);
        return ans;
    }
};
