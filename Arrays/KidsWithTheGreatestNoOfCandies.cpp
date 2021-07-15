#include<bits/stdc++.h>
using namespace std;
// Approach 1
// class Solution {
// public:
//     vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
//         // Firstly let's calculate the max element in the array
//         int max=*max_element(candies.begin(),candies.end());
//         vector<bool> a;
//         for (int i = 0; i < candies.size(); i++)
//         {
//             // If the no. of candies and extra candies is greater than equal to max then we will push_back true else false
//             if(candies[i]+extraCandies>=max){
//                 a.push_back(true);
//             }
//             else{
//                 a.push_back(false);
//             }
//         }
//         return a;
        
//     }
// };
// Approach 2
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       int maxc=*max_element(candies.begin(),candies.end());
       vector<bool> result;
    //    auto will automatically define the data type
    // x is the element of candies array that will be changed after every iteration of for loop
       for(auto x:candies){
           if(x+extraCandies>=maxc)
           result.push_back(true);
           else
           result.push_back(false);
       }
        return result;
    }
};
int main(){
    int element,excandy;
    Solution v;
    vector<int> vc;
    
    for (int i = 0; i < 5; i++)
    {
        cin>>element;
       vc.push_back(element);
    }
    cout<<"Size="<<vc.size()/2;
    cout<<"\nEnter the extra candies:";
    cin>>excandy;
    vector<bool> v1=v.kidsWithCandies(vc,excandy);
    cout<<"\nAfter running sum";
    for (int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i]<<",";
    }
    
    return 0;
}
