'''
HEAP SORT
It is a sorting technique based on the heap data structure.
Heap is a complete binary tree, in which every level except the last, is filled
completely with its nodes, and nodes are far left.
We implement this sorting in an array using Max Heap, in which the parent node 
value is greater than it child node values. 
'''
def heapify(arr, length, index):
    # base case
    # we will call this function until the largest number is the index...
    largest_num_index = index
    left_index = (index * 2) + 1
    right_index = (index * 2) + 2
 
    if(left_index < length and arr[index] < arr[left_index]):
        largest_num_index = left_index
 
    if(right_index < length and arr[largest_num_index] < arr[right_index]):
        largest_num_index = right_index
 
    # if index is not the largest, make it the largest!
    # and run it again!
    if(largest_num_index != index):
        arr[index], arr[largest_num_index] = arr[largest_num_index], arr[index]
        heapify(arr, length, largest_num_index)
 
 
def heap_sort(arr):
    # need array length to create indices
    length = len(arr)
 
    for index in range(length, -1, -1):
        # ask about functions modifying arrays without return value
        # build max heap
        heapify(arr, length, index)
 
    # for each sorted heap, swap the root and the last number
    for index in range(length - 1, 0, -1):
        arr[index], arr[0] = arr[0], arr[index]
        # then call heapify again with the new array
        heapify(arr, index, 0)
 
 
# Taking Elements to be Sorted

data = []
n = int(input("Enter elements to be sorted :"))
 
for i in range(n):
    data.append(int(input()))
    
# Sending element to get sorted
heap_sort(data)
 
# Priting Elements after Getting Sorted
for d in data:
    print(d, end = " ")


'''
INPUT
Enter elements to be sorted : 5
30
50
10
20
40

OUTPUT
10 20 30 40 50

Time Complexity:
Best Case: O (nlogn)
Average Case: O (nlogn)
Worst Case: O (nlogn)
Space Complexity: O (1)
'''

