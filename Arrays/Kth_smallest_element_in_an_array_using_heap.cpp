/**************************************************************************
Given an array arr[] and a number K where K is smaller than size of array, 
the task is to find the Kth smallest element in the given array. 
Given all Array elements are distinct.

For Example: arr[] = {7, 8, 1, 4, 9, 3}
             k = 3 ------> 3rd smallest element in the array
        ANS: 4

This can be solved using heap and priority queue.
***************************************************************************/

SOLUTION (in C++):

#include<bits/stdc++.h>

using namespace std;

int main()
{
   int n, k;
   cin>>n>>k;
   cout<<"Enter the array elements"<<endl;
   int arr[n];
   priority_queue<int> maxh; 
   //A priority queue keeps the elements in the order of their priority, i.e., 
   //elements having greater values will be at the top of the queue and elements having smaller values will be kept at the bottom of the queue.
   //The element popped out of this queue is the element with the maximum value.

   for(int i = 0;i<n;i++){
       maxh.push(arr[i]);
       if(maxh.size() > k){                       
          maxh.pop();
       }
   }
   
   cout<<"The "<<k<<"th smallest element is "<<maxh.top();
   return 0;
}