# BINARY SEARCH 

# It is a searching algorithm which is more efficient than linear search. It can find an element if present in O(log(n)) time complexity.
# For this algorithm to work, the array should be in sorted order
# it returns the position of the element in the array


def binary_search (arr, item):
    """The binary_Search function takes input the sorted list of elements and the item to be searched
        and returns the position of the item, if found in the list, else it returns -1 """
    beg, end = 0, len(arr)-1
    mid = (beg+end)//2

    while beg<=end:
        mid = (beg+end)//2
        if arr[mid] == item :
            return mid
        elif arr[mid] > item:
            end = mid-1
        elif arr[mid] < item:
            beg = mid+1
    return -1                   # return -1 if the element is not present in the array



## DRIVER CODE

test_arr = [1,2,3,4,5]      # this should be a sorted array
test_item = 2               # this is the item to be searched

ans = binary_search(test_arr, test_item)
if ans != -1 :
    print(f"Element found at index position {ans}")
else:
    print("Element is not present in array")