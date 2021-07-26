/* PROBLEM STATEMENT 
In a season, each player has three statistics: runs, wickets, and catches. Given the season stats of two players A and B, denoted by R, W, and C respectively, 
the person who is better than the other in the most statistics is regarded as the better overall player. Tell who is better amongst A and B. It is known that in each statistic, 
the players have different values.
Input Format
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains two lines of input.
The first line contains three integers R1, W1, C1, the stats for player A.
The second line contains three integers R2, W2, C2, the stats for player B.
Output Format
For each test case, output in a single line "A" (without quotes) if player A is better than player B and "B" (without quotes) otherwise.
Constraints
1≤T≤1000
0≤R1,R2≤500
0≤W1,W2≤20
0≤C1,C2≤20
R1≠R2
W1≠W2
C1≠C2
Sample Input 1 
3
0 1 2
2 3 4
10 10 10
8 8 8
10 0 10
0 10 0
Sample Output 1 
B
A
A
Explanation
Test Case 1: Player B is better than A in all 3 fields.
Test Case 2: Player A is better than B in all 3 fields.
Test Case 3: Player A is better than B in runs scored and number of catches. */


#include <stdio.h>

int main(void) {
int i=0;	
int tc;
  // tc is to take input the number of test cases
scanf("%d",&tc);
int a[tc];
int t=tc;
int r1,w1,c1,r2,w2,c2;
while(tc--)
{
    scanf("%d %d %d",&r1,&w1,&c1); //stores respective inputs for player A
    scanf("%d %d %d",&r2,&w2,&c2); //stores respective inputs for player B
    
    if(((w1>w2)&&(r1>r2)&&(c1>c2))||((w1>w2)&&(c1>c2))||((c1>c2)&&(r1>r2))||((r1>r2)&&(w1>w2)))
    {
        a[i]=1; //stores 1 in the array for results favouring player A
    }
    else
    {
        a[i]=2; //stores 1 in the array for results favouring player B
    }
    i++;
}

for(int j=0;j<t;j++)
{
    if(a[j]==1)
    {
        printf("A \n");
        
    }
    else
    {
        printf("B \n");
    }
    
}
	return 0;
}
