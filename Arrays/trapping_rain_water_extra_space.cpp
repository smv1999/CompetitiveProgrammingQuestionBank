// Trapping Rain Water
//Approach 2
// O(n) O(2n)

//i/p: 3 0 1 2 5
//o/p: 6

//Use 2 extra arrays

#include<bits/stdc++.h>
using namespace std;
int getwater(int arr[],int n)
{
   int res=0;
   int lmax[n],rmax[n];

   	//left max
   lmax[0]=arr[0];
   for(int i=1;i<n;i++)
        lmax[i]=max(arr[i],lmax[i-1]);

			//starts from start to end
			//1st element as it is other max will place in lmax
			//Array is 5 0 6 2 3
//					   |/\/\/\/\
			 //lmax is 5 5 6 6 6

	//right max
   	rmax[n-1]=arr[n-1];
   for(int i=n-2;i>=0;i--)
    rmax[i]=max(arr[0],rmax[i+1]);

	//starts from end to start
	//last element as it is other max will place in rmax
		//Array is 5 0 6 2 3
//			       /\/\/\/\|
   		 //rmax is 6 6 6 3 3

   //here we get result
   for(int i=1;i<n-1;i++)
    res+=(min(lmax[i],rmax[i])-arr[i]);

//    min(lmax,rmax)-arr[i]    min        arr[i]
//		5 5 6 6 6			5 5 6 3 3 - 5 0 6 2 3 = 0+5+0+1+0=6
//		6 6 6 3 3


   return res;
}
int main()
{
	int n;
    cout<<"Enter the number of elements in the array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in  the array\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Total trapped water is "<<getwater(arr,n);
    return 0;
}
