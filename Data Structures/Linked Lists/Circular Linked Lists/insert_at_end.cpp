/*

This is a Circular Linked List program which gets a integer data from the user and
creates a node which is inserted at the end of the Linked List.

Since, it is a Circular Linked List, the last node would point to the head node.

*/

#include <iostream>

using namespace std;

/*

Node definition:
	1. Integer Data
	2. Pointer to next node.

*/

class cll_node {
public: 
	int data;
	cll_node* next;
};

void createCLL(cll_node* &head) {

	int choice;

	cll_node* temp = head;

	do {
		int data;

		cout << "Enter Data : ";
		cin >> data;

		cll_node* newNode = new cll_node();
		newNode->data = data;
		newNode->next = NULL;

		if(head == NULL) {
			head = newNode;
			newNode->next = head;
			temp = head;
		} else {
			temp->next = newNode;
			temp = newNode;
			temp->next = head;
		}

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);

}

void display(cll_node* head) {
	cout << "The elements are : ";
	if(head == NULL)
		return;
	cll_node* temp = head;

	do {
		cout << temp->data << " ";
		temp = temp->next;
	} while(temp != head);
	cout << endl;
}

int main() {

	cll_node* head = NULL;

	createCLL(head);
	display(head);

	return 0;
}