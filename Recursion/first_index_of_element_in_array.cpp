/*Program to find first index of a number in array*/
#include <iostream>
using namespace std;
int firstIndex(int arr[],int n,int x){
  if(n==0){ //if size of array is 0 
    return -1;
  }
  if(arr[0]==x){ //if the element is found on first index 
    return 0;
  }
  int ans=firstIndex(arr+1,n-1,x);//recursion
  if(ans==-1){
    return -1;
  }
  else{
    return ans+1;
  }
}

int main() {
  int n,x,a[200];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cin>>x;
  cout<<firstIndex(a,n,x);
  
}
/*Example
Input:
5
5 5 6 7 9
5
Output:
0 
*/
