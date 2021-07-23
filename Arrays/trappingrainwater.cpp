// Given an array of numbers which are heights to the container, we need to find upto what maximum value water can be filled in this vessel
// of different heights.
// Time complexity - O(n)
//Space complexity - O(1)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,8,6,2,5,4,8,3,7}; //array of diff heights
    int l=0,n=sizeof(arr)/sizeof(int),r=n-1;
    int max_area=0,h,a,b;
    //2 pointers algorithm

    while(l<r){ 
        h=min(arr[l],arr[r]); //choosing the minimum of both heights -left and right side
        b=r-l; //base = right height index - left 
        a=h*b;
        max_area=max(a,max_area); //idea to maximize the area to trap more water
        if(arr[l]<=arr[r]){
            l++; //if right ride height is greater move left pointer to choose max of heights
        }
        else{
            r--; //else move right pointer to choose next max height
        }
    }
    cout<<"Maximum water that can be trapped is : "<<max_area;
    return 0;

}
