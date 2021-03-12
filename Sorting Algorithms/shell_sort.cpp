#include<bits/stdc++.h>
using namespace std;

void display(int *array,int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}

void swapping(int &a, int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void shellSort(int *arr,int n){
    int gap,j,k;
    for(gap=n/2;gap>0;gap=gap/2){
        for(j=gap;j<n;j++){
            for(k=j-gap;k>=0;k-=gap){
                if(arr[k+gap]>=arr[k])
                   break;
                else 
                  swapping(arr[k+gap],arr[k]);
            }
        }

    }
    
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
    cout<<"Array before Sorting: ";
    display(arr,n);
    shellSort(arr,n);
    cout<<"Array after Sorting: ";
    display(arr,n);

  
}
