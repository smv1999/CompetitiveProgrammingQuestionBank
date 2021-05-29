# Link for the problem : https://practice.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1


def snakePattern(matrix): 
   # code here 
    n_rows = len(matrix)
    n_columns = len(matrix[0])
    k = 0 
    output = []
    
    for i in range(0 , n_rows):
        if(i%2 == 0):
            for j in range(0 , n_columns):
                output.append(matrix[i][j])
        elif(i%2 != 0):
            for j in range(n_columns-1 , -1, -1):
               output.append(matrix[i][j])
      
    return output


#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        values = list(map(int, input().strip().split()))
        k = 0
        matrix =[]
        for i in range(n):
            row=[]
            for j in range(n):
                row.append(values[k])
                k+=1
            matrix.append(row)
        ans = snakePattern(matrix)
        for i in ans:
            print(i,end=" ")
        print()


# } Driver Code Ends