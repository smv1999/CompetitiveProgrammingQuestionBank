#include<stdio.h>
void sudokuSolver(int data[9][9]);
void sudokuPrinter(int data[9][9]);
int isSafe(int data[9][9],int c_row,int c_col ,int fillValue);
void sudokuSolverUtility(int data[9][9],int c_row,int c_col,int preFill[9][9]);
#define SAFE 1
#define UNSAFE 0
int main()
{
  int data[9][9]={
{0,8,0,3,0,7,0,0,0},
{0,4,0,0,2,0,0,0,0},
{0,0,3,6,0,0,0,2,4},
{7,5,0,0,0,0,4,0,0},
{4,6,0,5,7,3,0,8,2},
{0,0,2,0,0,0,0,5,7},
{6,7,0,0,0,4,9,0,0},
{0,0,0,0,8,0,0,7,0},
{0,0,0,7,0,9,0,4,0}
  };

sudokuSolver(data);
sudokuPrinter(data);
  return 0;
}
void sudokuSolver(int data[9][9])
{
    int preFill[9][9];
    int row,col;
    for(row=0 ;row<9; row++)
        for(col=0 ;col< 9 ; col++)
                preFill[row][col]=(data[row][col]>0)?data[row][col]:-1;
    sudokuSolverUtility(data,0,0,preFill);
}
void sudokuSolverUtility(int data[9][9],int c_row,int c_col,int preFill[9][9])
{
    int fillVal,safe_row,safe_col;
    static int sol_flag=0;
    if(c_row==9)
    {
        // sudokuPrinter(data);
        sol_flag=1;
         return;
    }
    if(preFill[c_row][c_col]>0)
    {
        safe_row=c_row;
        safe_col=c_col;
        if(safe_col+1==9)
         {
             safe_row++;
             safe_col=0;
         }
         else
            safe_col++;
        sudokuSolverUtility(data,safe_row,safe_col,preFill);
    }
    else//make a choice
    {
        for(fillVal=1;fillVal<=9;fillVal++)
        {
            if(isSafe(data,c_row,c_col,fillVal)==SAFE)
            {
                  data[c_row][c_col]=fillVal;//do
                   safe_row=c_row;
                    safe_col=c_col;
                    if(safe_col+1==9)
                     {
                         safe_row++;
                         safe_col=0;
                     }
                     else
                        safe_col++;
                    sudokuSolverUtility(data,safe_row,safe_col,preFill);
                   if(sol_flag==0)//if noo solution found
                    data[c_row][c_col]=-1;//undo
              }
        }
    }
}
int isSafe(int data[9][9],int check_row,int check_col ,int fillValue)
{
  int row,col,st_row,st_col;
  //row safety
  for(col=0;col<9;col++)
    if(data[check_row][col]==fillValue)
        return UNSAFE;
  //col safety
  for(row=0;row<9;row++)
    if(data[row][check_col]==fillValue)
        return UNSAFE;
  //sub matrix safety
  st_row = (check_row/3)*3;//4/3=1
  st_col = (check_col/3)*3;//4/3=1
  for(row= st_row;row<st_row+3;row++)
    for(col=st_col;col<st_col+3;col++)
        if(data[row][col]==fillValue)
            return UNSAFE;
  return SAFE;
}
void sudokuPrinter(int data[9][9])
{
    int row,col;
    for(row=0,printf("\n") ;row<9; row++,printf("\n"))
    {
        for(col=0 ;col< 9 ; col++)
        {
          printf("%3d ",data[row][col])  ;
        }
    }
}




/*
  int data[9][9]={
{6,0,0,0,0,8,9,4,0},
{9,0,0,0,0,6,1,0,0},
{0,7,0,0,4,0,0,0,0},
{2,0,0,6,1,0,0,0,0},
{0,0,0,0,0,0,2,0,0},
{0,8,9,0,0,2,0,0,0},
{0,0,0,0,6,0,0,0,5},
{0,0,0,0,0,0,0,3,0},
{8,0,0,0,0,1,6,0,0}
};

*/
/*
 int data[9][9]={
{2,0,0,0,0,0,5,0,0},
{0,0,6,0,0,4,0,0,0},
{0,0,3,8,0,0,0,9,7},
{6,7,0,0,3,0,0,0,0},
{0,1,0,0,9,0,0,5,0},
{0,0,0,0,4,0,0,7,1},
{4,9,0,0,0,2,7,0,0},
{0,0,0,5,0,0,8,0,0},
{0,0,5,0,0,0,0,0,6},
};
*/
