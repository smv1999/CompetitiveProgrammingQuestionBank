// Given a dictionary of distinct words and an M x N board where every cell has one character. Find all possible words from the dictionary that can be formed by a sequence of adjacent characters on the board. We can move to any of 8 adjacent characters, but a word should not have multiple instances of the same cell.
// Example 1:

// Input:
// N = 1
// dictionary = {"CAT"}
// R = 3, C = 3
// board = {{C,A,P},{A,N,D},{T,I,E}}
// Output:
// CAT
// Explanation:
// C A P
// A N D
// T I E
// Words we got is denoted using same color.
// Example 2:

// Input:
// N = 4
// dictionary = {"GEEKS","FOR","QUIZ","GO"}
// R = 3, C = 3
// board = {{G,I,Z},{U,E,K},{Q,S,E}}
// Output:
// GEEKS QUIZ
// Explanation:
// G I Z
// U E K
// Q S E
// Words we got is denoted using same color.

// Companies
// Amazon Directi Facebook Google MakeMyTrip Microsoft Nvidia Yahoo

// Expected Time Complexity: O(NW + RC^2)
// Expected Auxiliary Space: O(NW + RC)
------------------------------------------------------------

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

