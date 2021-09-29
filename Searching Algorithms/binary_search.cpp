/*Program for Binary Search */
/*Binary search is another searching algorithm which is more effective than the linear Search. Searching algorithms are used to search a desired element in an array.Binary Search does less number of comparisons than linear Search,so it is an effective algorithm.Binary Search works only on sorted array. It follows divide and conquer approach.*/

/*algorithm
The array should be sorted.
We take 3 variables start,mid and end. Start variables has the index of 0th element end variable has index of last element and mid points to middle element.
We run a loop until start<=end.
We check if our desired element is equal to mid element.
If yes then return mid.
If desired element is greater than the mid element then we search in the right array.
If desired element is less than the mid element then we search in the left array.
Else return -1.*/
#include <iostream>
using namespace std;
int binary_search(int a[],int n,int key){
  int s=0;
  int e=n-1;
  //start should not cross end 
  
  while(s<=e){
    int mid=(s+e)/2;
    if(a[mid]==key){
      return mid;
    }
    // search in left of Array 
    else if(a[mid]>key){
      e=mid-1;
      
    }
    //search in right of Array 
    else{
      s=mid+1;
    }
    
    
  }
  return -1;
}
int main() {
  int n;
  cout<<"Size of Array "<<endl;
  cin>>n;
  int a[1000];
  cout<<"Enter Array Elements: "<<endl;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int key;
  cin>>key;
  cout<<binary_search(a,n,key);
  
}
/*Examples
For example let the array be [4,5,8,9,11]
We have to search 9 in the array.
Here, start =0,end=4 and mid=(start+end)/2,mid=2
a[mid]=8 which is not equal to 9
a[mid]<9 hence, start=mid+1
start=3,end=4,mid=(3+4)/2=3
a[mid]=9 which is equal to 9 so we return 3.
*/