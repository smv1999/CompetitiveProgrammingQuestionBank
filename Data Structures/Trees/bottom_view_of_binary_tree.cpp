#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<map>

using namespace std;


class Node
{
public:
    int data;
    Node *left, *right;
};
vector<int> bottomView(Node *root)
{
    vector<int> res;
    queue<pair<Node *, int>> q;
    map<int, int> mp;

    if(root==NULL) return res;

    q.push(make_pair(root, 0)); // horizontal distance of the root is 0

    while(!q.empty())
    {
        pair<Node *, int> p = q.front();

        q.pop();

        Node *curr = p.first;

        int val = p.second;

        mp[val] = curr->data;

        if(curr->left!=NULL)
        {
            q.push(make_pair(curr->left, val-1));
        }
        if(curr->right!=NULL)
        {
            q.push(make_pair(curr->right, val+1));
        }
    }

    for(auto it:mp)
        res.push_back(it.second);
    return res;

}
int main()
{
    Node *root=NULL, *one=NULL, *two=NULL, *three=NULL, *four=NULL;
    vector<int> res;
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

    res = bottomView(root);

    for(int index=0;index<res.size();index++)
        cout<<res[index]<<" ";

    return 0;
}
