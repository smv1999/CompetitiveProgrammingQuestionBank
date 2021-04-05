'''Finding common elements between two arrays in which the elements are distinct.
Eg:

1 2 3 4 5 12 8
6 7 3 4 2 9 11


O/P:
2 3 4 '''

# Taking array input
l1=input().split()
l2=input().split()

#Creating array of common elements
r=[]
for i in l1:
    if i in l2:
        r.append(i)

print(r)

