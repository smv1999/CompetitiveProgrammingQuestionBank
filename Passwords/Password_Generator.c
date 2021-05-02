#include <stdlib.h>
#include <stdio.h>
#include<time.h>
int main() 
{
	system("color f0");
  int i,password,len,b;
  srand((unsigned int)time(NULL));
   printf("\n\n\t\t\t Enter No. of Password you want !!!\n\n\t\t\t\t\t");
  scanf("%d",&b);
  printf("\n\n\n\t\tEnter Password Length and must be greater than \"5\"\n\n\t\t\t\t\t");
  scanf("%d",&len);
  printf("\n\n\t\t\t\t");
  if(len>=6)
  {
  	system("cls");
  	printf("\n\n\t\t\t\tPASSWORDS ARE GIVEN BELOW !!!\n\n\t\t\t\t");
  	while(b--)
  	{
     for(i=0;i<len;i++)
      {
      int k=rand()%200;
       if((k>=48&&k<=57)||(k>=65&&k<=90)||(k>=97&&k<=122)||(k>=35&&k<=37)||k==64)
       {
        printf("%c",k);
        }
        else
        {
         i--;
        }
      }
      printf("\n\n\t\t\t\t");
  }
}

  else
  {
   printf("\n\n\n\t\t\tLength should be greater than \"6\"\n");
  }
  system("pause");
}
