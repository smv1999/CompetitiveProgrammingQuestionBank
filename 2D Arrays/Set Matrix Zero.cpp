/*______________________________________________________________________PROBLEM___________________________________________________________*/

/*Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.
   Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

 EXAMPLE 1:
 Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
 Output: [[1,0,1],[0,0,0],[1,0,1]]
 
 EXAMPLE 2:
 Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 
 
 
 Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
*/
 

class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        set<int>row,col;
        
      for(int i=0;i<m.size();i++){
          for(int j=0;j<m[0].size();j++){
              if(m[i][j]==0){
                  row.insert(i);
                  col.insert(j);
              }
          }
      }
    
    
        for(auto it=row.begin();it!=row.end();it++){
            for(int j=0;j<m[0].size();j++){
                m[*it][j]=0;
            }
            
        }
        for(auto it=col.begin();it!=col.end();it++){
            for(int j=0;j<m.size();j++){
                m[j][*it]=0;
            }
        }
    }
