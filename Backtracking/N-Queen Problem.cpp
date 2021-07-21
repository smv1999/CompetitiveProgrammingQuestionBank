/* N-Queen Problem


You have to place n queens on an nxn chessboard.
Idea: Try all the possible positions for the queen. isSafe functions check whether
the current position is safe or not

*/

#include<iostream>
using namespace std;

	
bool isSafe(int board[][10], int i, int j, int n){
	//Check in col
		
	for(int row=0;row<i;row++){
		if(board[row][j] == 1){
			return false;
		}
	}
	//Left diagonal
	int x=i;
	int y=j;
		
	while(x>=0 && y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}
	//Right diagonal
	x=i;
	y=j;
		
	while(x>=0 && y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y++;
	}
	//The position is safe
	return true;
	
	
}

bool nQueen(int board[][10], int i,int n){
	if(i==n){//base case
	// Place Queeen in n rows (0..n-1)
	//print the board
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(board[i][j]==1){
				cout<<"Q ";
			}
			else{
				cout<<"_ ";
			}
		}
		cout<<endl;
	}
		return true;
	}
	//Recursive case
	
	for(int j=0;j<n;j++){
		//Check i,j th position is safe to place the queen or not.
		if(isSafe(board,i,j,n)){
			//Place the Queen ,i, j in the right position
			board[i][j]=1;
			
			if(nQueen(board,i+1,n)){
				return true;
			}
			//Means i,j is not the right position
			board[i][j]=0; //backtracking
		}
	}
	//coudln't place the queen in current position.
	return false;
}
		
	
int main(){
	int n;
	cin>>n;
	
	int board[10][10]={0};
	nQueen(board,0,n);
	
	return 0;
	
}

/* Input:
4

Output:

_ Q _ _
_ _ _ Q
Q _ _ _
_ _ Q _

*/
