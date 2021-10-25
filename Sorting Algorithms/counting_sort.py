'''
Counting sort is a sorting algorithm that sorts the elements of an
array by counting the number of occurrences of each unique element in the array.
In this program default 'k' is 1000.

Algorithm
In Counting Sort, we will follow the following step-wise process:

First we will store the occurrence of elements in a count array.

Modify the count array such that every index store the sum of the previous count.

Traverse the given array from the end (so that stability maintains) and put the elements by checking our modified count array and the given input array.

And take a final array (output) and store the elements.

We get our sorted elements in the output array.
'''

def counting_sort(l, k=None):
    #  creating an array for counting elements
    if k == None:
        arr = [0]*1000
    else:
        arr = [0]*(k+1)
    # counting the occurrence of elements
    for i in l:
        arr[i]+=1
    # generating sorted array
    l=[]
    for i in range(len(arr)):
        l+=[i]*arr[i]
    return l


if __name__ == "__main__":
    l = list(map(int,input("Enter the elements of the list to be sorted:").split()))
    l = counting_sort(l)
    print("List after sorting:",*l)

'''
INPUT
Enter the elements of the list to be sorted:12 0 1 3 5 3 3 2 1 1
OUTPUT
List after sorting:0 1 1 1 2 3 3 3 5 12

Worst Case Complexity: O(n+k)
Best Case Complexity: O(n+k)
Average Case Complexity: O(n+k)
where n is size of an array , and k is element range of the array.
'''