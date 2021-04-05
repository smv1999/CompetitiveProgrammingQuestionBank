'''
Given two arrays: arr1[0..m-1] of size m and arr2[0..n-1] of size n. Task is to check whether arr2[] is a subset
of arr1[] or not. Both the arrays can be both unsorted or sorted. It may be assumed that elements in both array are distinct.
'''

# Taking array input
l1=input().split()
l2=input().split()

#Creating array of common elements
r=[]
for i in l1:
    if i in l2:
        r.append(i)

if r==l2:
    print("Array 2 is the subset of Array 1")
else:
    print("Array 2 is NOT the subset of Array 1")