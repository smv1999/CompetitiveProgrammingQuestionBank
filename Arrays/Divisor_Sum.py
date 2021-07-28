'''
Aim: Calculate the sum of all the divisors of the entered number and display it.

'''

# function to find out all divisors and add them up
def divisorSum(n):
    temp = []
    for i in range(1, n+1):
        # condition for finding factors
        if n%i == 0:
            temp.append(i)
    # adding all divisors
    return sum(temp)

# getting the input
n = int(input())
# printing the result
print(divisorSum(n))     

'''

COMPLEXITY:
	
	 Time Complexity -> O(N)
	 Space Complexity -> O(1)
     
Sample Input:
6
Sample Output:
12

Explaination:
Divisors/Factors of 6 are --> 1,2,3 and 6.
Adding them up --> 1+2+3+6 = 12.

'''