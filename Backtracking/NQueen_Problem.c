/* The N Queen is the problem of placing N chess queens on an 
N×N chessboard so that no two queens attack each other.

Language Used: C language

Output: The expected output is a binary matrix which has numbers 
        for the blocks where queens are placed. 
        
For example, following is the output matrix for above 4 queen solution.
OUTPUT FOR 4 Queens: { 2,  4,  1,  3}
              		 { 3,  1,  4,  2}
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

int place(int r,int c,int x[])//function gives resultant appropriate place for the queen 
{
    int i;
    for(i=1; i<r; i++)
    {
        if(x[i]==c||(abs(x[i]-c)==abs(i-r)))
            return 0;
    }
    return 1;
}

void NQueen(int r,int n,int x[]) //function for checking the places of the queen so that one queen would not attack other
{
    int c,i;
    for(c=1; c<=n; c++)
    {
        if(place(r,c,x))
        {
            x[r]=c;
            if(r==n)
            {
                printf("{");
                for(i=1; i<=n; i++) 
                    printf(" %d",x[i]);
                printf(" }\n");
            }
            else
                NQueen(r+1,n,x);
        }
    }
}
int main()
{
    int n,i,j;
    int x[50];
    printf("\nEnter the no. of Queens: ");
    scanf("%d",&n);
    printf("\nResultant Places of Queens: \n");
    NQueen(1,n,x);
}
