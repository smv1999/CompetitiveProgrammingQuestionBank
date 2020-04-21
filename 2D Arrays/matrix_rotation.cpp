/*
Rotation of matrix through a specified angle

input
2
1   2
3   4
90

output
3   1
4   2

*/
#include<iostream>
using namespace std;
int matrix[100][100],temp[100][100];
int n; 
void rotate(int angle)
{
    int i,j;
    int total = angle/90;
    total = total % 4;
    while(total--)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                temp[j][n-i-1]=matrix[i][j];
            }
        }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                matrix[i][j]=temp[i][j];
    }
}
int main(int argc, char const *argv[])
{
    int i,j,angle,totalrot=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
    cin>>angle;
    rotate(angle);
    totalrot = totalrot + angle;
    // rotate(360 - (totalrot%360)); // to convert the rotated matrix to the original one
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
