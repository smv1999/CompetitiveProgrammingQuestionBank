
#https://practice.geeksforgeeks.org/problems/maximum-sum-problem2211/1/

# Approach 1 - Memoization 

from functools import lru_cache

class Solution:
    @lru_cache(maxsize = 1000)
    def maxSum(self, n): 
        # code here 
        if(n == 0 or n == 1):
            return n
        else:
            return max( (self.maxSum(n//2) + self.maxSum(n//3) + self.maxSum(n//4))  , n )



#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        n = int(input())
        ob = Solution()
        print(ob.maxSum(n))
# } Driver Code Ends


