'''

Aim: Given set S = {1,2,3,....,N}. Find two integers, I and J (where I<J), 
from set S such that the value of I & J is the maximum possible and also 
less than a given integer, K. In this case, '&' represents the bitwise AND 
operator.

Input Format: 
1. The first line contains an integer T, the number of test cases.
2. Each of the T subsequent lines defines a test case as 2 space-separated 
   integers, N and K, respectively.

'''

def max_bit(n,k):
  maximum = 0              # we need a counter to keep a check on the value of I & J, it should not exceed K
  for i in range(1,n+1):
    for j in range(1,i):
      h = i & j            # storing bitwise AND value in a variable h
      if maximum < h < k:  # I & J < K
        maximum = h
      if maximum == k-1:   # if maximum becomes equal to k-1, we have found the maximum value of I & J which will be less than K
        return maximum
  return maximum

if __name__ == '__main__':
  t = int(input())
  for t_itr in range(t):
    nk = input().split()
    n = int(nk[0])           # getting the value of N
    k = int(nk[1])           # getting the value of K
    print(max_bit(n,k))      # calling function to compute the answer

'''   

Sample Test Case:
Input: 
3       
5 2     
8 5     
2 2 
Output: 
1
4
0
Explaination:
N = 5, K = 2, S = {1,2,3,4,5}
All possible values of I and J are:
 1. I = 1, J = 2; I & J = 0 
 2. I = 1, J = 3; I & J = 1 
 3. I = 1, J = 4; I & J = 0 
 4. I = 1, J = 5; I & J = 1
 5. I = 2, J = 3; I & J = 2 
 6. I = 2, J = 4; I & J = 0 
 8. I = 2, J = 5; I & J = 0 
 9. I = 3, J = 5; I & J = 1
10. I = 4, J = 5; I & J = 4
The maximum possible value of I & J that is also < (K = 2) is 1, so the output will be 1.

'''