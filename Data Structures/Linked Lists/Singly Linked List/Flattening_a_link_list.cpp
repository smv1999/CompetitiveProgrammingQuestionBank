// Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.
// Note: The flattened list will be printed using the bottom pointer instead of next pointer.



// Example 1:

// Input:
// 5 -> 10 -> 19 -> 28
// |     |     |     |
// 7     20    22   35
// |           |     |
// 8          50    40
// |                 |
// 30               45
// Output:  5-> 7-> 8- > 10 -> 19-> 20->
// 22-> 28-> 30-> 35-> 40-> 45-> 50.
// Explanation:
// The resultant linked lists has every
// node in a single level.
// (Note: | represents the bottom pointer.)


// Example 2:

// Input:
// 5 -> 10 -> 19 -> 28
// |          |
// 7          22
// |          |
// 8          50
// |
// 30
// Output: 5->7->8->10->19->20->22->30->50
// Explanation:
// The resultant linked lists has every
// node in a single level.

// (Note: | represents the bottom pointer.)

// Expected Time Complexity: O(N*M)
// Expected Auxiliary Space: O(1)

// Company Tags
// Innovation Labs Amazon Drishti-Soft Flipkart Goldman Sachs Microsoft Paytm Payu Qualcomm Snapdeal Visa

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;

	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}

};
*/

/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root)
{
    vector<int>s;
    Node* secroot = root;
    while(secroot){
        Node* temp = secroot;
        while(temp){
            s.push_back(temp->data);
            temp = temp->bottom;
        }
        secroot = secroot->next;
    }
    sort(s.begin(), s.end());
    Node* root2 = new Node(0);
    Node* dummy = root2;
    for(auto i: s){
        Node* n = new Node(i);
        dummy->bottom = n;
        dummy = dummy->bottom;
    }
    return root2->bottom;


}

