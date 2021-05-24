/*

This is a Doubly Linked List program which gets a integer data from the user and
creates a node which is appended to the Linked List.

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
		} else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);


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
	display(head);

	return 0;
}