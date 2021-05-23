
class Solution:
    def insert(self, alist, index, n):
        
        sort = self.insertionSort(alist , n)
        return sort
    #Function to sort the list using insertion sort algorithm.    
    def insertionSort(self, alist, n):
        
        for i in range(1 , n):
            temp = alist[i]
            j = i - 1
            while(j >= 0 and temp < alist[j]):
                alist[j+1] = alist[j]
                j -= 1
            alist[j+1] = temp
            

#{ 
#  Driver Code Starts
if __name__=="__main__":
    t=int(input())
    for i in range(t):
        n=int(input())
        arr=list(map(int,input().split()))
    
        Solution().insertionSort(arr,n)
    
        for i in range(n):
            print(arr[i],end=" ")
    
        print()
# } Driver Code Ends