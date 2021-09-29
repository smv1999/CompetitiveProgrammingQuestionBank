// Leetcode problem for Binary Tree
// 105. Construct Binary Tree from Preorder and Inorder Traversal

// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

// Example 1:

// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]
----------------------------------------------------------------------------
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre = 0;
        return maketree(pre,0,preorder.size()-1,inorder,preorder);
    }

    TreeNode* maketree(int &pre, int start, int end,vector<int>& inorder, vector<int>& postorder){
        if(start>end || pre>postorder.size())return NULL;
    TreeNode* root = new TreeNode(postorder[pre]);
    int index = -1;
    for(int i = start;i<=end;i++){
        if(inorder[i] == postorder[pre]){
            index = i;
            break;
        }
    }
    pre++;
    root->left = maketree(pre,start, index-1,inorder,postorder);
    root->right = maketree(pre,index+1, end,inorder,postorder);
    return root;
    }
};
