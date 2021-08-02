class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None


class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)

        if not self.head:
            self.head = node
        else:
            self.tail.next = node

        self.tail = node


def print_singly_linked_list(node, sep):
    while node:
        print(str(node.data), end=' ')

        node = node.next


def printt(headd):
    itr = headd
    llstr = []
    while itr:
        llstr.append(itr.data)
        itr = itr.next
    return llstr


def mergeLists(llist1, llist2):
    ll1 = printt(llist1)
    ll2 = printt(llist2)
    ll3 = (ll1 + ll2)
    ll3.sort()
    lll = SinglyLinkedList()
    for ii in ll3:
        lll.insert_node(ii)
    return lll.head


if __name__ == '__main__':

    llist1_count = int(
        input("Enter the number of element to be in linked list 1: "))

    llist1 = SinglyLinkedList()

    print("Enter the elements to be added in list1 line by line")
    for _ in range(llist1_count):
        llist1_item = int(input())
        llist1.insert_node(llist1_item)

    print("\n")
    llist2_count = int(
        input("Enter the number of element to be in linked list 2: "))

    llist2 = SinglyLinkedList()

    print("Enter the elements to be added in list2 line by line")
    for _ in range(llist2_count):
        llist2_item = int(input())
        llist2.insert_node(llist2_item)

    llist3 = mergeLists(llist1.head, llist2.head)

    print("\n")
    print("The merged linked list value: ")
    print_singly_linked_list(llist3, ' ')

'''
Output window:

Enter the number of element to be in linked list 1: 3
Enter the elements to be added in list1 line by line
1
2
3


Enter the number of element to be in linked list 2: 2
Enter the elements to be added in list2 line by line
3
4


The merged linked list value:
1 2 3 3 4

'''
