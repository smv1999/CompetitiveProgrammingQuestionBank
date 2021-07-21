class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { 
    // Optimal Solution without taking any new space
    // Two pointer approach 
    int p1 = m - 1, p2 = n - 1, curr=m+n-1;
    for (int i = curr; i >= 0 && p2 >=0 ;i--) {  
            if (p1 >= 0 && nums1[p1] > nums2[p2]) 
                nums1[i] = nums1[p1--]; 
            else 
                nums1[i] = nums2[p2--];
        }  
    }
};
