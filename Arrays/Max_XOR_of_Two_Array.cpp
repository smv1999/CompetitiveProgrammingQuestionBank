/* 
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], 
where 0 ≤ i ≤ j < n.
*/

#include<iostream>
#include<vector>
using namespace std;

// Constructing a trie
struct trie {
        trie *zero,*one;
};

//Building the trie
void insert(int num,trie *root) {
   // Store the head
   trie *ptr=root;
      for(int i=31;i>=0;i--) {
        // Find the i-th bit
         int h = (num>>i & 1);
           if(h==0) {
               // If ptr->zero is NULL
                if(ptr->zero==NULL) {
                    ptr->zero=new trie();
                }
                // Update ptr to ptr->zero
                ptr=ptr->zero;
            }
            else {
                // If ptr->onr is NULL
                if(ptr->one==NULL) {
                    ptr->one=new trie();
                }
                // Update ptr to ptr->one
                ptr=ptr->one;
            }
        }
}

//Finding the maximum XOR for each element   
int comp(int num,trie *root) {
        trie *ptr = root;
        int sum=0;
        for(int i=31;i>=0;i--) {
            sum=sum<<1;
            // Finding ith bit
           int h = (num>>i & 1);
           // Check if the bit is 0
            if(h==0) {
                // If right node exists
                if(ptr->one) {
                   sum++;
                    ptr=ptr->one;
                }
                else ptr=ptr->zero;
                
            }
            else {
                // Check if left node exists
                  if(ptr->zero) {
                   sum++;
                    ptr=ptr->zero;
                }
                else ptr=ptr->one;
            }
        }
        return sum;
}
   
int findMaximumXOR(vector<int>& nums) {
        // head Node of Trie
        trie *root = new trie(); 
        // Insert each element in trie
        for(int i=0;i<nums.size();i++) {
            insert(nums[i],root);
        }
        // Stores the maximum XOR value
        int maxm=0;
        // Traverse the given array
        for(int i=0;i<nums.size();i++) {
            maxm=max(comp(nums[i],root),maxm);
        }
        return maxm;
}

//Main Function
int main() {

   vector<int>nums;
   int sz; 
   
   cout<<"Enter the vector size\n";
   cin>>sz; // size of the vector
 
   cout<<"Enter the elements in the vector\n";
   for(int i=0;i<sz;i++) {
   	 int x; 
	 cin>>x;
	 nums.push_back(x);
   }
  
   int answer = findMaximumXOR(nums);
   cout<<"The Maximum XOR of two numbers in the array/vector is : "<<answer<<endl;   

        return 0;
}

/* Sample Text Case 
 Enter the vector size
 6
 Enter the elements in the vector
 3 10 5 25 2 8
 The Maximum XOR of two numbers in the array/vector is : 28

 Time Complexity : O(n) , where n is the number of elements in the vector.
*/