# Question : https://leetcode.com/problems/search-a-2d-matrix/

# Search an element in array
#Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

# Integers in each row are sorted from left to right.
# The first integer of each row is greater than the last integer of the previous row.

# Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
# Output: true

#1. Apply Binary Search on every row 
# Iterate through every row and consider each row as an array and apply binary Search

class Solution:
    def searchMatrix(self, matrix, target):
        
        output = False
        if len(matrix) == 1 and len(matrix[0]) == 1:
            if target == matrix[0][0]:return True 
            else:return False
            
        j = len(matrix[0]) - 1
        for i in range(len(matrix)):
            if target == matrix[i][j]:
                return True
            elif target < matrix[i][j]:
                output = self.search(matrix[i], target)
                break
        return output
    
    def search(self, arr, target):
        beg_index = 0
        end_index = len(arr) - 1
        while beg_index <= end_index :
            mid = (beg_index + end_index ) // 2
            if arr[mid] == target:
                return True
            elif target < arr[mid]:
                end_index = mid - 1
            else:
                beg_index = mid + 1
        return False