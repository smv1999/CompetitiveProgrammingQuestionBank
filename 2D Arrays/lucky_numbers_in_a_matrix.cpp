/*
Src : LeetCode
Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
*/

class Solution {
public:
    
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res, maxEles, minEles;
        int r = matrix.size();
        int c = matrix[0].size();
        int max = INT_MIN;
        int min = INT_MAX;
        // find the max element in each column
        for(int j=0;j<c;j++){
        max = INT_MIN;
        for(int i=0;i<r;i++){
            if(matrix[i][j] > max)
                max = matrix[i][j];
        }
            maxEles.push_back(max);
        }
        // find the min element in each row
         for(int i=0;i<r;i++){
             min = INT_MAX;
             for(int j=0;j<c;j++){
            if(matrix[i][j] < min)
                min = matrix[i][j];
         }
             minEles.push_back(min);
        }
        
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j] == maxEles[j] && matrix[i][j] == minEles[i])
                    res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};