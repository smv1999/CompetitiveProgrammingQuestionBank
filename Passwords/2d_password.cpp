/*
Generating Passwords using 2-D Matrix

26  28  5   18*  27  32  50
13  42  32  11   5   40  27
16  34  23* 49  44*  17  36
48  10  4   20  13   43  36
1   10*  19  2  23  22*  20
49  35  15  41  7   29   34
13*  23  45  50  31  8   2*

The elements mentioned with * are the ones that need to be considered for password generation.
The numbers are changed to alphabets like 1 mapped to a, 2 mapped to b, and so on till 26 maps to z.
We need to generate the final password.
*/
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int row,col;
    string alphabets = "_abcdefghijklmnopqrstuvwxyz";
    cin>>row>>col;
    int arr[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }
   
    
    int c=0;
    int r = row-1;
    int count=0;
    int generators[100];
    while (c<=row/2)
    {
        generators[count++] = arr[r][c];
        c+=1;
        r-=2;
    }
    r = 2;
    while (c<row)
    {
        generators[count++] = arr[r][c];
        c+=1;
        r+=2;
    }
    int gen;
    for(int i=0;i<count;i++)
    {
        gen = generators[i]%26;
        if(gen==0)
            gen = 26;
        cout<<alphabets[gen];
    }
    
    
    return 0;
}
