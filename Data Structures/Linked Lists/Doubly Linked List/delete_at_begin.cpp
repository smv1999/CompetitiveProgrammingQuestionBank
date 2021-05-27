/*

This is a Doubly Linked List program which deletes a node at the beginning to the Linked List.
Since, it is a Doubly Linked List, both the forward and backward traversal is also possible.

*/

#include <iostream>

using namespace std;

/*

Node definition:
	1. Pointer to previous node.
	2. Integer Data
	3. Pointer to next node.

*/

class dll_node {
public:
	dll_node* prev;
	int data;
	dll_node* next;
};

void createDLL(dll_node* &head) {

	int choice;

	dll_node* temp = head;

	do {

		int data;

		cout << "Enter Data : ";
		cin >> data;

		dll_node* newNode = new dll_node();
		newNode->data = data;
		newNode->prev = NULL;
		newNode->next = NULL;

		if(head == NULL) {
			head = newNode;
			temp = head;
		} else {
			temp->next = newNode;
			newNode->prev = temp;
			temp = newNode;
		}

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);


}

void delete_at_begin(dll_node* &head) {

	if(head == NULL)
		return;

	if(head->next == NULL) {
		dll_node* temp = head;
		head = head->next;
		delete temp;
		return;
	}

	dll_node* temp = head;
	head = head->next;
	head->prev = NULL;
	delete temp;
	return;

}

void display(dll_node* head) {
	cout << "The elements are : ";
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {

	dll_node* head = NULL;

	createDLL(head);

	cout << "Before Deletion : " << endl;
	display(head);

	delete_at_begin(head);

	cout << "After Deletion : " << endl;
	display(head);

	return 0;
}