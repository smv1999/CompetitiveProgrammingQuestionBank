#https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#

#Steps : 

# 1 . Initialize the count of ones in a row as max_ones_row = -1
# 2 . Initialize the max count of 1's as max_ones = 0
# 3 . Iterate through each row and find the ones count
# 4 . Compare the max_ones with max_ones_row in each row and store the updated count in max_ones_row

class Solution:
    
    def rowWithMax1s(self,arr, n, m):
        # code here
        j = m - 1 
        max_ones = 0
        max_ones_row = -1
        for i in range(0 , n ):
            ones = self.countones(arr[i])
            if( ones > max_ones ):
                max_ones = ones
                max_ones_row = i
                
                
        return max_ones_row
            
    def countones(self , a ):
        count = a.count(1)
        return count

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, m = list(map(int, input().strip().split()))
        
        inputLine = list(map(int, input().strip().split()))
        arr = [[0 for j in range(m)] for i in range(n)]
        
        for i in range(n):
            for j in range(m):
                arr[i][j] = inputLine[i * m + j]
        ob = Solution()
        ans = ob.rowWithMax1s(arr, n, m)
        print(ans)
        tc -= 1

# } Driver Code Ends