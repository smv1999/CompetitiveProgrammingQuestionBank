'''
PROBLEM DESCRIPTION :
Given a non-empty array of positive integers arr[]. 
Write a program to find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000

Example 1 :
Input: arr[] = [1, 6, 11, 6] 
Output: true  
Explanation: The array can be partitioned as [6, 6] and [1, 11].

Example 2 :
Input: arr[] = [2, 6, 7]
Output: false
Explanation: The array cannot be partitioned into equal sum sets

Solution Approach :

The idea is to calculate the sum of all elements in the set. 
A simple observation would be if the sum is odd, we cannot divide the array into two sets. 
Now, If the sum is even, we check if the subset with sum/2 exists or not.
We can consider each item in the given array one by one and for each item, 

there are two possibilities →
1. We include the current item in the subset and recur for remaining items with the remaining sum.
2. We exclude the current item from the subset and recur for remaining items.
Finally, we return true if we get subset by including or excluding the current item else we return false. 
The base case of the recursion would be when no items are left or sum becomes negative.
We can return true when sum becomes 0 i.e. subset is found.

'''
# CODE :

# A recursive Python3 program for
# partition problem
 
# A utility function that returns
# true if there is a subset of
# arr[] with sum equal to given sum
 
 
def isSubsetSum(arr, n, sum):
    # Base Cases
    if sum == 0:
        return True
    if n == 0 and sum != 0:
        return False
 
    # If last element is greater than sum, then
    # ignore it
    if arr[n-1] > sum:
        return isSubsetSum(arr, n-1, sum)
 
    # else, check if sum can be obtained by any of the following
    # (a) including the last element
    # (b) excluding the last element
 
    return isSubsetSum(arr, n-1, sum) or isSubsetSum(arr, n-1, sum-arr[n-1])
 
# Returns true if arr[] can be partitioned in two
# subsets of equal sum, otherwise false
 
 
def findPartion(arr, n):
    # Calculate sum of the elements in array
    sum = 0
    for i in range(0, n):
        sum += arr[i]
    # If sum is odd, there cannot be two subsets
    # with equal sum
    if sum % 2 != 0:
        return False
 
    # Find if there is subset with sum equal to
    # half of total sum
    return isSubsetSum(arr, n, sum // 2)
 
 
# Driver code
arr = []
n = len(arr)
 
# Function call
if findPartion(arr, n) == True:
    print("True")
else:
    print("False")
    
'''
Complexity Analysis :

Time Complexity -> O(2^n), In the worst case, this solution tries two possibilities (whether to include or exclude) for every element.

Space Complexity -> O(1), if not considering recursion stack space.

'''
