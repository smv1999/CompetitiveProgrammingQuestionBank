/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Number of nodes in a linked-list can be 0.
Merge all the linked-lists into one sorted linked-list and return it.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int n)
    {
        val = n;
        next = NULL;
    }
};

void printList(ListNode* head){
	int i = 0;
	while(head){
		cout<<head->val<<" ";
		head = head->next;
	}
}

//Go on merging 2 linked list into 1 
ListNode* mergeTwoLists(ListNode* l1,ListNode* l2) {
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->val<l2->val){
       l1->next=mergeTwoLists(l1->next,l2);
       return l1;
    }
    else{
        l2->next=mergeTwoLists(l1,l2->next);
        return l2;
    }
}
 
   
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(!lists.size()) return NULL;
    int l=lists.size();
    while(l>1){
        for(int i=0;i<l/2;i++){
        	//Passing 2 linked-list head to merge them
            lists[i]=mergeTwoLists(lists[i],lists[l-1-i]);
        }
        l=(l+1)/2;
    }
    return lists.front();
}
    
int main()
{
    int NumOfList, NumOfNodes, nl, nn, data;
    vector<ListNode*> headList;
    //cout<<"Enter no of list\n";
    cin>>NumOfList;
    nl = NumOfList;
    
    while(nl--){
    	//cout<<"Enter no of nodes\n";
    	cin>>NumOfNodes;
    	nn = NumOfNodes;
    	ListNode* head = NULL;
    	ListNode* tail = head;
    	int i = NumOfNodes;
    	while(nn--){
    		cin>>data;
    		if(nn == NumOfNodes-1){
    			head = new ListNode(data);
    			tail = head;
			}
			else{
				tail->next = new ListNode(data);
				tail = tail->next;
			}
			
		}
		headList.push_back(head);
	}
	ListNode* finalHead = mergeKLists(headList);
	printList(finalHead);
    return 0;
}
//No extra space used.

