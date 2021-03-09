def stairCaseSearch(matrix , key):
	n , m = len(matrix) , len(matrix[0])
	i , j = 0 , m - 1

	isFound = False

	while(i <= n - 1 and j >= 0):
		if(matrix[i][j] == key):
			isFound = True
			print("Found at : " , i , j)
			break
		elif(matrix[i][j] > key):
			j -= 1
		else:
			i += 1

	if(not(isFound)):
		print("Key not found")

n = int(input("Enter the no. of rows in the matrix : "))
m = int(input("ENter the no. of columns in the matrix : "))

matrix = []
print("Enter the elements of the Row and Column sorted matrix : ")
for i in range(n):
	rows = [int(j) for j in input().split()]
	matrix.append(rows)

key = int(input("Enter the key to search : "))

stairCaseSearch(matrix , key)
