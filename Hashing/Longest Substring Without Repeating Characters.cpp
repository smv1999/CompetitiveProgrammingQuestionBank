/*
****** Approach ******
using unordered map to store the last occurance of a character in the string
if a character is already present in tha map and its last occurance is within the window, we update the answer
else, we update its last occurance

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int ans = 0;
        while(j < s.length()){
            if(!mp.count(s[j])) mp[s[j]] = j;
            else{
                if(mp[s[j]] < i){
                    mp[s[j]] = j;
                }
                else{
                    ans = max(ans, j-i);
                    i = mp[s[j]]+1;
                    mp[s[j]] = j;
                }
            }
            j++;
        }
        ans = max(ans, j-i);
        return ans;
    }
};
