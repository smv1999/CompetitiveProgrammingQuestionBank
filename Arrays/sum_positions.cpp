/* Title : User need to enter the elements he wants to enter .
          The possible pairs of positions will be found whose sum
           will equal to the query number accepted .

           ex : Elements : 2 3 4 5
                Query element : 8
                Output : Addition of elements present at position 2 and 4 = 8.

*/
#include<iostream>
#include<cstdlib>
#include<conio.h>
int fact (int n);
using namespace std;

int main()
{
  int i , j ,n,th;
  int opt , count=0;


do
  {
  cout<<"\n Enter the total number of elements :   \n"<<endl;  // Enter more than 1.
  cin>>n;
  if(n<=1)
  {
    cout<<"\n Invalid Input .\n Try again later ! "<<endl;
    exit(0);
  }
  int fac=fact(n);
  int a[n];
  cout<<"\n Enter the "<<n<<" elements : \n"<<endl;
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }

 do
  {
  cout<<"\n Enter the query you wish to choose  : ";
  cin>>th;

  cout<<"\n";
  count=0;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
       if(a[i]+a[j]==th)
       {
         cout<<" Found : "<<" Addition of elements at positions "<<i+1<<" and "<<j+1<<endl;
       }

       else
       { count++ ; }
    }
  }

if(count==fac)
{
  cout<< "\n  Oops ! \n  Not found .\n"<<endl;
}

  cout<<"\n Do you wish to check for another query with same data ? \n 1.Yes 2.Press any to do not\n"<<endl;    // Press 1 to contiune only .
   cin>>opt;                                                                                      // It will be done on the same data sets .
 }while(opt==1);

   cout<<"\n Do you wish to continue ? \n Press 1 to continue or any to stop . \n"<<endl;   // Press 1 to continuw\e .
    cin>>opt;
  }while(opt==1);                                              // You will need to enter the data of arrays and query again .
}

int fact(int n)
{
  int i=n-1, sum=0;
  while(i>=1)
  {
    sum=sum+i ;
    i--;
  }
  return sum;
}

/*
Enter the total number of elements :

7

Enter the 7 elements :

106
-53
0
53
21
4
23

Enter the query you wish to choose  : 53

Found :  Addition of positions 1 and 2
Found :  Addition of positions 3 and 4

Do you wish to check for another query with same data ?
1.Yes 2.Press any to do not

1

Enter the query you wish to choose  : 4

Found :  Addition of positions 3 and 6

Do you wish to check for another query with same data ?
1.Yes 2.Press any to do not

2

Do you wish to continue ?

1


Enter the total number of elements :
3

Enter the 3 elements :
12
22
0

Enter the query you wish to choose  : 23


 Oops !
 Not found .


Do you wish to check for another query with same data ?
1.Yes 2.Press any to do not

2

Do you wish to continue ?

2
*/
