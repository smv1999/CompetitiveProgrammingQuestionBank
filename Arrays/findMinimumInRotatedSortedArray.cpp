/*

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Constraints:
 n == nums.length
 1 <= n <= 5000
 -5000 <= nums[i] <= 5000
 All the integers of nums are unique.
 nums is sorted and rotated between 1 and n times.

*/

/*
Time Complexity: O(log(N)), where N is the size of the array
Space Complexity: O(1), Constant Space
*/

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{

    int l = 0; // lower bound
    int u = nums.size() - 1; // upper bound
    int m = (l + u) / 2; // variable to track middle value
    int n = nums.size();
    while (l <= u)
    {
        int next = (m + 1) % n; // to track next index of middle value
        int prev = (m - 1 + n) % n; // to track previoys index of middle value
        if (nums[l] <= nums[u]) // if array is sorted => return value present at lower bound
            return nums[l];
        else if (nums[m] < nums[prev] && nums[m] < nums[next]) // if value at middle is less than value at next, previous => return value present at middle
            return nums[m];
        else if (nums[m] > nums[l]) // if value at middle > value at lower bound => update lower bound
            l = next;
        else if (nums[m] < nums[u]) // if value at middle < value at upper bound => update upper bound
            u = prev;
        else if (nums[u] <= nums[l]) // if value at upper <= value at lower bound => Whole array is reversed i.e. return value at upper bound
            return nums[u];

        m = (l + u) / 2;
    }
    return -1;
}

int main() // driver function
{
    vector<int> array = {3, 4, 5, 1, 2};
    int ans = findMin(array);
    cout << ans;
    return 0;
}