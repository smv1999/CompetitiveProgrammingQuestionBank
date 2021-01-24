/*
Src : LeetCode
--------------

You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. 
Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.
*/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st;
        for(vector<string> p : paths){
            st.insert(p[0]);
        }
        for(vector<string> p : paths){
            if(!st.count(p[1])) return p[1];
        }
        
     return "";    
    }
};