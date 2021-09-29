/* 
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n 
vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water the container can contain is 49.

Constraints:
 n == height.length
 2 <= n <= 105
 0 <= height[i] <= 104
  
*/

/*
Time Complexity: O(N), where N is the size of the array
Space Complexity: O(1), Constant Space
*/

#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int n = height.size(); 
    int i = 0; // one pointer to the start of the array
    int j = n - 1; // one poninter to the end of the array
    int mx = min(height[i], height[j]) * (j - i); // contains the max value of maximum water that can be stored
    while (i < j) 
    {
        if (height[i] < height[j]) // Checking condition if height pointed by i is less than that pointed by j if yes => incrementing i and updating value of mx
        {
            i++;
            mx = max(mx, (min(height[i], height[j]) * (j - i)));
        }
        else // otherwise =>  decrementing j and updating value of mx
        {
            j--;
            mx = max(mx, (min(height[i], height[j]) * (j - i)));
        }
    }
    return mx;
}

int main() // driver function
{
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    int ans = maxArea(heights);
    cout<<ans;
    return 0;
}
