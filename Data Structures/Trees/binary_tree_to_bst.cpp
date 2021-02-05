/*
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void printInorder(struct Node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

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

Node *binaryTreeToBST(Node *root);

void inOrder(Node *root, vector<int> &process)
{
    if (root == NULL)
        return;
    inOrder(root->left, process);
    process.push_back(root->data);
    inOrder(root->right, process);
}
void insertElements(Node *root, vector<int> &process, int &index)
{
    if (root == NULL)
        return;
    insertElements(root->left, process, index);
    root->data = process[index++];
    insertElements(root->right, process, index);
}

Node *binaryTreeToBST(Node *root)
{
    vector<int> process;
    inOrder(root, process);
    sort(process.begin(), process.end());
    int index = 0;
    insertElements(root, process, index);

    return root;
}

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Node *res = binaryTreeToBST(root);
        printInorder(res);
        cout << endl;
    }
    return 0;
}
