/*WAP TO PRINT THE PATTERN AS GIVEN BELOW.
INPUT: 4
  1  2  3  4  3  2  1
  5  6  7     7  6  5
  8  9           9  8
 10                10
  8  9           9  8
  5  6  7     7  6  5
  1  2  3  4  3  2  1
  */
#include<stdio.h>
#include<conio.h>
int main()
{
	//clrscr();
	int i,j,n,k=0,c;
	printf("ENTER THE VALUE OF N:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i+1;j++)
		printf("%3d",++k);
		for(j=i-1;j>=1;j--)
		printf("%3c",' ');
		for(j=i-1;j>1;j--)
		printf("%3c",' ');
		c=k;
		if(i==1)
		c=c-1;
		for(j=1;j<=n-i+1&&c!=0;j++)
		printf("%3d",c--);
		printf("\n");
	}//end of upper block
	int t=2;
		for(i=n-1;i>=1;i--)
	{
		k=k-t;
		t++;
		for(j=1;j<=n-i+1;j++)
		printf("%3d",k+j-1);
		for(j=i-1;j>=1;j--)
		printf("%3c",' ');
		for(j=i-1;j>1;j--)
		printf("%3c",' ');
		c=k+t-2;
		if(i==1)
		c=c-1;
		for(j=1;j<=n-i+1&&c!=0;j++)
		printf("%3d",c--);
		printf("\n");
	}//end of lower block

	getch();
	return 0;
}
/*
ENTER THE VALUE OF N:
7
  1  2  3  4  5  6  7  6  5  4  3  2  1
  8  9 10 11 12 13    13 12 11 10  9  8
 14 15 16 17 18          18 17 16 15 14
 19 20 21 22                22 21 20 19
 23 24 25                      25 24 23
 26 27                            27 26
 28                                  28
 26 27                            27 26
 23 24 25                      25 24 23
 19 20 21 22                22 21 20 19
 14 15 16 17 18          18 17 16 15 14
  8  9 10 11 12 13    13 12 11 10  9  8
  1  2  3  4  5  6  7  6  5  4  3  2  1

--------------------------------
*/
