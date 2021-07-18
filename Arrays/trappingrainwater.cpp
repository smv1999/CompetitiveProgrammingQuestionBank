// Given an array of numbers which are heights to the container, we need to find upto what maximum value water can be filled in this vessel
// of different heights.
// Time complexity - O(n)
//Space complexity - O(1)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,8,6,2,5,4,8,3,7};
    int l=0,n=sizeof(arr)/sizeof(int),r=n-1;
    int max_area=0,h,a,b;

    while(l<r){
        h=min(arr[l],arr[r]);
        b=r-l;
        a=h*b;
        max_area=max(a,max_area);
        if(arr[l]<=arr[r]){
            l++;
        }
        else{
            r--;
        }
    }
    cout<<"Maximum water that can be trapped is : "<<max_area;
    return 0;

}