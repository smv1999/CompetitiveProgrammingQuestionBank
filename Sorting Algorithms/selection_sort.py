
class Solution: 
    def select(self, arr, i):
        
        minimum = i
        j = i + 1
        for j in range(j , n):
            if(arr[j] < arr[minimum]):
                minimum = j
        return minimum
            
    
    def selectionSort(self, arr,n):
     
        for i in range(0 , n):
            minimum = self.select(arr , i)
            if(minimum != i):
                arr[i] , arr[minimum] = arr[minimum] , arr[i]
                

#{ 
#  Driver Code Starts


if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        Solution().selectionSort(arr, n)
        for i in range(n):
            print(arr[i],end=" ")
        print()
# } Driver Code Ends