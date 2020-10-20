#include <iostream>

using namespace std;

class Node
{
    Node *left = NULL, *right = NULL;
    int data;

public:
    Node(int data)
    {
        this->data = data;
    }
    void insert(int value);
    bool contains(int value);
    void printInOrder();
};

void Node::insert(int value)
{
    if (value <= this->data)
    {
        if (this->left == NULL)
        {
            this->left = new Node(value);
        }
        else
        {
            this->left->insert(value);
        }
    }
    else
    {
        if (this->right == NULL)
        {
            this->right = new Node(value);
        }
        else
        {
            this->right->insert(value);
        }
    }
}

bool Node::contains(int value)
{
    if (value < this->data)
    {
        if (this->left == NULL)
        {
            return false;
        }
        else
        {
            this->left->contains(value);
        }
    }
    else if (value == this->data)
    {
        return true;
    }
    else
    {
        if (this->right == NULL)
        {
            return false;
        }
        else
        {
            this->right->contains(value);
        }
    }
}

void Node::printInOrder()
{
    if (this->left != NULL)
    {
        this->left->printInOrder();
    }
    cout << this->data << " ";
    if (this->right != NULL)
    {
        this->right->printInOrder();
    }
}

int main(int argc, char const *argv[])
{
    Node *bst = new Node(8);
    bst->insert(7);
    bst->insert(10);
    bst->insert(3);
    bst->insert(4);

    bst->printInOrder();
    cout << "\n";
    cout << bst->contains(10) << endl;
    cout << bst->contains(13) << endl;
    return 0;
}
