

#https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/?company[]=Morgan%20Stanley&company[]=Morgan%20Stanley&page=1&query=company[]Morgan%20Stanleypage1company[]Morgan%20Stanley


def rotate(a): 
    #code here
    
    n = len(a)
    
    # Transpose
    for i in range(n):
        for j in range(i):
            a[i][j] , a[j][i] = a[j][i] , a[i][j]
            
    # Rotate the rows
    
    for i in range(int(n/2)):
        a[i] , a[n-i-1] = a[n-i-1] , a[i]
    
    return a

#{ 
#  Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N=int(input())
        arr=[int(x) for x in input().split()]
        matrix=[]

        for i in range(0,N*N,N):
            matrix.append(arr[i:i+N])

        rotate(matrix)
        for i in range(N): 
            for j in range(N): 
                print(matrix[i][j], end =' ') 
            print() 
        

# } Driver Code Ends