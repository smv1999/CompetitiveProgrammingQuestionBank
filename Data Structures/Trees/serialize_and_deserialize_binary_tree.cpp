/*
Implementation of Serialize and Deserialize Binary Tree

According to the problem:
We need to ensure that a binary tree can be serialized to a string and this string 
can be deserialized to the original tree structure.

NOTE:Serialization is the process of converting a data structure or object into a sequence of 
bits so that it can be stored in a file or memory buffer, or transmitted across a network 
connection link to be reconstructed later in the same or another computer environment.

Link to the problem: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
*/

/*
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
           TreeNode* makeTree(queue<string> &q) {
        string s = q.front();
        q.pop();
        if(s=="null")
            return NULL;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = makeTree(q);
        root->right = makeTree(q);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "null,";
      return to_string(root->val)+","+ serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s ="";
        queue <string> q;
        for(char c: data) {
            if(c ==',') {
                q.push(s);
                s="";
                continue;
            }
            s+=c;
        }
        return makeTree(q);
    }
} 

/*
Time complexity: O(n)

Test cases:

Example 1:

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]

Example 4:

Input: root = [1,2]
Output: [1,2]
*/