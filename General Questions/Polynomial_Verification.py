'''
Aim: Given a polynomial P of a single indeterminate (or variable), x. Also, 
given the values of x and k. The task is to verify if P(x) = k.

'''

# taking the space separated input
x_and_k = input().split()
# the very first number denotes 'x'
x = int(x_and_k[0])
# eval is used to evaluate any expression
# here if the evaluated expression results in the value of k, it would mean that it is valid
# the value of k is second in the entered string x_and_k, we have selected it using indicing
print(eval(input()) == int(x_and_k[1]))

'''

COMPLEXITY:
	
	 Time Complexity -> O(1)
	 Space Complexity -> O(1)
     
Sample Input:
1 4
x**3 + x**2 + x + 1

Sample Output:
True

Explanation:
x = 1
k = 4
P(x) = x**3 + x**2 + x + 1
P(1) = 1**3 + 1**2 + 1 + 1
     = 1 + 1 + 1 + 1
     = 4
     = k
Hence, the polynomial is a valid one.

'''