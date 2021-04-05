'''
Example - 1 2 3 4 6 3 3 5 5

Duplicates are -> 3 5
'''

# Taking array input
l=input().split()

# Changing string array to integer array
for i in range(0,len(l)):
    l[i]=int(l[i])

newl=[]
dupli=[]

# Logic for catching duplicate elements
for i in l:
    if i not in newl:
        newl.append(i)
    else:
        if i not in dupli:
            dupli.append(i)

print(dupli)