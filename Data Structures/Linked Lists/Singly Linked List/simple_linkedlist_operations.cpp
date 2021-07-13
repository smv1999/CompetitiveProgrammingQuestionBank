/*

*/
 
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

};

// inserts to the list at the beginning

Node* insert_to_list(Node* head){

    cout << "enter the number to be inserted in beginning : ";

    int number;

    cin >> number;

    Node* temp = new Node();

    temp -> data = number;

    temp -> next = head;

    head = temp;

    return head;

}

// deletes the first node from list 

Node* delete_from_list(Node* head){

    // cout << "enter the number to be removed from list : ";

    // int number;

    // cin >> number;

    Node* temp = new Node();

    temp = head;

    head  = head -> next;

    delete temp;
    
    return head;

}

// prints list

void print_list(Node* n){

    while (n != NULL)
    {
        cout << n -> data << " ";
        n = n -> next;
    }
    cout << endl;

}

 
int main()
{
    
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head -> data = 1;
    head -> next = second;

    second -> data = 2;
    second -> next = third;

    third -> data = 3;
    third -> next = NULL;

    bool quit = false;
    int choice;

    while (!quit){

        cout << "1. add to list begninnig" << endl
             << "2. delete first node from list" << endl
             << "3. print list" << endl
             << "4. quit" << endl;

        cin >> choice;
        
        switch(choice){

            case 1: 
            {
                Node* temp = insert_to_list(head);
                head = temp;
                print_list(temp);
                break;
            }
                
            case 2: 
            {
                Node* temp = delete_from_list(head);
                head = temp;
                print_list(temp);
                break;
            }
                
            case 3: 
            {
                print_list(head);
                break;
            }
            
            case 4: 
            {
                quit = true;
                break;
            }
                
            default:{
                cout << "That is not a valid input, quitting program";
                quit = true;

            }
        }
    }

    // Node* temp = insert_node(head);

    // print_list(temp);


    // Node* temp = delete_node(head);

    // print_list(temp);

    return 0;
}