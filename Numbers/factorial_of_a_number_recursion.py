'''Program to find the factorial of a number using recursion'''

def factorial_of_a_number(n):
    if n<=1:
        return 1
    else:
        return n * factorial_of_a_number(n-1)

#Taking number from user and passing it to the function

n = int(input())
print(factorial_of_a_number(n))