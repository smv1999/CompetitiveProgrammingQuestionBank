/*
Src : LeetCode
--------------
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of 
negative numbers in grid.

*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(vector<int> row : grid){
            for(int i=0;i<row.size();i++){
                if(row[i] < 0){
                    count++;
                }
            }
        }
        return count;
    }
};