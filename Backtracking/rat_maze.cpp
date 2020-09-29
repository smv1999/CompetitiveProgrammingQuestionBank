#include<iostream>
#define TOT_ROWS 4
#define TOT_COLS 4
using namespace std;

void printArray(int sol[TOT_ROWS][TOT_COLS])
{
    for(int outer=0;outer<TOT_ROWS;outer++,printf("\n"))
    {
        for(int inner=0;inner<TOT_COLS;inner++)
        {
            cout<<sol[inner][outer]<<" ";
        }
    }
}
void mazeSolverUtility(int row,int col, int maze[TOT_ROWS][TOT_COLS],int sol[TOT_ROWS][TOT_COLS],int curr_row, int curr_col)
{
    if((curr_row==row-1) && (curr_col==col-1) && maze[curr_row][curr_col]==1)
    {
        sol[curr_row][curr_col] = 1;
        printArray(sol);
        return;
    }
    //right
    if(curr_col+1<col && maze[curr_row][curr_col+1]==1)
    {
        sol[curr_row][curr_col+1] = 1;
        mazeSolverUtility(row,col,maze,sol,curr_row,curr_col+1);
        sol[curr_row][curr_col+1] = 0;
    }
    //down
    if(curr_row+1<row && maze[curr_row+1][curr_col]==1)
    {
        sol[curr_row+1][curr_col] = 1;
        mazeSolverUtility(row,col,maze,sol,curr_row+1,curr_col);
        sol[curr_row+1][curr_col] = 0;
    }
}
void mazeSolver(int maze[TOT_ROWS][TOT_COLS])
{
    int sol[TOT_ROWS][TOT_COLS] = {{ 0, 0, 0, 0 },
                       { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 } };
    mazeSolverUtility(TOT_ROWS,TOT_COLS,maze,sol,0,0);
    //printArray(sol);
}

int main()
{
   int maze[TOT_ROWS][TOT_COLS] =
                     { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };
    mazeSolver(maze);

    return 0;
}
