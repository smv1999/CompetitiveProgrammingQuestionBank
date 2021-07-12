// Red Black Tree implementation in C++

/*A red-black tree is a kind of self-balancing binary search tree where each node has an extra bit, and that bit is often interpreted as the colour (red or black).
*/

#include <iostream>

using namespace std;

// data structure that represents a node in the tree
struct Node {
	int data; // holds the key
	Node *parent; // pointer to the parent
	Node *left; // pointer to left child
	Node *right; // pointer to right child
	int color; // 1 -> Red, 0 -> Black
};

typedef Node *NodePtr;

// class RBTree implements the operations in Red Black Tree
class RBTree {
private:
	NodePtr root;
	NodePtr TNULL;

	// initializes the nodes with appropirate values
	// all the pointers are set to point to the null pointer
	void initializeNULLNode(NodePtr node, NodePtr parent) {
		node->data = 0;
		node->parent = parent;
		node->left = nullptr;
		node->right = nullptr;
		node->color = 0;
	}

	void preOrder(NodePtr node) {
		if (node != TNULL) {
			
 		string node_Color = node->color ? "RED" : "BLACK";
		   cout << node->data << "(" << node_Color <<")  ";
			preOrder(node->left);
			preOrder(node->right);
		} 
	}

	void inOrder(NodePtr node) {
		if (node != TNULL) {
			inOrder(node->left);
			string node_Color = node->color ? "RED" : "BLACK";
		   cout<<node->data << "(" << node_Color <<")  ";
			inOrder(node->right);
		} 
	}

	void postOrder(NodePtr node) {
		if (node != TNULL) {
			postOrder(node->left);
			postOrder(node->right);
			string node_Color = node->color ? "RED" : "BLACK";
		   cout << node->data << "(" << node_Color << ")  ";
		} 
	}

	// fix the rb tree modified by the delete operation
	void fixDelete(NodePtr x) {
		NodePtr s;
		while (x != root && x->color == 0) {
            	// If the new node gets inserted on the left of parent node
			if (x == x->parent->left) {
				s = x->parent->right;
				if (s->color == 1) {

					// x's sibling S is red
					s->color = 0;
					x->parent->color = 1;
					leftRotate(x->parent);
					s = x->parent->right;
				}

				if (s->left->color == 0 && s->right->color == 0) {

					// x's sibling S is black, and both of S's children are black.
					s->color = 1;
					x = x->parent;
				} 
				else {
					if (s->right->color == 0) {
						// x ’s sibling S is black, S's left child is red, and S's right child is black.
						s->left->color = 0;
						s->color = 1;
						rightRotate(s);
						s = x->parent->right;
					} 

					// x's sibling S is black, and S's right child is red.
					s->color = x->parent->color;
					x->parent->color = 0;
					s->right->color = 0;
					leftRotate(x->parent);
					x = root;
				}
			} 
			else {
                // If the new node gets inserted on the right of parent node
				s = x->parent->left;
				if (s->color == 1) {
					// x's sibling S is red
					s->color = 0;
					x->parent->color = 1;
					rightRotate(x->parent);
					s = x->parent->left;
				}

				if (s->right->color == 0 && s->right->color == 0) {
					// x's sibling S is black, and both of S's children are black.
					s->color = 1;
					x = x->parent;
				} 
				else {
					if (s->left->color == 0) {
						// x ’s sibling S is black, S's left child is red, and S's right child is black.
						s->right->color = 0;
						s->color = 1;
						leftRotate(s);
						s = x->parent->left;
					} 

					// x's sibling S is black, and S's right child is red.
					s->color = x->parent->color;
					x->parent->color = 0;
					s->left->color = 0;
					rightRotate(x->parent);
					x = root;
				}
			} 
		}
		x->color = 0;
	}


	void rbTransplant(NodePtr u, NodePtr v){
		if (u->parent == nullptr) {
			root = v;
		} 
		else if (u == u->parent->left){
			u->parent->left = v;
		} 
		else {
			u->parent->right = v;
		}
		v->parent = u->parent;
	}

