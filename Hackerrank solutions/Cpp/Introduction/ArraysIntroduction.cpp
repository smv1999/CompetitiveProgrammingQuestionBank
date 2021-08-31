#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int a[n], b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    } 
    for(int j=n-1;j>=0;j--){
        cout<<a[j]<<" ";
    }
    
    return 0;
}
