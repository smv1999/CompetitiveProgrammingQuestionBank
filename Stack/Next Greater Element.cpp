/*
Approach:

We will first go through the second array (num2) and find greater element for each of the number and we will store them in a unordered map, we do this by iterating from right to left.
Finally we iterate the first array and find next greater value in the mapping table.
Time : O(m+n)
Space: O(n) for stack
*/

public:
    vector nextGreaterElement(vector& nums1, vector& nums2) {
        stack st;
        unordered_map mp;
        vector v;
        
        for(int i=nums2.size()-1; i>=0; i--)
        {
            if(st.empty())
                mp[nums2[i]] = -1;  
            else
            {
                while(!st.empty() and st.top()0 ? (mp[nums2[i]] = st.top()): (mp[nums2[i]] = -1); 
                    
            }
            st.push(nums2[i]);
        }
        
        for(auto x: nums1)
        {
           v.push_back(mp[x]);
        }
        
        return v;
    }
};
