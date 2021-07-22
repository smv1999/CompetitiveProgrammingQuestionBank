/*
Given a Binary Search Tree ,Check if its a AVL Tree or not
A BST is said to be a AVL Tree 

AVL Tree can be defined as height balanced binary search tree in which each node is associated with a balance factor
which is calculated by subtracting the height of its right sub-tree from that of its left sub-tree.
Tree is said to be balanced if balance factor of each node is in between -1 to 1, otherwise, 
the tree will be unbalanced and need to be balanced.

Balance Factor (k) = height (left(k)) - height (right(k))
*/

#include <bits/stdc++.h> 
using namespace std;

//Define Node as structure
struct Node 
{
    int key;
    Node* left;
    Node* right;
};
 
/* Function to create a node with 'value' as the data stored in it. 
 Both the children of this new Node are initially null. */
struct Node* newNode(int value)
{
    Node* n = new Node;
    n->key = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function to insert a node with given value to the root
struct Node* insert(struct Node* root,int element) 
{
    /*If the root is NULL , create a node with given element and assign it to root
    else if the root itself is the node with given data , return 
    else recursively insert it in one of the subtrees accordingly */
    if(root==NULL)
        root = newNode(element);
    else if(root->key < element)
        root->right = insert(root->right,element);
    else if(root->key > element)
        root->left = insert(root->left,element);
    
    return root;
}

// Function to calculate height of a given Tree recursively
int Height(struct Node* root)
{
    /* If root is a NULL node return 0
    else recursively calculate heights of subtrees and get height of the root */
    if(root==NULL)
      return 0;
    else
      return 1 + max( Height(root->left) , Height(root->right) );
}

//Function to determine whether given Tree is AVL Tree or not
bool IsAVLTree(struct Node* root)
{
    /* If heights of subtrees differ atmost by 1 , return True
     else return False */
    if(abs( Height(root->left) - Height(root->right) ) <= 1)
      return true;
    else
      return false;
}

// Driver code
int main()
{
    int n;
    cout<<"Enter total no.of nodes of the input Tree ( including NULL nodes ) : ";
    cin>>n;

    //create a null node  and initialise it as a NULL node
    struct Node* root;
    root=NULL;
    
    cout<<"Enter value of each node of the Tree , with head as the first value ( if a node is NULL , enter -1 ) with spaces"<<endl;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data; 
        //take input of data of each node and insert it in the root
        root = insert(root,data);
    }

    //Call the function and print the result
    if(IsAVLTree(root))
        cout<<"Hence given BST is a AVL Tree";
    else
        cout<<"Hence given BST is not a AVL Tree";

    return 0; 
}
    
/*
While entering node values of the tree , 
value of the head of the tree should be enetered first
 
Input Binary Tree:                    
            11                                                             
          /     \                                             
         2      20                                      
        / \                              
       1   5                                
           /
          4
Input: 
Enter total no.of nodes of the input Tree ( including NULL nodes ) : 6
Enter value of each node of the Tree , with head as the first value ( if a node is NULL , enter -1 ) with spaces
11 2 20 1 5 4
Output:
Hence given BST is not a AVL Tree

Time Complexity : O(n) 
   Where n is the no.of nodes ofthe tree
Space Complexity : O(h) 
   Where h is the height of the tree
*/