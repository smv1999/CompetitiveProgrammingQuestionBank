/*
Src : LeetCode
--------------

Given an integer n, return any array containing n unique integers such that they add up to 0.

*/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int i = 1;
        if(n % 2 == 0){
            while(ans.size() != n){
                ans.push_back(i);
                ans.push_back(-i);
                i++;
            }           
        }
        else{
            while(ans.size() != n-1){
                ans.push_back(i);
                ans.push_back(-i);
                i++;
            }    
            ans.push_back(0);
        }
        return ans;
    }
};