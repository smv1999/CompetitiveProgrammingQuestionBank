/* Title : User will enter the unsorted array .
      You will need to sort it and has to
      find out the first missing positive integer from the sorted array .
*/
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{
  int n ,j=0, i,k=1 , val;
  cout<<" Enter the total number of elements "<<endl;
  cin>>n;
  int a[n];
  cout<<" Enter the elements : \n"<<endl;
  for(i=0;i<n;i++)
    {  cin>>a[i]; }

    for(i=0;i<n;i++)
{    for(j=0;j<n-1;j++)
     if(a[j]>a[j+1])
       { val=a[j];
         a[j]=a[j+1];
         a[j+1]=val; }
}
    cout<<" Sorted array : \n"<<endl;
    for(i=0;i<n;i++)
    {
      cout<<a[i]<<" ";
    }
    cout<<" \n"<<endl;
    cout<<" Missing element : ";
if(a[n-1]<=0)
{
   cout<<"1";

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

                 cout<<k;
                  exit(0);
             }  }
       }  }
  }}






/*
Enter the total number of elements
5
Enter the elements :

12
-43
-5
0
2
Sorted array :

-43 -5 0 2 12

Missing element : 1
*/
