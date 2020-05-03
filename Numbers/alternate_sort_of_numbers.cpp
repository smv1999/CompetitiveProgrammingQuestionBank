/*
Alternate sorting of numbers

Given an array of N integers, rearrange the array in such a way that the first element is
first maximum, second element is first minimum, third element is second maximum, fourth
element is second minimum and so on.

Input
1 2 3 4 5 6 7

Output
 7 1 6 2 5 3 4
*/
#include<iostream>
using namespace std;
void bubbleSort(int a[], int n)
{ int temp;
  for(int i=0;i<n-1;i++)
  {
      for(int j=0;j<n-i-1;j++)
      {
          if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
      }
  }
}
void revBubbleSort(int a[], int n)
{
    int temp;
  for(int i=0;i<n-1;i++)
  {
      for(int j=0;j<n-i-1;j++)
      {
          if(a[j]<a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
      }
  }
}
int main(int argc, char const *argv[])
{
    int n;
    int a[100],k=0,b[100],l=0;
   do {
       cin >> n;
       a[k++] = n; 
      }while (cin.get()!='\n');
    for(int i=0;i<k;i++)
        b[l++] = a[i];
    bubbleSort(a,k);
    revBubbleSort(b,k);
    int p=0,q=0;
    for(int i=0;i<k;i++)        
    {
        if(i%2==0)
        {
            cout<<b[p++]<<" ";
        }
        else
        {
            cout<<a[q++]<<" ";
        }
    }
    return 0;
}
