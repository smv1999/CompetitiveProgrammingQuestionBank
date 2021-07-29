/*
Top view of binary tree
Given a binary tree, print the nodes in left to right manner as visible from above the tree.
Input is given in order of root left child then right child.
For e.g. 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
Tree looks like 
              1
          /      \
      2           3
    /     \       /
  4       5     6
   
nodes '5' and '6' will be overlapped by '1' as seen from above, 
so when viewed from the top , we would see the nodes 4, 2, 1 and 3.
*/

#include <bits/stdc++.h>
using namespace std;

// class for defining the the node, left and right child pointer along 
// with a constructor for assigning the "key" to the node.
class node
{
public:
    int val;
    node *left;
    node *right;

    node(int d)
    {
        val = d;
        left = NULL, right = NULL;
    }
};

// function for taking the input from user and assigning the node values accordingly.
// Queue has been used to assign the "keys" to left and right child alternatively
node *maketree()
{
    int d;
    queue<node *> q;
    cout << "Enter the root value: ";
    cin >> d;
    node *root = new node(d);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        int l, r;
        cout << "\nEnter the left and right childs : ";
        cin >> l >> r;
        if (l != -1)
        {
            // assigning value to the left child pointer and inserting  is as the parent node to repeat the process
            temp->left = new node(l);
            q.push(temp->left);
        }
        if (r != -1)
        {
            // assigning value to the right child pointer and inserting it as the parent node to repeat the process
            temp->right = new node(r);
            q.push(temp->right);
        }
    }
    cout << "\n";
    return root;
}

// The Concept is combining the left side view and right side view of that tree, will be 
// the in total, the top view as all overlapping will be overcomed.

/* Now for printing the tree, firstly the left child are printed recursively.
-->                     1
                    /      \
-->              2           3
                /     \      /
-->            4       5    6
so the nodes 4, 2 and 1 are printed respectively
*/
void printleft(node *root)
{
    if (root == NULL)
        return;
    printleft(root->left);
    cout << root->val << " ";
    return;
}

/* Now for printing the tree, secondly the right child are printed recursively.
                       1            
                    /      \
                 2           3      <--
                /     \      /
               4       5    6   
so the node 3 is printed respectively. 
*/
void printright(node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    printright(root->right);
    return;
}

int main()
{
    // calling the function for making the binary tree
    node *root = maketree();
    // calling the printleft and printright function for printing nodes and overall, the top view
    cout << "Top view: ";
    printleft(root);
    printright(root->right);
    return 0;
}

/*
Sample Input:
Enter the root value: 1
Enter the left and right childs : 2 3
Enter the left and right childs : 4 5
Enter the left and right childs : 6 -1
Enter the left and right childs : -1 -1
Enter the left and right childs : -1 -1
Enter the left and right childs : -1 -1
Sample Output:
Top view: 4 2 1 3 

Time Complexity:  O(n), for traversing the nodes
Space Complexity: O(n), since queue has been used for n nodes
*/