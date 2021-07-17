"""
DESCRIPTION :
Given an array of integers arr[] and a target number k, write a program to find all unique combinations in arr[] 
such that the sum of all integers in the combination is equal to k.
The same repeated number may be chosen from arr[] unlimited number of times.

NOTE :
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.
        4. The solution set must not contain duplicate combinations.
        
EXAMPLE :

Given array 2,3,6,7 and target 7,
A solution set is:
[2, 2, 3]

CONSTRAINTS:
1 <= N <= 30
1 <= A[i] <= 20
1 <= B <= 100

SOLUTION APPROACH :

In every recursion run, you either include the element in the combination or you don’t. 
To account for multiple occurrences of an element, 
make sure you call the next function without incrementing the current index.

"""
# SOLUTION IN PYTHON3


class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return a list of list of integers
    def combinationSum(self, A, B):
        # Remove duplicate and sort since each element can be repeated 
        # in combination either way.
        # Removing duplicates here helps us avoid removing them from the final result.
        A=sorted(set(A))
        # if the target sum is less than 2 or the lis A is empty,
        # then retirn an empty list
        if B<2 or len(A)==0:
            return [[]]

        
        result=[]
        comb=[]
        index=0
        self.find(result, comb, A, B, index)
        return result
    
    def find(self, result, comb, A, B, index):
        # The recursion will nest until we hit the target. At this point we append and return.
        if sum(comb) == B:
            result.append(comb[:])
            return
        # If the sum is bigger, we also terminate the recursion chain.
        if sum(comb)>B:
            return
        
        for i in range(index, len(A)):
            comb.append(A[i])
            # Start from same index since an element can be repeated.
            self.find(result, comb, A, B, i)
            comb.pop()
                
 '''
 
Sample Input : A  = [2,3,5], B = 8 
Output:  
[   
    [2,2,2,2],   
    [2,3,3],   
    [3,5] 
]

EXPLANATION: 
All the unique combinations whose sum is 8 is printed.
2+2+2+2 = 8
2+3+3 = 8
3+5 = 8

COMPLEXITY ANALYSIS :

Time Complexity -> O(l^k) 
Where l is the length of the array, k is the length of the longest possible combination (namely target / minInArray).

Space Complexity -> O(k)
for storing the path, which could be k long at most.

'''
