# Maximum and minimum of an array using minimum number of comparisons - Python

def getMinMax(arr):
	
	n = len(arr)
	
	# If array has even number of elements then initialize the first two elements as minimum and maximum
	if(n % 2 == 0):
		maximum = max(arr[0], arr[1])
		minimum = min(arr[0], arr[1])
		
		# set the starting index for loop
		i = 2
		
	# If array has odd number of elements then initialize the first element as minimum and maximum
	else:
		maximum = minimum = arr[0]
		
		# set the starting index for loop
		i = 1
		
	# In the while loop, pick elements in pair and compare the pair with max and min so far
	while(i < n - 1):
		if arr[i] < arr[i + 1]:
			maximum = max(maximum, arr[i + 1])
			minimum = min(minimum, arr[i])
		else:
			maximum = max(maximum, arr[i])
			minimum = min(minimum, arr[i + 1])
			
		# Increment the index by 2 as two elements are processed in loop
		i += 2
	
	return (maximum, minimum)
	
# Driver Code
if __name__ =='__main__':
	
	arr = [9, 1, 45, 2, 330, 3]
	maximum, minimum = getMinMax(arr)
	print("Minimum element is", minimum)
	print("Maximum element is", maximum)
	

