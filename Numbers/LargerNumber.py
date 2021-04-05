'''
Find the larger number n greater than n2 that is divisible by n1.
For eg:
4   7 
output: 8
since 8 is the nearest larger number than 7 and it is divisible by 4.
'''


mn=input().split()

m=int(mn[0])
n=int(mn[1])

print(((n//m)+1)*m)