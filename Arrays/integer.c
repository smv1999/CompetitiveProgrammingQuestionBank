/* Title : Enter the data elments before that mention the their total count . .
            After entering the data you first missed positive integer missed will
            be displayed .
            Code is done in C language .
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n ,j=0, i,k=1 , val;
  int opt=1;
  printf("\n Enter the total number of elements : \n");
  scanf("%d",&n);
  if(n<=0)
  {
    printf("\n Invalid Input , Try again later !!  \n");
    exit(0);
  }
  int a[n];
  printf("\n Enter the elements : \n");
  for(i=0;i<n;i++)
    {  scanf("%d",&a[i]); }

    for(i=0;i<n;i++)
{    for(j=0;j<n-1;j++)
     if(a[j]>a[j+1])
       { val=a[j];
         a[j]=a[j+1];
         a[j+1]=val; }
}
    printf("\n Sorted array : \n");
    for(i=0;i<n;i++)
    {
      printf(" %d  ", a[i]);
    }
    printf("\n \n");
    printf("\n Postive element missed from the data  is ");
if(a[n-1]<=0)
{
   printf("\n1\n");


}
else {

    for(i=0;i<n;i++)
    {
      if(a[i]>0)
      {
        for(j=0+i, k=1;j<=n && k<=n+1;k++,j++)
         {
             if(a[j]==k)
             {
               continue ;
             }
             else
             {

                 printf(" %d " ,k);
                  exit(0);

                  }



          }
       }
     }
  }

}


/*

Enter the total number of elements :
7

Enter the elements :
0
-1
1
-2
-3
-4
-5

Sorted array :
-5   -4   -3   -2   -1   0   1


Postive element missed from the data  is  2

*/
