#include<bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(int i = a;i<b;i++)
class Solution
{
    public:
    //Function to find minimum time required to rot all oranges.
    void solve(int r, int c, queue<pair<int,int>>&q, vector<vector<int>>&grid){
        int rr[4] = {-1,1,0,0};
        int cc[4] = {0,0,-1,1};
        for(int i = 0;i<4;i++){
            int nr = r + rr[i];
            int nc = c + cc[i];

            if(nr<0 || nc<0 || nr>=grid.size()|| nc>=grid[0].size())continue;
            if(grid[nr][nc] == 1){
                grid[nr][nc] = 2;
                q.push({nr,nc});
            }

        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        f(i,0,grid.size()){
            f(j,0,grid[0].size()){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int timer = -1;
        while(!q.empty()){
            int k = q.size();
            while(k--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                solve(r,c,q,grid);
            }
            timer++;
        }
        for(auto i: grid){
            for(auto j :i){
                if(j == 1)return -1;
            }

        }
        return timer;


    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  //
