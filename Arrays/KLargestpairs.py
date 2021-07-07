# K Largest Pairs

"""
You are given two lists of integers nums0, nums1 and an integer k. 
Find k largest sum pairs where each pair contains one integer in nums0 and another in nums1, 
and return the sum of all of the pairs.

Constraints

0 ≤ n ≤ 100,000 where n is the length of nums0
0 ≤ m ≤ 100,000 where m is the length of nums1
0 ≤ k ≤ 100,000
0 ≤ k ≤ n * m


Example 1:

Input:-
nums0 = [5, 3, 9]
nums1 = [1, 2, 4]
k = 2

Output:-
24

Explanation:-
The 2 largest pairs are (9,2) and (9,4)..therefore the sum of the pairs would be 9+2+9+4=24
"""


def solve(nums0, nums1, k):
    lst=[]
    tot=0
    for i in nums0:
        for j in nums1:
            sum=0
            sum=i+j
            lst.append(sum)
    lst=sorted(lst,reverse=True)
    for i in range(0,k):
        tot=tot+lst[i]
    return tot

n1=int(input(("Enter no. of elements in num list1: ")))
n2=int(input(("Enter no. of elements in num list2: ")))
k=int(input("Enter no. of largest pairs that you need: "))
list1=[]
list2=[]
print("Enter elements of list1 one by one: ")
for i in range(0,n1):
    
    ele1=int(input())
    list1.append(ele1)
    
print("Enter elements of list2 one by one: ")
for j in range(0,n2):
    
    ele2=int(input())
    list2.append(ele2)

ans=solve(list1,list2,k)
print("Sum of the largest " + str(k) + " pairs is",ans)