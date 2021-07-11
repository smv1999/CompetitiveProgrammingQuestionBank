"""
DESCRIPTION :
Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. 
The same number may be chosen from the array any number of times to make B.
NOTE :
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.
        
EXAMPLE :

Input:
N = 4
arr[] = {7,2,6,5}
B = 16
Output:
(2 2 2 2 2 2 2 2)
(2 2 2 2 2 6)
(2 2 2 5 5)
(2 2 5 7)
(2 2 6 6)
(2 7 7)
(5 5 6)
Constraints:
1 <= N <= 30
1 <= A[i] <= 20
1 <= B <= 100
"""

# SOLUTION IN PYTHON3


import atexit
import io
import sys


class Solution:
    
    
    def combinationalSum(self,A, B):
        partialpath=[]
        allpath=[]
        A = sorted(list(set(A)))
        def find(start,target,partialpath,allpath,A):
            
            if(sum(partialpath)==target):
                allpath.append(partialpath[:])
                return
            if(sum(partialpath)>target):
                return
            for i in range(start,len(A)):
                partialpath.append(A[i])
                find(i,target,partialpath,allpath,A)
                partialpath.pop()
        find(0,B,partialpath,allpath,A)
        return allpath
     

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        a = list(map(int,input().strip().split()))
        s = int(input())
        ob = Solution()
        result = ob.combinationalSum(a,s)
        if(not len(result)):
            print("Empty")
            continue
        for i in range(len(result)):
            print("(", end="")
            size = len(result[i])
            for j in range(size - 1):
                print(result[i][j], end=" ")
            if (size):
                print(result[i][size - 1], end=")")
            else:
                print(")", end="")
        print()
