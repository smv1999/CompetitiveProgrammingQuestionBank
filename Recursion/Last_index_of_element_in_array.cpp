/*Program to find first index of a number in array*/
#include <iostream>
using namespace std;
int lastIndex(int arr[],int n,int x){
  if(n==0){
    return -1; // if size of array is 0 then we return -1
  }
  int ans=lastIndex(arr+1,n-1,x);//recursion call to the next element of array.
  if(ans==-1){ //if we cannot find the element in the remaining part of array 
  if(arr[0]==x){//We check for 1st element.
    return 0;
  }
  else{
    return -1;//else we return -1
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
