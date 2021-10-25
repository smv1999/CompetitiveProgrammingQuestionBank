'''
Given a 6X6 2D Array, A:
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

An hourglass in A is a subset of values with indices falling in this pattern 
in A's graphical representation:
a b c
  d
e f g

There are 16 hourglasses in A, and an hourglass sum is the sum of an hourglass' 
values. Like here, the maximum hourglass sum is 7 for the hourglass in the top 
left corner.

Aim: Check all such hourglasses and print the maximum hourglass sum for the 
2D array entered by user.

'''

# getting the 2D array as input
arr = []
for _ in range(6):
    arr.append(list(map(int, input().rstrip().split())))

res = []
# looping through the 2D array
for x in range(0, 4):
    for y in range(0, 4):
        # selecting combinations that make an hourglass
        s = sum(arr[x][y:y+3]) + arr[x+1][y+1] + sum(arr[x+2][y:y+3])
        res.append(s)
# printing out the maximum hourglass sum        
print(max(res))

'''

COMPLEXITY:
	
	 Time Complexity -> O(N^2)
	 Space Complexity -> O(N)
     
Sample Input:
0 0 1 2 3 0
0 0 0 5 0 0
1 0 0 7 1 0
0 0 0 0 0 0
0 1 1 1 0 1
0 0 4 0 0 4

Sample Output:
19

Explanation:
The hourglass with the maximum sum is,
1 2 3
  5 
0 7 1
with the sum being 1 + 2 + 3 + 5 + 0 + 7 + 1 = 19
    
'''