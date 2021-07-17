class Solution 
{
    public:
        void rotate(vector<int>& nums, int k) 
        {
            int n = nums.size();
            int start = n - k % n;
            int remainder = k % n;
            vector<int> v(n);
            
            for(int i = 0; i < remainder; i++)
             {
                v[i] = nums[i + start];
             }
            
            for(int i = 0; i < start; i++) 
            {
                v[i + remainder] = nums[i];
            }
            
            for(int i = 0; i < n; i++) 
            {
                nums[i] = v[i];
            }
        }
};

