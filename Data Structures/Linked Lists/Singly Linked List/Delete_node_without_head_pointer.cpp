/**************************************************
 
 
Delete a Node from linked list without head pointer
 
Input: 1->2->3->4->5

Output: 1->2->4->5   //if 3 is to be deleted
 
***************************************************/
 
 //Deleting a node where head pointer is given is very easy, however, 
 //here we don't have the head pointer and only have the pointer of the node which we want to delete.
 
 //A simple approach would be to have a ptr node that points to the pointer next to deleted node
 //All you have to do is copy the ptr data into deleted node's data
 //And do some manipulation with both the pointers.
 
 
 //SOLUTION (in C++):
 
 #include<bits/stdc++.h>
 
 using namespace std;
 
 struct Node{
    int data;
    struct Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
 }*head = NULL, *ptr = NULL, *temp = NULL;
 
 void create(int value)
 {
    if(head == NULL)
    {
        head = new Node(value);
        temp = head;
    }
    else
    {
        temp->next = new Node(value);
        temp = temp->next;
        temp->next = NULL;
    }
 }
 
 Node *find_node(struct Node *p, int value)
 {
    while(p!=NULL && p->data != value){
        p = p->next;
    }
    return p;
 }
 
 void deleteNodeWithoutHead(struct Node *del)
 {
    if(del == NULL){  //linked list is empty
        return;
    }
    if(del->next == NULL){
        cout<<"The last node requires head, so it can't be freed"<<endl;
        return;
    }
    ptr = del->next;     // eg: 1->2->3->4->5 suppose del pointer is 3, so,
                         //  so ptr pointer oints to 4
                         //now, acc to the code, 1->2->4->4->5
                         //where the second 4 is ptr after free(ptr), we get,
                         //1->2->4->5;
    del->data = del->next->data;
    del->next = del->next->next;
    ptr->next = NULL;
    free(ptr);
 }
 
 void print(struct Node *node)
 {
    while(node!=NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
 }
 
 int main()
 {
    int n, i, k, data;
    cout<<"Enter n"<<endl;
    cin>>n;
    cout<<"Create a linked list"<<endl;
    for(i = 0;i<n;i++)
    {
        cin>>data;
        create(data);
    }
    cout<<"Enter the value where you want your delete pointer to be"<<endl;
    cin>>k;
    // Delete k without sending head
    Node* del = find_node(head, k);
    deleteNodeWithoutHead(del);
 
    // Print the final linked list
    cout<<"Final Linked List after deletion:\n";
    print(head);
 
    return 0;
 
 }