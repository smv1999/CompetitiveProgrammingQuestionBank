/* Number of subarrays of an array with n elements = nC2 + n = n*(n+1) / 2.*/

#include "bits/stdc++.h"


using namespace std;

int main(){
	
	int n;
	cin>>n;
	
	
	int arr[n];
	for(int i =0;i<n;i++){
		cin>> arr[i];
	}
	
	int curr =0; //initialize curr=0
	
	for(int i=0; i<n;i++){
		curr=0;
		for(int j=i;j<n;j++){
			curr +=arr[j];
			cout<< curr<<endl;
		}
	}
	
}

/* 
INPUT :
5
1 2 0 7 2

OUTPUT :
1
3
3
10
12
2
2
9
11
0
7
9
7
9
2

