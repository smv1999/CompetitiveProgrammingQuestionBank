/*
Find the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

Input:
K = 3, N = 5
Arr[] = {3, 9, 12, 16, 20}
Output:
11
Explanation:
The array can be modified as
{6, 12, 9, 13, 17}. The difference between 
the largest and the smallest is 17-6 = 11.
*/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
	//sort the array first
        sort(arr, arr+n);

	//store the difference between first and last value.
        int ans = arr[n-1] - arr[0];
        
        for(int i = 0; i < n-1; i++) {
            if(arr[i+1] < k) {
                continue;
            }
	    	//currMin will have minimum value after update
            int currMin = min(arr[i+1]-k, arr[0]+k);
	        //currMax will have maximum value after update
            int currMax = max(arr[i]+k, arr[n-1]-k);
		//minimum value between previous answers and current difference will be saved in ans variable.
            ans = min(ans, currMax-currMin);
        }
        
        return ans;
    }
};

int main(){
	int n,k;
	
	//Accept length of the array
	cin>>n;
	//K is the number by which the values will be increased/decreased
	cin>>k;
	
	int arr[n];
	//loop to accept array values
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	//creating object of Solution class and saving the returned value in min_diff variable.
	Solution obj;
	int min_diff = obj.getMinDiff(arr,n,k);
	
	//print the final answer
	cout<<"The difference between the largest and smallest is: " << min_diff<< "\n";
	
	return 0;
}
