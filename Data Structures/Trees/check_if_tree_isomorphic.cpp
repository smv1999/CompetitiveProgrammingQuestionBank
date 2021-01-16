/*
Given two Binary Trees. Check whether they are Isomorphic or not.

Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and 
right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
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

bool isIsomorphic(Node *root1, Node *root2);

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        Node *root1 = buildTree(s1);
        Node *root2 = buildTree(s2);
        if (isIsomorphic(root1, root2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

bool isIsomorphic(Node *root1, Node *root2)
{
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    if (root1->data != root2->data)
        return false;
    if (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right) ||
        isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left))
        return true;
}