/*
LeetCode : #74
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

1. Integers in each row are sorted from left to right.
2. The first integer of each row is greater than the last integer of the previous row.
*/
#include <vector>
using namespace std; 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(vector<int> v : matrix)
        {
            int first = 0;
            int last = matrix[0].size()-1;
            while(first<=last)
            {
                int mid = (first+last)/2;
                if(v[mid]==target)
                    return true;
                else if(v[mid]<target)
                    first = mid + 1;
                else if(v[mid]>target)
                    last = mid - 1;
            }
        }
        return false;
    }
};