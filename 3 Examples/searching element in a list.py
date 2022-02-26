''' write a python program to search for a
roll number in a list and display the
frequency of the roll number present in the list and their
location using linear search by using user defined function.
[list,search element entered by user]
in both forward, backward indexing
hello
       0  1 2  3  4
      -5,-4-3,-2,-1
 '''

def search(list,ser):
    count=0
    for i in range(0,len(list)):
        if list[i]==ser:
            print("Element",ser,"found at forward index",i)
            print("position of element is",i+1)
            count+=1
    print("The frequency of the element is",count)

    for i in range(-1,-len(list)-1,-1):
        if list[i]==ser:
            print("\n Element",ser,"found at backward index",i,"\n")
            print("\n Position of element is",len(list)+i+1,"\n")
            
    print("The frequency of the element is",count)        
            
list=eval(input("Enter the list"))
ser=int(input("enter the element you want to search"))

search(list,ser)   
