'''This is a Program to reverse an array
 i.e. Input: 1,2,3,4,5
 Output:5,4,3,2,1'''

# Taking array input
l=input().split()

#Creating reverse array
r=[]
for i in range(0,len(l)):
    r.append(int(l[len(l)-i-1]))

print(r)

