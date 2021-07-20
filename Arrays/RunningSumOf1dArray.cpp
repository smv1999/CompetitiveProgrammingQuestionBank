/*Question:-
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
Constraints:

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        return nums;//returning the array
    }
int main(){
vector<int> nums;//to store elements
int n,element;
cin>>n;
 for (int i = 0; i < n; i++)
    {
        cin>>element;
       nums.push_back(element);//storeing the elements
    }
vector<int> result=runningSum(nums);//calling the fuction to return the running sum of array
for (int i = 0; i < result.size(); i++)
{
    cout<<result[i]<<",";//print the elements of running sum array
}

return 0;
}