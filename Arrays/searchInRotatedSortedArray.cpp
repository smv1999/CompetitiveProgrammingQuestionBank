/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that 
the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 
if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Constraints:
 1 <= nums.length <= 5000
 -104 <= nums[i] <= 104
 All values of nums are unique.
 nums is guaranteed to be rotated at some pivot.
 -104 <= target <= 104

*/

/*
Time Complexity: O(log(N)), where N is the size of the array
Space Complexity: O(1), Constant Space
*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int l, int r, int x) // Function to perform Binary Search
{
    while(l<=r)
    {
        int m=(l+r)/2;
        if(arr[m]==x)
        return m;
        else if(arr[m]<x)
        l=m+1;
        else
        r=m-1;
    }
    return -1;
}
int search(const vector<int> &A, int B) 
{
    int l=0; // lower bound
    int n=A.size();
    int u=n-1; // upper bound
    int index=-1; // to know the index upto which array is sorted i.e left,right of this will be sorted array
    while(l<=u)
    {
        int m=(l+u)/2;
        int prev=(m-1+n)%n;
        int next=(m+1)%n;
        if(A[l]<=A[u]) // If array is already sorted return lower bound
        {
            index=l;
            break;
        }
        if(A[m]<=A[prev]&&A[m]<=A[next]) // if value at middle is less than or equal to value at previous and value at middle is also less than or equal to value at next => we have found our match
        {
            index=m;
            break;
        }
        else if(A[l]<=A[m]) // if value at lower bound is less than value at middle then shift lower bound
        l=next;
        else// if above condition is  not true shift upper bound
        u=prev;
    }
    int i1=binarySearch(A,0,index-1,B); // performing binary search in either halves of the sorted array
    if(i1!=-1)
    return i1;
    i1=binarySearch(A,index,n-1,B);
    return i1;
}

int main() // driver function
{
    vector<int> array = {4,5,6,7,0,1,2};
    int ans = search(array,0);
    cout << ans;
    return 0;
}
