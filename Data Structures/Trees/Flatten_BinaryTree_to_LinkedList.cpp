/*
Src : LeetCode
--------------

Given the root of a binary tree, flatten the tree into a "linked list":

1) The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
2) The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
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
    TreeNode* flattenSubtrees(TreeNode* root){
        if(!root->left && !root->right) return root;
        if(root->left==NULL)
            return fun(root->right);
        TreeNode* last=fun(root->left);
        last->right=root->right;
        root->right=root->left;
        root->left=NULL;
        return fun(last);
    }
    
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* right=root->right;
        root->right=root->left;
        root->left=NULL;
        TreeNode* cur=root;
        while(cur->right){
            cur=cur->right;
        }
        cur->right=right;
        
    }
};
