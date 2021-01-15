/*
Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to 
construct the binary tree from these traversals.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void preOrder(Node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);

    preOrder(node->left);

    preOrder(node->right);
}

Node *buildTree(int in[], int post[], int n);

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Node *root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

Node *convertTree(int in[], int post[], int is, int ie, int &postIndex)
{
    if (is > ie)
        return NULL;
    Node *root = new Node(post[postIndex--]);

    int inIndex = 0;
    for (int i = is; i <= ie; i++)
    {
        if (in[i] == root->data)
        {
            inIndex = i;
            break;
        }
    }

    root->right = convertTree(in, post, inIndex + 1, ie, postIndex);
    root->left = convertTree(in, post, is, inIndex - 1, postIndex);

    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    int postIndex = n - 1;
    return convertTree(in, post, 0, n - 1, postIndex);
}
