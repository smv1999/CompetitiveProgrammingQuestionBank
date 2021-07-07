# function to find the partition position

def partition(array, low, high):
  pivot = array[high]        #pivot element

  #index of smaller element
  i = low - 1

  # traverse through all elements
  # compare each element with pivot
  for j in range(low, high):
    if array[j] <= pivot:
      # if current element smaller than pivot is found
      #increment index of smaller element
      i = i + 1             

      # swapping element at i with element at j
      (array[i], array[j]) = (array[j], array[i])

  # swap the pivot element with the greater element specified by i
  (array[i + 1], array[high]) = (array[high], array[i + 1])

  # return the position from where partition is done
  return i + 1

# quicksort function
def quickSort(array, low, high):
  if low < high:
    #pi is partitioning index
    pi = partition(array, low, high)

    # Separately sort elements before partition and after partition 
    quickSort(array, low, pi - 1)
    quickSort(array, pi + 1, high)


size= int(input("Enter number of elements "))
data=list(map(int,input("\nEnter the numbers: ").strip().split()))[:size]
print("Unsorted Array")    
print(data)
quickSort(data, 0, size - 1)
print('Sorted Array in Ascending Order:')
print(data)
