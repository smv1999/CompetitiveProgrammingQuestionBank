""" Python program to pass list to a function
and double the odd
values and half the even values of the list
and display the list elements after changing
"""

def operator_fn(a):
    new=[]
    for i in a:
        if i%2==0:
            i=i/2
            new.append(i)
        elif i%2!=0:
            i=i*2
            new.append(i)

    a=new
    print(a)

#_main_
a=list(input("Enter the list of numbers")) #getting the list as the input
a=list(a)
operator_fn(a)
