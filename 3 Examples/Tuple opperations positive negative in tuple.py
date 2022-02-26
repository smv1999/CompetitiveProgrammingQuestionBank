#Input numbers in a tuple and pass it to a function to count
#how many positive and negative numbers are entered

def positive_negative():
    count_pos=0
    count_neg=0
    count0=0

    value=eval(input("Enter the tuple of numbers"))
    for i in value:
        if i>0:
            count_pos+=1

        elif i<0:
            count_neg+=1

        elif i==0:
            count0+=1

        else:
            print("You have entered an invalid value")
            
    print("There are",count_pos," positive numbers")
    print("There are",count_neg," negative numbers")
    print("There are",count0," zeros")

positive_negative()            
