# Problem : https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1#

#Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
#1. Each student gets exactly one packet.
#2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.


class Solution:

    def findMinDiff(self, A,N,M):

        # code here
        if(N == 0 or M == 0):
            return 0
        elif (N < M):
            return -1
        else:
            A.sort()
            min_diff = A[N-1] - A[0]
            for i in range(0 , N - M + 1):
                min_diff = min(min_diff , A[i+M-1] - A[i])
            return min_diff
        
        
#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        N = int(input())
        A = [int(x) for x in input().split()]
        M = int(input())


        solObj = Solution()

        print(solObj.findMinDiff(A,N,M))
# } Driver Code Ends