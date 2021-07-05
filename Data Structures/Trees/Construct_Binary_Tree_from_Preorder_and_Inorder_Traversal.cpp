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
