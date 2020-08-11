#include<stdio.h>
#define TOT_ROWS 5
#define TOT_COLS 7
#define VISITED 1
#define NOT_VISITED 0
#include<limits.h>
typedef struct positions
{
    int r;
    int c;
}POS;
void visitedFill(int visited[TOT_ROWS][TOT_COLS]);

int find_path_ani(char maze[TOT_ROWS][TOT_COLS],POS start , POS des ,int visited[TOT_ROWS][TOT_COLS],int path_len,int first_time_flag);
int find_path_grass(char maze[TOT_ROWS][TOT_COLS],POS start , POS des ,int visited[TOT_ROWS][TOT_COLS],int path_len,int first_time_flag);


int main()
{
char mat[TOT_ROWS][TOT_COLS]={{' ',' ',' ',' ',' ',' ',' '},
                {' ','W','M','G','G','G','G'},
                {' ','M','G','W','G','M','M'},
                {' ','G','W','G','G','G','G'},
                {' ','W','G','W','M','W','G'}};
  POS gate_pos[3]={{1,6},{3,6},{4,6}};
  POS ani_pos={3,4};
  POS tempStart;
  int visited[TOT_ROWS][TOT_COLS];
  int path_len,ind,first_time_flag,row,col,grassCount=0,grass_path,safe=0;
  int ani_path_len[3];
 for(ind=0;ind<3;ind++)
 {
  visitedFill(visited);
  path_len=first_time_flag=0;
   ani_path_len[ind]=find_path_ani(mat,ani_pos,gate_pos[ind],visited,path_len,first_time_flag);
 }
// for(ind=0;ind<3;ind++)
 // printf("%d ",ani_path_len[ind]);

  for(row=1;row<TOT_ROWS;row++)
  {
      for(col=1;col<TOT_COLS;col++)
      {
          if((row==gate_pos[0].r&&col==gate_pos[0].c)||(row==gate_pos[1].r&&col==gate_pos[1].c)||(row==gate_pos[2].r&&col==gate_pos[2].c))
          {
              safe++;
              grassCount++;
              continue;
          }
          if(row==ani_pos.r&&col==ani_pos.c)
          {
              grassCount++;
              continue;
          }
          if(mat[row][col]=='G')
          {
              grassCount++;
              tempStart.r=row;
              tempStart.c=col;
              for(ind=0;ind<3;ind++)
              {
               visitedFill(visited);
               path_len=first_time_flag=0;
               grass_path=find_path_grass(mat,tempStart,gate_pos[ind],visited,path_len,first_time_flag);
               if(grass_path < ani_path_len[ind])//safer path found
               {
                   safe++;
                   break;
               }
              }
              if(grass_path==INT_MAX)//human cannot move to gate
              {
                  //check for animal can reach human
                  visitedFill(visited);
                  path_len=first_time_flag=0;
                  path_len=find_path_ani(mat,ani_pos,tempStart,visited,path_len,first_time_flag);
                  if(path_len==INT_MAX)//animal cannot reach human
                  {
                      safe++;
                  }
              }
          }
      }
  }
  printf("%d %d %.2f",safe,grassCount,(safe*100.0)/grassCount);
  return 0;
}

int find_path_grass(char maze[TOT_ROWS][TOT_COLS],POS start , POS des ,int visited[TOT_ROWS][TOT_COLS],int path_len,int first_time_flag)
{
 static int min_path=INT_MAX;
 POS tempStart;
 if(first_time_flag==0)
 {
  min_path=INT_MAX;
  first_time_flag=1;
 }
 //base condition
 if(start.r==des.r && start.c==des.c)
 {
     if(path_len < min_path) //finding minimum out of all paths
        min_path=path_len;
     return min_path;
 }
 //top
 if(start.r-1>=1 && visited[start.r-1][start.c]==NOT_VISITED&&
    (maze[start.r-1][start.c]=='G'))
 {
     visited[start.r][start.c]=VISITED;//do
     tempStart.r=start.r-1;
     tempStart.c=start.c;
     find_path_grass(maze,tempStart,des,visited,path_len+1,first_time_flag);
     visited[start.r][start.c]=NOT_VISITED;//undo
 }
 //right
 if(start.c+1<TOT_COLS && visited[start.r][start.c+1]==NOT_VISITED&&
    (maze[start.r][start.c+1]=='G'))
 {
     visited[start.r][start.c]=VISITED;//do
     tempStart.r=start.r;
     tempStart.c=start.c+1;
     find_path_grass(maze,tempStart,des,visited,path_len+1,first_time_flag);
     visited[start.r][start.c]=NOT_VISITED;//undo
 }
 //bottom
 if(start.r+1<TOT_ROWS && visited[start.r+1][start.c]==NOT_VISITED&&
    (maze[start.r+1][start.c]=='G'))
 {
     visited[start.r][start.c]=VISITED;//do
     tempStart.r=start.r+1;
     tempStart.c=start.c;
     find_path_grass(maze,tempStart,des,visited,path_len+1,first_time_flag);
     visited[start.r][start.c]=NOT_VISITED;//undo
 }
 //left
 if(start.c-1>=1 && visited[start.r][start.c-1]==NOT_VISITED&&
    (maze[start.r][start.c-1]=='G'))
 {
     visited[start.r][start.c]=VISITED;//do
     tempStart.r=start.r;
     tempStart.c=start.c-1;
     find_path_grass(maze,tempStart,des,visited,path_len+1,first_time_flag);
     visited[start.r][start.c]=NOT_VISITED;//undo
 }
 return min_path;
}

