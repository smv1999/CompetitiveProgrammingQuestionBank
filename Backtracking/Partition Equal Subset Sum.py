`___________________________________________________________________GFG-PROBLEM_______________________________________________________________________________________`

"""
DESCRIPTION :
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.
EXAMPLE :
Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
CONSTRAINTS :
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
"""

#Solution in Python3

class Solution:
    def equalPartition(self, N, nums):
        
        if sum(nums) % 2 != 0:
            return False
        total = sum(nums) // 2
        dp = [[False]*(total+1) for _ in range(len(nums)+1)]
        for i in range(len(nums)+1):
            dp[i][0] = True
        for i in range(1, total+1):
            dp[0][i] = False
        for i in range(1, len(nums)+1):
            for j in range(1, total+1):
                if nums[i-1] <= j:
                    dp[i][j] = dp[i-1][j - nums[i-1]] or dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[len(nums)][total]


import sys
input = sys.stdin.readline
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = input().split()
        for it in range(N):
            arr[it] = int(arr[it])
        
        ob = Solution()
        if (ob.equalPartition(N, arr) == 1):
            print("YES")
        else:
            print("NO")

`__________________________________________________________________________DONE_____________________________________________________________________________________`
