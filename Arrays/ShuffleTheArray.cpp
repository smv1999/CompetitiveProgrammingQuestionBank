/*Question-
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
Return the array in the form [x1,y1,x2,y2,...,xn,yn].

Example 1:

Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7] 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
Example 2:

Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]

Constraints:

1 <= n <= 500
nums.length == 2n
1 <= nums[i] <= 10^3

*/
#include<bits/stdc++.h>
using namespace std;
// Create a function to shuffle the array
vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> result; //created result to return store the shuffled array elements
    for (int i = 0; i < n; i++)//Loop to iterate all the elements
    {
        result.push_back(nums[i]);//it will push the ith element
        result.push_back(nums[n + i]);//it will push the (n+i)th element
    }
    return result; //Return the shuffled array
}

int main(){
vector<int> nums;//Create a vector to input elements that you want to shuffle
int n,element;
cin>>n;
 for (int i = 0; i < n*2; i++)
    {
        cin>>element;
       nums.push_back(element);//Push the element that you want to shuffle
    }
vector<int> shuffled=shuffle(nums,n);//created a vector that can store shuffled array
for (int i = 0; i < shuffled.size(); i++)
{
    cout<<shuffled[i]<<","; //print the shuffled array element
}

return 0;
}