int find_path_ani(char maze[TOT_ROWS][TOT_COLS],POS start , POS des ,int visited[TOT_ROWS][TOT_COLS],int path_len,int first_time_flag)
{
 static int min_path=INT_MAX;
 POS tempStart;
 if(first_time_flag==0)
 {
  min_path=INT_MAX;
  first_time_flag=1;
 }
 //base condition
 if(start.r==des.r && start.c==des.c)
 {
     if(path_len < min_path) //finding minimum out of all paths
        min_path=path_len;
     return min_path;
 }
 //top
 if(start.r-1>=1 && visited[start.r-1][start.c]==NOT_VISITED&&
    (maze[start.r-1][start.c]=='G'||maze[start.r-1][start.c]=='M'))
 {
     visited[start.r][start.c]=VISITED;//do
     tempStart.r=start.r-1;
     tempStart.c=start.c;
     find_path_ani(maze,tempStart,des,visited,path_len+1,first_time_flag);
     visited[start.r][start.c]=NOT_VISITED;//undo
 }
 //right
 if(start.c+1<TOT_COLS && visited[start.r][start.c+1]==NOT_VISITED&&
    (maze[start.r][start.c+1]=='G'||maze[start.r][start.c+1]=='M'))
 {
     visited[start.r][start.c]=VISITED;//do
     tempStart.r=start.r;
     tempStart.c=start.c+1;
     find_path_ani(maze,tempStart,des,visited,path_len+1,first_time_flag);
     visited[start.r][start.c]=NOT_VISITED;//undo
 }
 //bottom
 if(start.r+1<TOT_ROWS && visited[start.r+1][start.c]==NOT_VISITED&&
    (maze[start.r+1][start.c]=='G'||maze[start.r+1][start.c]=='M'))
 {
     visited[start.r][start.c]=VISITED;//do
     tempStart.r=start.r+1;
     tempStart.c=start.c;
     find_path_ani(maze,tempStart,des,visited,path_len+1,first_time_flag);
     visited[start.r][start.c]=NOT_VISITED;//undo
 }
 //left
 if(start.c-1>=1 && visited[start.r][start.c-1]==NOT_VISITED&&
    (maze[start.r][start.c-1]=='G'||maze[start.r][start.c-1]=='M'))
 {
     visited[start.r][start.c]=VISITED;//do
     tempStart.r=start.r;
     tempStart.c=start.c-1;
     find_path_ani(maze,tempStart,des,visited,path_len+1,first_time_flag);
     visited[start.r][start.c]=NOT_VISITED;//undo
 }
 return min_path;
}


void visitedFill(int visited[TOT_ROWS][TOT_COLS])
{
    int row,col;
    for(row= 1 ;row<TOT_ROWS;row++)
        for(col=1;col<TOT_COLS;col++)
          visited[row][col]=NOT_VISITED;
}
/*

int park[ROWS][COLS] = {
{G,G,W,G,G,M,G,G,G,G},
{G,G,G,G,G,W,G,G,G,G},
{G,M,G,G,G,W,G,G,G,G},
{G,M,G,G,G,M,M,G,G,G},
{G,G,M,G,M,G,G,G,G,G},
{G,M,G,G,G,M,G,G,G,G},
{W,G,G,G,G,G,G,M,G,G},
{G,W,W,G,G,M,G,G,G,G},
{G,G,G,W,G,G,G,G,G,G},
{G,G,G,W,G,G,G,G,G,G}
};
*/
