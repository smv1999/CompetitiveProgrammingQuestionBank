'''
Aim: Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers.

Example:
arr = [1,3,5,7,9]
The minimum sum is 1+3+5+7 = 16 and the maximum sum is 3+5+7+9 = 24. So, the output will be:
16 24

'''

def MMSum(a):
    # sorting the array so that it becomes easier to find the min and max set of values
    a.sort()    
    minn=0
    maxx=0
    for i in range(0,4):
        # summing up all minimum values
        minn+=a[i]           
    for i in range(1,5):
        # summing up all maximum values
        maxx+=a[i]           
    print(minn,maxx)

# getting the input    
user_input = (input().strip().split()) 
array = []
for i in user_input:
    array.append(int(i))
# calling the Min-Max-Sum function     
MMSum(array)                           
  
'''

COMPLEXITY:
	
	 Time Complexity -> O(N)
	 Space Complexity -> O(N)
     
Sample Input:
2 1 3 4 5

Sample Output:
10 14

Explanation:
Sorted array: [1,2,3,4,5]
Min Sum: 1+2+3+4 = 10
Max Sum: 2+3+4+5 = 14

'''