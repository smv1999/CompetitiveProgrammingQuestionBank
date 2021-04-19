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
