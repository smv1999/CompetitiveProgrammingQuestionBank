#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isfullyfound(int r, int c, int index, vector<vector<char>>& board, vector<vector<bool>>&visited, string word){
        if(index == word.size()){
            return true;
        }
        if(r>=0 && r<board.size() && c>=0 && c<board[0].size() && !visited[r][c] && word[index] == board[r][c]){
            visited[r][c] = true;
            if( isfullyfound(r-1,c,index+1,board,visited,word) ||
                isfullyfound(r+1,c,index+1,board,visited,word) ||
                isfullyfound(r,c-1,index+1,board,visited,word) ||
                isfullyfound(r,c+1,index+1,board,visited,word) ||
                isfullyfound(r+1,c+1,index+1,board,visited,word) ||
                isfullyfound(r+1,c-1,index+1,board,visited,word) ||
                isfullyfound(r-1,c-1,index+1,board,visited,word) ||
                isfullyfound(r-1,c+1,index+1,board,visited,word)
            )return true;

            visited[r][c] = false;
        }
        return false;
    }
    bool wordfound(string word,vector<vector<char>>& board){
        int index = 0;
        vector<vector<bool>>visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(word[index] == board[i][j]){
                    if(isfullyfound(i,j,index,board,visited,word)){
                        return true;
                    }
                }
            }
        }
        return false;

    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    vector<string>v;
	    for(auto i: dictionary){
	        if(wordfound(i,board)){
	            v.push_back(i);
	        }
	    }
	    return v;
	}
};

