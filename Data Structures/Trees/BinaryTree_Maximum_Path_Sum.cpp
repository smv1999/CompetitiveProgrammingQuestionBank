/*
Src : LeetCode
--------------

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any path.

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=root->val,sum;
        sum=helper(root,ans);
        return max(ans,sum);
    }
    
    int helper(TreeNode* root,int &ans){
        if(root==NULL)
            return 0;
        int l=helper(root->left,ans);
        int r=helper(root->right,ans);
        if(l<0)
            l=0;
        if(r<0)
            r=0;
        ans=max(ans,l+r+root->val);
        return max(l+root->val,r+root->val);
    }
};
