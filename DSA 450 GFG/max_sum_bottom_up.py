#https://practice.geeksforgeeks.org/problems/maximum-sum-problem2211/1/


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