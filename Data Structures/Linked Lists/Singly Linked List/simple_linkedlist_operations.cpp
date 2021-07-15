/*

This program will do simple linkedlist operations like Insertion, Deletion, Searching and Modifying.

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

    Node* temp = new Node();

    temp = head;

    head  = head -> next;

    delete temp;
    
    return head;

}

// search node in the list, returns true if the node is found in the list, if not false

void search_list(Node* head){

    cout << "enter the number to search : ";

    int number;

    cin >> number;

    string result = "false";

    while (head != NULL)
    {

        if(head -> data == number){

            // cout << head -> data << endl;

            if(head -> data){

                result = "true";
            }
            
        }

        head = head -> next;

    }

    cout << result << endl;
    
}

// modifies the node in the list

void modify_list(Node* head){

    int modify_number, replace_number;

    cout << "enter the number to modify : ";

    cin >> modify_number;

    cout << "enter the number that replaces the number : ";

    cin >> replace_number;

    while (head != NULL)
    {

        if(head -> data == modify_number){

            head -> data = replace_number;
        }

        head = head -> next;

    }
    
}


// prints list

void print_list(Node* head){

    while (head != NULL)
    {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;

}

 
int main()
{
    
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head -> data = 1;
    head -> next     = second;

    second -> data = 2;
    second -> next = third;

    third -> data = 3;
    third -> next = NULL;

    bool quit = false;
    int choice;

    while (!quit){

        cout << "1. add number to the list beginning" << endl
             << "2. delete first number from the list" << endl
             << "3. search for number in the list" << endl
             << "4. modify number in the list" << endl
             << "5. print the list" << endl
             << "6. quit" << endl;

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

                search_list(head);
                break;
            }
            
            case 4:
            {   
                modify_list(head);
                print_list(head);
                break;
                
            }

            case 5:
            {
                print_list(head);
                break;
            }
            
            case 6: 
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

    return 0;
}