	void deleteNodeHelper(NodePtr node, int key) {
		// find the node containing key
		NodePtr z = TNULL;
		NodePtr x, y;
		while (node != TNULL){
			if (node->data == key) {
				z = node;
			}

			if (node->data <= key) {
				node = node->right;
			} 
			else {
				node = node->left;
			}
		}

		if (z == TNULL) {
			cout<<"Couldn't find key in the tree"<<endl;
			return;
		} 

		y = z;
		int y_original_color = y->color;
		if (z->left == TNULL) {
			x = z->right;
			rbTransplant(z, z->right);
		} 
		else if (z->right == TNULL) {
			x = z->left;
			rbTransplant(z, z->left);
		} 
		else {
			y = minimum(z->right);
			y_original_color = y->color;
			x = y->right;
			if (y->parent == z) {
				x->parent = y;
			} 
			else {
				rbTransplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}

			rbTransplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		delete z;
		if (y_original_color == 0){
			fixDelete(x);
		}
	}
	
	// fix the red-black tree
	void fixInsert(NodePtr k){
		NodePtr u;
		while (k->parent->color == 1) {
			if (k->parent == k->parent->parent->right) {
				u = k->parent->parent->left; // uncle
				if (u->color == 1) {
					// Parent node and uncle node both are RED.
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				} 
				else {
					if (k == k->parent->left) {
						//  Parent node  is right child of Grand parent and new node is left child of parent node
						k = k->parent;
						rightRotate(k);
					}
					// Parent node  is RED and Uncle node is black (or NULL)
					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
				}
			} 
			else {
				u = k->parent->parent->right; // uncle
                	// Similar to the cases in if statement, just invert the sides
				if (u->color == 1) {
					
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;	
				} 
				else {
					if (k == k->parent->right) {
						
						k = k->parent;
						leftRotate(k);
					}
					
					k->parent->color = 0;
					k->parent->parent->color = 1;
					rightRotate(k->parent->parent);
				}
			}
			if (k == root) {
				break;
			}
		}
		root->color = 0;
	}



public:
	RBTree() {
		TNULL = new Node;
		TNULL->color = 0;
		TNULL->left = nullptr;
		TNULL->right = nullptr;
		root = TNULL;
	}

	
    	// Pre-Order traversal
	// Node->Left Subtree->Right Subtree
	void preorder() {
		preOrder(this->root);
        cout<<endl;
	}

	// In-Order traversal
	// Left Subtree -> Node -> Right Subtree
	void inorder() {
		inOrder(this->root);
        cout<<endl;
	}

	// Post-Order traversal
	// Left Subtree -> Right Subtree -> Node
	void postorder() {
		postOrder(this->root);
        cout<<endl;
	}


	// find the node with the minimum key
	NodePtr minimum(NodePtr node) {
		while (node->left != TNULL) {
			node = node->left;
		}
		return node;
	}

	// find the node with the maximum key
	NodePtr maximum(NodePtr node) {
		while (node->right != TNULL) {
			node = node->right;
		}
		return node;
	}

	// find the successor of a given node
	NodePtr successor(NodePtr x) {
		// if the right subtree is not null,
		// the successor is the leftmost node in the
		// right subtree
		if (x->right != TNULL) {
			return minimum(x->right);
		}

		// else it is the lowest ancestor of x whose
		// left child is also an ancestor of x.
		NodePtr y = x->parent;
		while (y != TNULL && x == y->right) {
			x = y;
			y = y->parent;
		}
		return y;
	}

	// find the predecessor of a given node
	NodePtr predecessor(NodePtr x) {
		// if the left subtree is not null,
		// the predecessor is the rightmost node in the 
		// left subtree
		if (x->left != TNULL) {
			return maximum(x->left);
		}

		NodePtr y = x->parent;
		while (y != TNULL && x == y->left) {
			x = y;
			y = y->parent;
		}

		return y;
	}

	// rotate left at node x
	void leftRotate(NodePtr x) {
		NodePtr y = x->right;
		x->right = y->left;
		if (y->left != TNULL) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		} 
		else if (x == x->parent->left) {
			x->parent->left = y;
		} 
		else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	// rotate right at node x
	void rightRotate(NodePtr x) {
		NodePtr y = x->left;
		x->left = y->right;
		if (y->right != TNULL) {
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		} 
		else if (x == x->parent->right) {
			x->parent->right = y;
		} 
		else {
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}

	// insert the key to the tree in its appropriate position
	// and fix the tree
	void insert(int key) {
		// Ordinary Binary Search Insertion
		NodePtr node = new Node;
		node->parent = nullptr;
		node->data = key;
		node->left = TNULL;
		node->right = TNULL;
		node->color = 1; // new node must be red

		NodePtr y = nullptr;
		NodePtr x = this->root;

		while (x != TNULL) {
			y = x;
			if (node->data < x->data) {
				x = x->left;
			} 
			else {
				x = x->right;
			}
		}

		// y is parent of x
		node->parent = y;
		if (y == nullptr) {
			root = node;
		} 
        	else if (node->data < y->data) {
			y->left = node;
		} 
        	else {
			y->right = node;
		}

		// if new node is a root node, simply return
		if (node->parent == nullptr){
			node->color = 0;
			return;
		}

		// if the grandparent is null, simply return
		if (node->parent->parent == nullptr) {
			return;
		}

		// Fix the tree
		fixInsert(node);
	}

	NodePtr getRoot(){
		return this->root;
	}

	// delete the node from the tree
	void deleteNode(int data) {
		deleteNodeHelper(this->root, data);
	}


};

int main() {
	RBTree bst;

    int choice;

    do{
        cout << "\n\n------------------------- RED BLACK TREE ---------------------------" << endl;
        cout << "\nOperations in Red Black Tree" << endl;
        cout << "\nOption 1 : To insert a node" << endl;
        cout << "Option 2 : To delete a node" << endl;
        cout << "Option 3 : Display the Red Black Tree" << endl;
        cout << "Option 4 : To end the program. " << endl;

        cout << "\nEnter your choice : " << endl;
        cin >> choice;

        switch (choice){
        case 1:
            cout << "\n------------- Inserting a node in Red Black Tree ---------------\n" << endl;
            int node1;
            cout << "Enter the value of node you want to insert: ";
            cin >> node1;
            bst.insert(node1);
            break;
        
        case 2:
            cout << "\n------------- Deleting a node in Red Black Tree ---------------\n" << endl;
            int node2;
            cout << "Enter the node you want to delete: ";
            cin >> node2;
            bst.deleteNode(node2);
            break;

        case 3:
            cout << "\n------------- Printing the Red Black Tree ---------------\n" << endl;
            cout << "Pre order : ";
            bst.preorder();
            cout << "\n\nIn order : ";
            bst.inorder();
            cout << "\n\nPost order : ";
            bst.postorder();
            break;

        case 4:
            break;   
        }

    } while(choice != 4);

	return 0;
}

/* 
Test Case : 1
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
1
------------- Inserting a node in Red Black Tree ---------------
Enter the value of node you want to insert: 45
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
1
------------- Inserting a node in Red Black Tree ---------------
Enter the value of node you want to insert: 78
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
1
------------- Inserting a node in Red Black Tree ---------------
Enter the value of node you want to insert: 23
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
1
------------- Inserting a node in Red Black Tree ---------------
Enter the value of node you want to insert: 10
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
89
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
1
------------- Inserting a node in Red Black Tree ---------------
Enter the value of node you want to insert: 24
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
3
------------- Printing the Red Black Tree ---------------
Pre order : 45(BLACK)  23(BLACK)  10(RED)  24(RED)  78(BLACK)
In order : 10(RED)  23(BLACK)  24(RED)  45(BLACK)  78(BLACK)
Post order : 10(RED)  24(RED)  23(BLACK)  78(BLACK)  45(BLACK)
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
2
------------- Deleting a node in Red Black Tree ---------------
Enter the node you want to delete: 24
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
3
------------- Printing the Red Black Tree ---------------
Pre order : 45(BLACK)  23(BLACK)  10(RED)  78(BLACK)
In order : 10(RED)  23(BLACK)  45(BLACK)  78(BLACK)
Post order : 10(RED)  23(BLACK)  78(BLACK)  45(BLACK)
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
4
_____________________________________________________________________________
Test Case : 2
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
1
------------- Inserting a node in Red Black Tree ---------------
Enter the value of node you want to insert: 13
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
1
------------- Inserting a node in Red Black Tree ---------------
Enter the value of node you want to insert: 45
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
1
------------- Inserting a node in Red Black Tree ---------------
Enter the value of node you want to insert: 23
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
3
------------- Printing the Red Black Tree ---------------
Pre order : 23(BLACK)  13(RED)  45(RED)  
In order : 13(RED)  23(BLACK)  45(RED)  
Post order : 13(RED)  45(RED)  23(BLACK)  
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
2
------------- Deleting a node in Red Black Tree ---------------
Enter the node you want to delete: 13
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
3
------------- Printing the Red Black Tree ---------------
Pre order : 23(BLACK)  45(RED)
In order : 23(BLACK)  45(RED)
Post order : 45(RED)  23(BLACK)  
------------------------- RED BLACK TREE ---------------------------
Operations in Red Black Tree
Option 1 : To insert a node
Option 2 : To delete a node
Option 3 : Display the Red Black Tree
Option 4 : To end the program.
Enter your choice :
4
Time Complexity for Insertion in the Red black tree : O(log(n)), where n is the number of nodes in the tree
Time Complexity for Deletion of a node from the tree : O(log(n)), where n is the number of nodes in the tree
Time Complexity for Printing the tree : O(n), where n is the number of nodes in the tree
Time Complexity for the functions rightRotate and leftRotate : O(1) ; since the rotation is at a single node
Space Complexity for Insertion in the Red Black Tree tree : O(n), where n is the number of nodes in the tree
Space Complexity for Deletion in the Red Black Tree tree : O(n), where n is the number of nodes in the tree
*/