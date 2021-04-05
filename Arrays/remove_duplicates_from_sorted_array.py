# Taking array input
l=input().split()

# Changing string array to integer array
for i in range(0,len(l)):
    l[i]=int(l[i])

#sorting
l.sort()

#Removing duplicate elements
newl = []
if(len(l)>0):
    newl.append(l[0])
    for i in range(1,len(l)):
        if l[i-1]!=l[i]:
            newl.append(l[i])

print(newl)


