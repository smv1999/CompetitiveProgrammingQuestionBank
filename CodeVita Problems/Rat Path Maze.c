#include<stdio.h>
#define TOT_ROWS 7
#define TOT_COLS 6
#define VISITED 1
#define NOT_VISITED 0
void mazeSolver(int maze[TOT_ROWS][TOT_COLS]);
void mazeSolverUtility(int maze[TOT_ROWS][TOT_COLS],int curr_row,int curr_col,int des_row,int des_col,int visited[TOT_ROWS][TOT_COLS]);
int main()
{
/* int maze[TOT_ROWS][TOT_COLS] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
    };
    */
int maze[TOT_ROWS][TOT_COLS]={
{1,0,1,1,1,1},
{1,1,1,0,0,1},
{1,0,1,1,1,1},
{1,1,0,0,1,1},
{0,1,1,0,0,1},
{0,0,1,0,0,1},
{1,0,1,1,1,1}
};
  mazeSolver(maze);

  return 0;
}
void mazeSolver(int maze[TOT_ROWS][TOT_COLS])
{
    int visited[TOT_ROWS][TOT_COLS]={0};
    int st_row,st_col,des_row,des_col;
    st_row=0;
    st_col=0;
    des_row=TOT_ROWS-1;
    des_col=TOT_COLS-1;
    mazeSolverUtility(maze,st_row,st_col,des_row,des_col,visited);
}
void mazeSolverUtility(int maze[TOT_ROWS][TOT_COLS],int curr_row,int curr_col,int des_row,int des_col,int visited[TOT_ROWS][TOT_COLS])
{
    if(curr_row==des_row&&curr_col==des_col)//base case
    {
      printf("Found Path\n");
      return;
    }
    /* if(BoundaryCheck && visitedCheck && checking depending on problem Statement)
     {

     }*/

    //top
    if(curr_row-1>=0 && visited[curr_row-1][curr_col]==NOT_VISITED && maze[curr_row-1][curr_col]==1)
    {
        visited[curr_row][curr_col]=VISITED;//do
        mazeSolverUtility(maze,curr_row-1,curr_col,des_row,des_col,visited);
        visited[curr_row][curr_col]=NOT_VISITED;//undo
    }
    //right
    if(curr_col+1<TOT_COLS && visited[curr_row][curr_col+1]==NOT_VISITED && maze[curr_row][curr_col+1]==1)
    {
        visited[curr_row][curr_col]=VISITED;//do
        mazeSolverUtility(maze,curr_row,curr_col+1,des_row,des_col,visited);
        visited[curr_row][curr_col]=NOT_VISITED;//undo
    }
    //bottom
    if(curr_row+1<TOT_ROWS && visited[curr_row+1][curr_col]==NOT_VISITED && maze[curr_row+1][curr_col]==1)
    {
        visited[curr_row][curr_col]=VISITED;//do
        mazeSolverUtility(maze,curr_row+1,curr_col,des_row,des_col,visited);
        visited[curr_row][curr_col]=NOT_VISITED;//undo
    }
    //left
    if(curr_col-1>=0 && visited[curr_row][curr_col-1]==NOT_VISITED && maze[curr_row][curr_col-1]==1)
    {
        visited[curr_row][curr_col]=VISITED;//do
        mazeSolverUtility(maze,curr_row,curr_col-1,des_row,des_col,visited);
        visited[curr_row][curr_col]=NOT_VISITED;//undo
    }
}
