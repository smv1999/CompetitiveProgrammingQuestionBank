
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


#Approach 2 - Bottom Up approach 


    def maxSum(self, n): 
        # code here
        dp = [0]*(n+1)
        dp[0] = 0
        if(n >= 1):
            dp[1] = 1
            for i in range(2 , n+1):
                dp[i] = max((dp[int(i/2)] + dp[int(i/3)] + dp[int(i/4)]) , i)
                
        return dp[n]


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