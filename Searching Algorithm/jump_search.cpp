#include<bits/stdc++.h>
using namespace std;
int JumpSearch(int arr[],int x,int n){
    int step = sqrt(n);
    int prev=0;

    while (arr[min(step,n)-1]<x)
    {
        prev = step;
        step+=sqrt(n);
        if(prev>=n)
          return -1;
    }

    while(arr[prev]<x){
        prev++;

        if(prev==min(step,n))
        return -1;
    }

    if(arr[prev]==x)
      return prev;

    return -1;
    
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: "<<"\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int r;
    cout<<"Enter element to search: ";
    cin>>r;
    int index = JumpSearch(arr,r,n);
    cout<<"Number "<<r<<" is at index "<<index;
  
}
