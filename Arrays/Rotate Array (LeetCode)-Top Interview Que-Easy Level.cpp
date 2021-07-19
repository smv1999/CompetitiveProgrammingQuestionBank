class Solution //Solution Class
{
    public:
        void rotate(vector<int>& nums, int k) //function for shifting the elements
        {
            int n = nums.size(); //assign size of array
            int start = n - k % n; //starting from first element
            int remainder = k % n; //to move to next index
            vector<int> v(n);
            
            for(int i = 0; i < remainder; i++) //shifting the index
             {
                v[i] = nums[i + start];
             }
            
            for(int i = 0; i < start; i++) //shifting the index
            {
                v[i + remainder] = nums[i];
            }
            
            for(int i = 0; i < n; i++) //for shifting elements
            {
                nums[i] = v[i];
            }
        }
};

