#Stack implementation using lists
stack=[]

def push():
    upper=int(input("Enter the upper limit of the stack <max no. of elements"))
    
    while True:
        if len(stack)==upper:
            print("Upper limit reached stack overflow")
            choice=input("Do you want to perform other opperations? y/n : ")
            if choice in ["y","Y"]:
                main()
                break
            else:
                print("Exiting")
        x=eval(input("Enter the element to be pushed in the stack:"))
        stack.append(x)
        print("Element pushed successfully")
        ch=input("Do you want to enter more elements?: y/n")
        if ch in["n","N"]:
            choice=input("Do you want to perform other opperations? y/n : ")
            if choice in ["y","Y"]:
                main()
                break
            else:
                print("Exiting")

def pop():
    while True:
        if len(stack)==0:
            print("No element left in stack underflow")
            choice=input("Do you want to perform other opperations? y/n : ")
            if choice in ["y","Y"]:
                main()
                break
            else:
                print("Exiting")

        print("Original stack =",stack)
        y=stack.pop()
        print("Element removed :",y)
        print("Current stack :",stack)
        ch=input("Do you want to pop more elements? y/n :")
        if ch in["n","N"]:
            choice=input("Do you want to perform other opperations? y/n : ")
            if choice in ["y","Y"]:
                main()
                break
            else:
                print("Exiting")

def peek():
    # This should return the last element appended to stack
    top=len(stack)-1
    print("The peek of the stack is",stack[top])
    if len(stack)==0:
        print("Stack doesnot contain any element")

    choice=input("Do you want to perform other opperations? y/n : ")
    if choice in ["y","Y"]:
            main()
          
    else:
        print("Exiting")
    
def display():
    print("The stack is",stack)
    choice=input("Do you want to perform other opperations? y/n : ")
    if choice in ["y","Y"]:
            main()
    else:
        print("Exiting")
    
def main():
    print("STACK OPPERATIONS menue \n")
    print("1.PUSH ITEM IN STACK")
    print("2.POP ELEMENT IN STACK")
    print("3.VIEW PEEK OF THE STACK")
    print("4.DISPLAY THE STACK")
    print("5.EXIT \n")
    ch=int(input("Enter your choice 1,2,3,4,5"))
    if ch==1:
        push()
    elif ch==2:
        pop()
    elif ch==3:
        peek()
    elif ch==4:
        display()
    elif ch==5:
        print("Exiting")
    else:
        print("Invalid choice try again")
        main()
main()
# initial start
    
