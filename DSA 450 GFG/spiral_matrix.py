# Link to the problem : https://leetcode.com/problems/spiral-matrix/

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        n = len(matrix)
        if (n == 0):
          return matrix
        
        # Initialize the Boundaries
        rowBeg = 0
        rowEnd = len(matrix) - 1
        colBeg = 0 
        colEnd = len(matrix[0]) - 1
        
        #Right Traversal
        while(rowBeg <= rowEnd and colBeg <= colEnd):
          
          for i in range(colBeg , colEnd + 1):
            res.append(matrix[rowBeg][i])
          rowBeg += 1

        #Bottom Traversal
          for i in range(rowBeg , rowEnd + 1):
            res.append(matrix[i][colEnd])
          colEnd -= 1
        
        #Left Traversal
        
          if(rowBeg <= rowEnd):
            for i in range(colEnd  , colBeg - 1  , -1 ):
              res.append(matrix[rowEnd][i])
          rowEnd -= 1
        
        #Upward Traversal
        
          if(colBeg <= colEnd):
            for i in range(rowEnd  , rowBeg - 1 , -1):
              res.append(matrix[i][colBeg])  
          colBeg += 1
        
        return res