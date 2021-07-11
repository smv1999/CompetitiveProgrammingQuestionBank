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
        sort(arr, arr+n);

        int ans = arr[n-1] - arr[0];
        
        for(int i = 0; i < n-1; i++) {
            if(arr[i+1] < k) {
                continue;
            }
            int currMin = min(arr[i+1]-k, arr[0]+k);
            int currMax = max(arr[i]+k, arr[n-1]-k);
            ans = min(ans, currMax-currMin);
        }
        
        return ans;
    }
};

int main(){
	int n,k;
	cin>>n;
	cin>>k;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	Solution obj;
	int min_diff = obj.getMinDiff(arr,n,k);
	cout<<"The difference between the largest and smallest is: " << min_diff<< "\n";
	
	return 0;
}
