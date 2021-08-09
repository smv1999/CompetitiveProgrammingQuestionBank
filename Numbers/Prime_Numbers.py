'''
Aim: To check if the entered numbers are prime or not.

'''

# importing necessary library
from math import sqrt

# getting the number of test cases as input
T = int(input().strip())

# checking condition
for t in range(0,T):
    # getting each number as input
    n = int(input().strip())
    p = 0
    if n == 1:
        # '1' is not a prime number
        print('Not prime')
    else:    
        # loop to calculate all factors of the entered number
        for i in range(1,int(sqrt(n)+1)):
            if n%i == 0:
                p+=1
        # if the factors are more than 2, then the number is not a prime one
        if p>=2:
            print('Not prime') 
        else:
            print('Prime')
            
'''

COMPLEXITY:
	
	 Time Complexity -> O(N^2)
	 Space Complexity -> O(N)
     
Sample Input:
3
12
7
3
Sample Output:
Not prime
Prime
Prime

Explanation:
7 and 3 have only two factors --> 1 and the number itself.
12 has factors --> 1, 2, 3, 4, 6 and 12, which are more than 2.
So, it's not a prime number.

'''