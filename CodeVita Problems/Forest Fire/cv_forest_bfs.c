#define TOT_ROWS 5
#define TOT_COLS 5
#define VISITED 1
#define NOT_VISITED 0
#include<stdio.h>

typedef struct queue
{
    int r;
    int c;
    int qCtr;

}Q;
int front=-1,rear=-1;
int findSpreadUtility(char mat[TOT_ROWS][TOT_COLS],int start_row, int start_col,int visited[TOT_ROWS][TOT_COLS]);
Q deQ(Q forest[]);
void findSpread(char mat[TOT_ROWS][TOT_COLS],int start_row, int start_col);
void enQ( Q forest[] , Q enQdata);

int main()//function entry point to the program
{
 /*
 char mat[TOT_ROWS][TOT_COLS]={
 {'T','W','W','W','W','T' },
 {'T','W','T','W','W','T' },
 {'T','T','W','W','W','T' },
 {'T','W','W','W','W','T' },
 {'T','T','T','T','T','T' },
 };
 */
/*char mat[TOT_ROWS][TOT_COLS]=
{
 {'W','T','T','T','T','T'},
 {'T','W','W','W','W','W'},
{'W','T','T','T','T','T'},
{'W','W','W','W','W','T'},
{'T','T','T','T','T','T'},
{'T','W','W','W','W','W'}
};
*/
char mat[TOT_ROWS][TOT_COLS]=
{
 {'W','W','T','W','W'},
 {'W','W','T','T','W'},
{'W','T','T','T','W'},
{'T','T','W','W','T'},
{'W','W','W','T','W'},
};

 /*
 char mat[TOT_ROWS][TOT_COLS]={
 {'T','W','W','W','W','T' },
 {'T','T','W','W','W','T' },
 {'T','W','W','W','W','T' },
 {'T','W','W','W','W','T' },
 {'T','T','T','T','T','T' },
 };
 */

 findSpread(mat,2,2);

 return 0;
}

void findSpread(char mat[TOT_ROWS][TOT_COLS],int start_row, int start_col)
{
    int visited[TOT_ROWS][TOT_COLS]={0};

   printf("%d ", findSpreadUtility(mat,start_row,start_col,visited));
}
void enQ( Q forest[] , Q enQdata)
{
    if(front==-1)
        front++;
    forest[++rear]=enQdata;
}

Q deQ(Q forest[])
{
    Q toReturn={-1,-1,-1};
    if(front> rear)//empty queue
        return toReturn;
    toReturn = forest[front];
    front++;
    return toReturn;
}
int findSpreadUtility(char mat[TOT_ROWS][TOT_COLS],int start_row, int start_col,int visited[TOT_ROWS][TOT_COLS])
{
    Q forest[TOT_ROWS*TOT_COLS];
    Q tempdata,deQdata;
    int seconds_ctr,curr_row,curr_col,safe=0;

    tempdata.r=start_row;
    tempdata.c=start_col;
    tempdata.qCtr=1;
    enQ(forest,tempdata);
    visited[start_row][start_col]=VISITED;
  while(1)
  {
    deQdata=deQ(forest);
    curr_row = deQdata.r;
    curr_col = deQdata.c;
    seconds_ctr = deQdata.qCtr;
    if(seconds_ctr>safe)
        safe=seconds_ctr;
    if(curr_row==-1||curr_col==-1)
        break;
    //top
    if(curr_row-1>=0 && mat[curr_row-1][curr_col]=='T' && visited[curr_row-1][curr_col]==NOT_VISITED)
    {
         tempdata.r=curr_row-1;
        tempdata.c=curr_col;
        tempdata.qCtr=seconds_ctr+1;
        enQ(forest,tempdata);
        visited[curr_row-1][curr_col]=VISITED;
    }
    //right top
    if(curr_row-1>=0 &&curr_col+1<TOT_COLS&& mat[curr_row-1][curr_col+1]=='T' && visited[curr_row-1][curr_col+1]==NOT_VISITED)
    {
         tempdata.r=curr_row-1;
        tempdata.c=curr_col+1;
        tempdata.qCtr=seconds_ctr+1;
        enQ(forest,tempdata);
        visited[curr_row-1][curr_col+1]=VISITED;
    }
    //right
    if(curr_col+1<TOT_COLS&& mat[curr_row][curr_col+1]=='T' && visited[curr_row][curr_col+1]==NOT_VISITED)
    {
         tempdata.r=curr_row;
        tempdata.c=curr_col+1;
        tempdata.qCtr=seconds_ctr+1;
        enQ(forest,tempdata);
        visited[curr_row][curr_col+1]=VISITED;
    }
    //right bottom
   if(curr_row+1<TOT_ROWS &&curr_col+1<TOT_COLS&& mat[curr_row+1][curr_col+1]=='T' && visited[curr_row+1][curr_col+1]==NOT_VISITED)
    {
         tempdata.r=curr_row+1;
        tempdata.c=curr_col+1;
        tempdata.qCtr=seconds_ctr+1;
        enQ(forest,tempdata);
        visited[curr_row+1][curr_col+1]=VISITED;
    }
    //bottom
   if(curr_row+1<TOT_ROWS&& mat[curr_row+1][curr_col]=='T' && visited[curr_row+1][curr_col]==NOT_VISITED)
    {
         tempdata.r=curr_row+1;
        tempdata.c=curr_col;
        tempdata.qCtr=seconds_ctr+1;
        enQ(forest,tempdata);
        visited[curr_row+1][curr_col]=VISITED;
    }
    //left bottom
   if(curr_row+1<TOT_ROWS &&curr_col-1>=0&& mat[curr_row+1][curr_col-1]=='T' && visited[curr_row+1][curr_col-1]==NOT_VISITED)
    {
        tempdata.r=curr_row+1;
        tempdata.c=curr_col-1;
        tempdata.qCtr=seconds_ctr+1;
        enQ(forest,tempdata);
        visited[curr_row+1][curr_col-1]=VISITED;
    }
    //left
   if(curr_col-1>=0&& mat[curr_row][curr_col-1]=='T' && visited[curr_row][curr_col-1]==NOT_VISITED)
    {
        tempdata.r=curr_row;
        tempdata.c=curr_col-1;
        tempdata.qCtr=seconds_ctr+1;
        enQ(forest,tempdata);
        visited[curr_row][curr_col-1]=VISITED;
    }
    //left top
    if(curr_row-1>=0 &&curr_col-1>=0&& mat[curr_row-1][curr_col-1]=='T' && visited[curr_row-1][curr_col-1]==NOT_VISITED)
    {
        tempdata.r=curr_row-1;
        tempdata.c=curr_col-1;
        tempdata.qCtr=seconds_ctr+1;
        enQ(forest,tempdata);
        visited[curr_row-1][curr_col-1]=VISITED;
    }

  }
 return safe;
}
