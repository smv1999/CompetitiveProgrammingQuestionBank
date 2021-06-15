/*

This is a Circular Linked List program which reverses the Linked List recursively.

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

cll_node* recursive_reverse_helper(cll_node* head , cll_node* tail) {

	if(head == NULL || head->next == head)
		return head;

	// O(1)
	/*
		// O(n)
		// cll_node* tail = head;
		// while(tail->next != head) {
		// 	tail = tail->next;
		// }
	*/

	tail->next = head->next;
	cll_node* temp = head->next;

	cll_node* newHead = recursive_reverse_helper(temp , tail);

	temp->next = head;
	head->next = newHead;
	return newHead;

}

cll_node* recursive_reverse(cll_node* head) {

	if(head == NULL || head->next == head)
		return head;

	cll_node* tail = head;

	while(tail->next != head) {
		tail = tail->next;
	}

	return recursive_reverse_helper(head , tail);
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

	cout << "Before reversing : " << endl;
	display(head);

	head = recursive_reverse(head);

	cout << "After reversing : " << endl;
	display(head);

	return 0;
}