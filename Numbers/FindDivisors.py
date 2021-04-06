'''Finding factors of a number'''
import math

n=int(input())

l=[]

for i in range(1,int(math.sqrt(n))+1):
    if(n%i==0):
        l.append(i)

print(l)