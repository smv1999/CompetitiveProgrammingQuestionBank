#Kadane's Algorithm

def kadaneAlgo(arr):
    maxSumSoFar = arr[0]
    max_sum = arr[0]
    for ele in arr[1:]:
        maxSumSoFar = max(ele, ele + maxSumSoFar) #current maximum sum so far
        max_sum = max(max_sum, maxSumSoFar)  #maximum sum so far  
    return max_sum
 
l = list(map(int, input().split()))
max_sm = kadaneAlgo(l)
print(max_sm)
