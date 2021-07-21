/*  Title : To find whether the given series format is following AP or GP .
    Description : User need to provide the terms present and also need to mention
                  how many number of terms user is providing .
                  You can also find the ' Mean' , ' Sum ' and the nth the term if
                  it is following any one of the of progression .
                  Need to enter atleast three minimun number .
                *****  For G.P here the common difference should be greater then 1 .******

*/
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std ;

int main()
{   int opt  ;
    float s;
    cout<<"  **** Welcome *** "<<endl;
    cout<<" Arithematic Progression : Common difference between two adjacent terms is constant ."<<endl;
    cout<<" Geometric Progression   : Common ratio between two adjacent terms is constant .\n( For G.P here we can perform the operations for common difference greater than 1 only.) \n "<<endl;
     do
   {
   int i=0,j=0 ,n ;
   float sum=0, mean ,nth ,d ,k, s=1;

   float first_term, AP ,GP;
   int count=1 , co=0;
   cout<<"\n Enter the number elements of the given series you wish to enter : \n **** You need to enter atleast 3 terms **** \n"<<endl; /* User need tor provide minimum three terms . Otherwise system will exit */
   cin>>n;
   float a[n];
   cout<<"\n Enter the elements : \n"<<endl;
   for(i=0;i<n;i++)
   { cin>>a[i] ; }

    AP=a[1]-a[0];
    GP=a[1]/a[0];

   first_term=a[0];
   // To define the operation of A.P and G,P:

        for(i=0;i<n-1;i++)
      {
  // a. AP operations :
        d=a[i+2]-a[i+1];

        if (AP==d)
      { count++ ;


      if (count==n-1)
   {
      do {
        cout<<"\n Given series is in Arithematic Progression " <<endl;
        cout<<"\n 1.Mean \n 2.Sum  \n 3.To find the nth element of the given series \n 4.Exit : "<<endl;
        cin>>opt;


        switch(opt)
        {
          case 1 : cout<<"\n Mean of the given A.P series : "<<endl;
                   i=0 , sum=0;
                   while(i<n)
                   {
                      sum=sum+a[i];
                      i++;
                    }
                    mean=sum/n;
                    cout<<" Arithematic Mean : "<<mean<<endl;
                   break ;
          case 2 :
                   cout<<"\n Sum of the first "<< n<< "  AP elements entered : "<<endl;
                   sum=0;
                   sum=(n*((2*first_term) + (n - 1)*(AP)))/2;
                   cout<<sum<<endl;
                   break ;
          case 3 : cout<<" Enter the nth element : "<<endl;
                   cin>>nth;
                   nth= (first_term + (nth - 1)*AP );
                   cout<<" Nth element of the given AP : "<<nth<<endl;
                   break ;
          case 4 : exit(0);
                   break ;
          default : cout<<"\n Invalid option , Try again later !"<<endl;
                   break;
          }
      cout<<"\n Wish to continue the AP operations on the given series ?\n1.Yes 2.No \n"<<endl;   /* 1. To continue or press any to stop */
      cin>>opt;
   }while(opt==1);
  }
 }
}
  //2.GP Operations :
   for(i=0;i<n-2;i++)
  {
// a. AP operations :
    d=a[i+2]/a[i+1];
    if (GP==d)
  {  co++ ;

  if(co==n-2)
{
 do
  {
  cout<<" \n Given series is in Geometric Progression " <<endl;
  cout<<"\n 1.Mean \n 2.Sum  \n 3.To find the nth element of the given series \n 4.Exit : "<<endl;
  cin>>opt;


  switch(opt)
  {
    case 1 :  cout<<"\n Enter the number of elements to find the geometric mean : \n"<<endl;
              float t;
              cin>>t;
              cout<<"\n the first "<<t<<"  given G.P series elements have the "<<endl;
              i=0;
              while(i<n)
              {
                s=s*a[i];
                i++;  }
              mean=pow(s, (1/t));
              cout<<" Geometrical Mean : "<<mean<<endl;
              break ;
    case 2 :  cout<<"Enter the number of elements to find the mean of them : "<<endl;
              int tt;
              cin>>tt;
              cout<<"\n Sum of the first "<<tt<<"GP elements  : "<<endl;
              sum=first_term*((pow(GP, tt))-1)/(GP-1);
              cout<<abs(sum)<<endl;
              cout<<" If the series belongs to infinity : "<<endl;
              cout<<" sum : "<<abs(first_term/(1 - GP))<<endl;
              break ;
    case 3 :  cout<<" Enter the nth element : "<<endl;
              cin>>nth;
              nth=first_term*pow(GP , nth-1);
              cout<<" Nth term of the given G.P : "<<nth<<endl;
              break ;
    case 4 :  exit(0);
              break ;
    default : cout<<"\n Invalid option , Try again later !"<<endl;
              break;
    }

      cout<<" \n Wish to continue the GP operations on the given series ?\n1.Yes 2.No \n"<<endl;   /* 1. To continue or press any to stop */
      cin>>opt;
     }while(opt==1);
    }
  }
}
  cout<<"\n Do you wish to continue further or not \n1.Yes 2.No \n"<<endl;    /* 1. To continue or press any to stop */
  cin>>opt;
} while(opt==1);

}


/*

**** Welcome ***
Arithematic Progression : Common difference between two adjacent terms is constant .
Geometric Progression   : Common ratio between two adjacent terms is constant .


Enter the number elements of the given series you wish to enter :
**** You need to enter atleast 3 terms ****

3
Enter the elements :
1
1.02
1.04

Given series is in Arithematic Progression

1.Mean
2.Sum
3.To find the nth element of the given series
4.Exit :
1

Mean of the given A.P series :
Arithematic Mean : 1.02
Wish to continue the AP operations on the given series ?
1.Yes 2.No

1

Given series is in Arithematic Progression

1.Mean
2.Sum
3.To find the nth element of the given series
4.Exit :
2

Sum of the first 3 AP elements entered :
3.06

Wish to continue the AP operations on the given series ?
1.Yes 2.No

1

Given series is in Arithematic Progression

1.Mean
2.Sum
3.To find the nth element of the given series
4.Exit :
3

Enter the nth element :
5

Nth element of the given AP : 1.08

Wish to continue the AP operations on the given series ?
1.Yes 2.No

2

Do you wish to continue further or not
1.Yes 2.No
1

Enter the number elements of the given series you wish to enter :
**** You need to enter atleast 3 terms ****

4

Enter the elements :
2
4
8
16

Given series is in Geometric Progression

1.Mean
2.Sum
3.To find the nth element of the given series
4.Exit :
1

Enter the number of elements to find the geometric mean :
4

the first 4given G.P series elements have the
Geometrical Mean : 5.65685

Wish to continue the GP operations on the given series ?
1.Yes 2.No

1
Given series is in Geometric Progression

1.Mean
2.Sum
3.To find the nth element of the given series
4.Exit :
2

Enter the number of elements to find the mean of them :
3

Sum of the first 3 GP elements  :
14

If the series belongs to infinity :
sum : 2

Wish to continue the GP operations on the given series ?
1.Yes 2.No

1
Given series is in Geometric Progression

1.Mean
2.Sum
3.To find the nth element of the given series
4.Exit :
3

Enter the nth element :
5

Nth term of the given G.P : 32
Wish to continue the GP operations on the given series ?
1.Yes 2.No

2
Do you wish to continue further or not
1.Yes 2.No
2

*/
