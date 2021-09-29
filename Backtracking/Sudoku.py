'''
Aim: Given a 9*9 sudoku board, in which some entries are filled and others are 0 
    (0 indicates that the cell is empty), you need to find out whether the Sudoku 
    puzzle can be solved or not i.e. return true or false.
    
'''

# checking if move could be made or not
def isSafeToPut(i,j,option,board,n):
    for k in range(n):
        if board[k][j]==option or board[i][k]==option:
            return False
        
    # finding the dimensions of the 3 X 3 box 
    starti=(i//3)*3
    startj=(j//3)*3

    for p in range(starti,starti+3):
        for q in range(startj,startj+3):
            if board[p][q]==option:
                return False
    
    return True

# applying basic rules of the game to find the result
def sudokuSolver(i,j,board,n):
    if i==n:
        return True
    
    if j==n:
        return sudokuSolver(i+1,0,board,n)

    if board[i][j]!=0:
        return sudokuSolver(i,j+1,board,n)
    
    # checking if it's safe to put a number at a place
    for option in range(1,10):
        if isSafeToPut(i,j,option,board,n):
            board[i][j]=option
            canWeMoveFwd=sudokuSolver(i,j+1,board,n)
            if canWeMoveFwd is True:
                return True
            board[i][j]=0

    return False

# getting the input
board = [[ int(ele) for ele in input().split() ]for i in range(9)]
ans = sudokuSolver(0,0,board,9)

# printing out the results
print(ans)

'''

Sample Input:   
 9 0 0 0 2 0 7 5 0 
 6 0 0 0 5 0 0 4 0 
 0 2 0 4 0 0 0 1 0 
 2 0 8 0 0 0 0 0 0 
 0 7 0 5 0 9 0 6 0 
 0 0 0 0 0 0 4 0 1 
 0 1 0 0 0 5 0 8 0 
 0 9 0 0 7 0 0 0 4 
 0 8 2 0 4 0 0 0 6
 
Sample Output:  
True

Explanation:
According to the rules of sudoku, this can be solved.

COMPLEXITY:
    
     Time Complexity = O(9^(N*N))
     Space complexity = O(N)
     
''' 