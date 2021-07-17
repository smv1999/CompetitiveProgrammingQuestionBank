'''
Aim: To calculate average of all the distinct integers.

'''

def average(array):
    # getting all unique numbers
    p = set(array)
    # calculating the total number of elements
    s = len(p)
    # computing the average
    ans = sum(p)/s
    # printing the result
    print('Average is:',ans)
    
# getting the input
arr = input('Enter numbers: ').strip().split()
# converting elements into integer type for calculating average
arr_int = []
for i in arr:
    arr_int.append(int(i))
# calling function to compute the average
average(arr_int)

'''

COMPLEXITY:
	
	 Time Complexity -> O(1)
	 Space Complexity -> O(N)
     
Sample Input:
Enter numbers: 5 3 1 2 3 4 5

Sample Output:
Average is: 3.0

Explanation:
All unique integers --> 1 2 3 4 5
Total count --> 5
Average --> (1+2+3+4+5)/5 = 3.0

'''