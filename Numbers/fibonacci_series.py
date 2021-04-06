'''Fibonacci series upto n value'''

# taking user input-1
n = int(input())

a=0
b=1

if(a<=n):
    print(a," ",end="")
    if(b<=n):
        print(b," ",end="")
        c=a+b
        while(c<=n):
            print(c," ",end="")
            a=b
            b=c
            c=a+b
else:
    print("None of the values in fibonacci series are less than",n)