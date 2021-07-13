
#Bubble sort is a sorting algorithm. Sorting algorithms are used to arrange the array in particular order.In,Bubble sort larger elements are pushed at the end of array in each iteration.It works by repeatedly swapping the adjacent elements if they are in wrong order.

def bubbleSort(a): 
    n = len(a) 
    # Traverse through all array elements 

    for i in range(n-1): 
        # Last i elements are already in place 
        for j in range(0, n-i-1): 

            # traverse the array from 0 to n-i-1 
            # Swap if the element found is greater 
            # than the next element 
            if arr[j] > arr[j + 1] : 
                arr[j], arr[j + 1] = arr[j + 1], arr[j] 

arr = []
n=int(input("Enter size of array: "))
for i in range(n):
    e=int(input())
    arr.append(e)
bubbleSort(arr)
print ("Sorted array is:")
for i in range(len(arr)):
     print(arr[i])
     
#Time complexity - O(n^2)
#Space complexity - O(1)
