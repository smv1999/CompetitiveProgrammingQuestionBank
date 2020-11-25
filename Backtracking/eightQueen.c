/*
The eight queens problem is the problem of placing eight queens on an 8×8 chessboard such that none of them attack one another 
(no two are in the same row, column, or diagonal). More generally, the n queens problem places n queens on an n×n chessboard.
*/
#include <stdio.h>
void solutionFinder(int tot_queens);
void NQueenSolver(int queenPositions[], int tot_queens, int queenNum);
int isSafe(int queenPositions[], int tot_queens, int choice, int queenNum);
#define SAFE 1
#define UNSAFE 0
void printBoard(int queenPositions[], int tot_queens);
int main()
{
    solutionFinder(8);
    return 0;
}
void solutionFinder(int tot_queens)
{
    int queenPositions[tot_queens];
    int ind;
    for (ind = 0; ind < tot_queens; ind++)
        queenPositions[ind] = -1; //no queens placed at start
    NQueenSolver(queenPositions, tot_queens, 0);
}
void NQueenSolver(int queenPositions[], int tot_queens, int queenNum)
{
    //choices are 0 to tot_queens-1
    int choice;
    if (tot_queens == queenNum) //
    {
        printBoard(queenPositions, tot_queens);
        getch();
        return;
    }
    for (choice = 0; choice < tot_queens; choice++)
    {
        if (isSafe(queenPositions, tot_queens, choice, queenNum) == SAFE)
        {
            //do certain things
            queenPositions[queenNum] = choice;
            NQueenSolver(queenPositions, tot_queens, queenNum + 1);
            //undo
            queenPositions[queenNum] = -1;
        }
    }
}
int isSafe(int queenPositions[], int tot_queens, int choice, int queenNum)
{
    int row, col;
    //left top
    for (row = queenNum - 1, col = choice - 1; row >= 0 && col >= 0; row--, col--)
        if (queenPositions[row] == col)
            return UNSAFE;
    //top
    for (row = queenNum - 1, col = choice; row >= 0; row--)
        if (queenPositions[row] == col)
            return UNSAFE;
    //right top
    for (row = queenNum - 1, col = choice + 1; row >= 0 && col < tot_queens; row--, col++)
        if (queenPositions[row] == col)
            return UNSAFE;
    return SAFE;
}
void printBoard(int queenPositions[], int tot_queens)
{
    int row, col;
    for (printf("\n"), row = 0; row < tot_queens; row++, printf("\n"))
    {
        for (col = 0; col < tot_queens; col++)
        {
            if (queenPositions[row] == col)
                printf(" Q ");
            else
                printf(" - ");
        }
    }
}
