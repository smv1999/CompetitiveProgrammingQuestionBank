'''Program to find the factorial of a number using recursion'''

#Taking number from user and finding its factorial using loop
n = int(input())
fact=1
for i in range(1,n+1):
    fact*=i

print(fact)