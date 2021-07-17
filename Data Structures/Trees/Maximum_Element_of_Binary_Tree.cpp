/*
Given a Binary Tree , Print the value of maximum node key 

Argument/Return Type
Input of total no.of nodes is taken
Input of key values of nodes of tree are taken in level order form 
Incase of a null node , -1 is taken as input
A function which returns the maximum element 
If the root is NULL it prints -1
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
 
// Function to create a node with 'value' as the data stored in it. 
// Both the children of this new Node are initially null.
struct Node* newNode(int value)
{
    Node* n = new Node;
    n->key = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function to build tree with given input
struct Node* createTree(vector<int>v)
{
    int n=v.size();
    if(n==0) 
      return NULL;
    vector<struct Node* >a(n);
    //Create a vector of individual nodes with given node values
    for(int i=0;i<n;i++)  
    {
        //If the data is -1 , create a null node
        if(v[i]==-1)  
          a[i] = NULL;
        else 
          a[i] = newNode(v[i]);
    }
    //Interlink all created nodes to create a tree
    //Use two pointers using int to store indexes
    //One to keep track of parent node and one for children nodes
    for(int i=0,j=1;j<n;i++) 
    {
        //If the parent node is NULL , advance children pointer twice
        if(!a[i])
        {
          j=j+2;
          continue;
        } 
        //Connect the two children nodes to parent node
        //First left and then right nodes
        a[i]->left = a[j++];
        if(j<n) 
          a[i]->right = a[j++];
    }
    return a[0];
}

//Function to return maximum value of root key of the given tree
int FindMax(struct Node* root)
{

    // If root is NULL , return -1
    if (root == NULL)
        return -1;
    //Initialise a maximum variable with -1 value 
    // keep track of it traversing the tree in Pre Order Fashion
    int maximum=-1;

    // Create an empty stack and push root to it
    stack<struct Node*> stack;
 
    while (1) 
    {
        while(root)
        {
            //keep visiting left branch , untill we reach extreme left node
            //During each visit , keep updating the maximum value
            maximum=max(maximum,root->key);
            stack.push(root);
            root=root->left;
        }
        if(stack.empty())
           break;
        // Now consider the most recently visited node
        root=stack.top();
        stack.pop();
        //and run Pre Order traversal for its right child 
        root=root->right;
        //repeat the process till there are no more nodes left
    }
    return  maximum;
}
 
// Driver code
int main()
{

    int n;
    cout<<"Enter total no.of nodes of the input Tree ( including NULL nodes ) : ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter value of each node of the tree in level order ( if a node is NULL , enter -1 ) with spaces"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i]; //store the input values in a vector
    }

    //create the tree using input node values  
    struct Node* root=createTree(v); 

    //Call the function and print the result
    cout<<"The maximum value of the node key of given tree is "<<FindMax(root);
    
    return 0; 
}
    
/*
if node is NULL , -1 is entered as it's key
Sample Test Case  
Input Binary Tree :                   
               10                                
           /         \                          
         11              12                    
     /       \        /   \               
    5       NULL     6     13             
   / \      /  \    / \   /  \            
  4 NULL  NULL NULL 8  9 10  NULL         
Input : 
Enter total no.of nodes of the input Tree ( including NULL nodes ) : 15
Enter value of each node of the tree in level order ( if a node is NULL , enter -1 ) with spaces
10 11 12 5 -1 6 13 4 -1 -1 -1 8 9 10 -1

Output :
The maximum value of the node key of given tree is 13

Time Complexity : O(n) 
   Where n is the no.of nodes 
Space Complexity : O(n) 
   Where n is the no.of nodes
*/