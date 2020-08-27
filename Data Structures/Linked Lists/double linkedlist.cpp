#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>

using namespace std;

class Node
{  public:
    int data;
    Node *prev;
    Node *next;
};

int main()
{
    int val, count=0;
    Node *new_node, *head;
    head = NULL;
    new_node = NULL;
    while(true)
    {
        cin>>val;
        if(val==-1)
        {
            break;
        }

        if(head==NULL)
        {
             head = new Node();
             head->data = val;
             head->prev = NULL;
             head->next = NULL;
        }
        else{
            new_node = new Node();
            new_node->data = val;
            Node *temp;
            temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev=temp;
            new_node->next = NULL;
        }
        count++;
    }
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
    cout<<count;
    return 0;
}
