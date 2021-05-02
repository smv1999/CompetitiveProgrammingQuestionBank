#  Write a program to reverse an array
# Given an array (or string), the task is to reverse the array/string.
# Examples : 
 
# Input  : arr[] = [1, 2, 3]
# Output : arr[] = [3, 2, 1]
# Input :  arr[] = [4, 5, 1, 2]
# Output : arr[] = [2, 1, 5, 4]




# Reverse of an array can be implented in Python using the List slicing 

def reverseList(a):
      print( a[::-1])

# Driver Code
arr = [4,5,1,2]
print(arr)
print("Reverse : ")
reverseList(arr) 