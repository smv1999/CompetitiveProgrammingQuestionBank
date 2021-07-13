#Linear Search in python 
#Linear Search is one of the easiest searching algorithm. The main aim of a searching algorithm is to search for a desired element in the whole array. Linear Search sequentially searches for an element in an array.
#algorithm 
#In Linear Search, we start from the 0th index of the array, we compare each element with the key (desired element).
#If the key is same as the element of array ,we return the index of that element.
#If the key does not match any element then ,we return -1.
def search(arr, x): 
    for i in range(len(arr)): 
        if arr[i] == x: 
            return i 
    return -1
    
    
n=int(input("Enter Size of array: "))
arr=[]
print("Enter array elements: ")
for i in range(n):
  e=int(input())
  arr.append(e)
x=int(input("Enter element to be searched: "))
ans=search(arr,x)
if ans==-1:
  print("Element not found ")
else:
  print("Element found at ",ans)
  