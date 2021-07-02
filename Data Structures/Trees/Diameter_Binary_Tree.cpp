// The path which has the highest number of nodes is called the diameter of the binary tree.
#include<bits/stdc++.h>
using namespace std;
class node
{   
    public:
    int data;
    node *left;
    node *right;
};
node* newnode(int data)
{
  node *newblock= new node();
  newblock->left=NULL;
  newblock->right=NULL;
}
// calculating the height of the binary tree.
int height (node *p)
{
    if(p==NULL)
    return 0;
    int left=height(p->left);
    int right=height(p->right);
    int h;
    if(left>right)
    {
        h=1+left;
    }
    else
    {
        h=1+right;
    }
    return h;
}
// calculating the diameter of the binary tree.
int final_diameter(node *p)
{
    if(p==NULL)
    return 0;
    //value of the left node is passed to height function to calculate height of left sub tree.
    int left_height=height(p->left); 
    //value of the right node is passed to height function to calculate height of right sub tree.
    int right_height=height(p->right);
    //calculating diameter of left subtree which does not include root node
    int left_diameter=final_diameter(p->left);
    //calculating diameter of right subtree which does not include root node
    int right_diameter=final_diameter(p->right);
    int final=max(left_height+right_height+1 , max(left_diameter,right_diameter));
    return final;
}
int main()
{   
    // formation of a binary tree
    node * root=newnode(5);
    root->left=newnode(3);
    root->left->left=newnode(9);
    root->right=newnode(1);
    root->left->right=newnode(6);
    // printing the final value
    cout<<"Diameter"<<final_diameter(root);
    return 0;
}

/*
    OUTPUT

         5
        / \         the longest path is from the node conatining value '4' to node containing 
       3   1        value '1'.
      / \
     9   6

     Diameter:4


*/
