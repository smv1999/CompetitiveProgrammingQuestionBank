/*
Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors 
of the two nodes in the BST.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N")
        {

            currNode->left = new Node(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N")
        {

            currNode->right = new Node(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node *LCA(Node *root, int l, int h);

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        int l, h;
        getline(cin, s);
        scanf("%d ", &l);
        scanf("%d ", &h);
        Node *root = buildTree(s);
        cout << LCA(root, l, h)->data << endl;
    }
    return 1;
}

Node *LCA(Node *root, int n1, int n2)
{
    Node *a = root, *b = root;
    Node *lca = NULL;
    while (a && b && (a->data != n1 || b->data != n2))
    {
        if (a == b)
            lca = a;

        if (a->data < n1)
            a = a->right;
        else if (a->data > n1)
            a = a->left;

        if (b->data < n2)
            b = b->right;
        else if (b->data > n2)
            b = b->left;
    }
    if (a && b)
        return lca;
    return NULL;
}
