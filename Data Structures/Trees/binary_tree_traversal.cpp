#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL, *one = NULL, *two = NULL, *three = NULL, *four = NULL;

    root = new Node();
    root->data = 10; // root node

    one = new Node();
    two = new Node();
    three = new Node();
    four = new Node();

    one->data = 20;
    two->data = 30;
    three->data = 40;
    four->data = 50;

    root->left = one;
    root->right = two;

    root->left->left = three;
    root->left->right = four;

    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);

    return 0;
}
