/*Program to find first index of a number in array*/
#include <iostream>
using namespace std;
int lastIndex(int arr[],int n,int x){
  if(n==0){
    return -1;
  }
  int ans=lastIndex(arr+1,n-1,x);
  if(ans==-1){
  if(arr[0]==x){
    return 0;
  }
  else{
    return -1;
  }
  }
  

return ans+1;
  
}

int main() {
  int n,x,a[200];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cin>>x;
  cout<<lastIndex(a,n,x);
  
}
/*Example
Input:
5
5 5 6 7 9
5
Output:
0 
*/