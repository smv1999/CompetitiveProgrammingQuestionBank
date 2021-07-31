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


def print_singly_linked_list(node, sep, fptr):
    while node:
        fptr.write(str(node.data))

        node = node.next

        if node:
            fptr.write(sep)


def printt(headd):
    itr = headd
    llstr = []
    while itr:
        llstr.append(itr.data)
        itr = itr.next
    return llstr


def compare_lists(llist1, llist2):
    ll1 = printt(llist1)
    ll2 = printt(llist2)
    if ll1 == ll2:
        return 'Same'
    else:
        return 'Not Same'


if __name__ == '__main__':

    llist1_count = int(input("Number of nodes in LinkedList1: "))

    llist1 = SinglyLinkedList()
    print("Enter the value to be stored on linkedlist 1: ")
    for _ in range(llist1_count):
        llist1_item = input()
        llist1.insert_node(llist1_item)

    print('\n')
    llist2_count = int(input("Number of nodes in LinkedList2: "))

    llist2 = SinglyLinkedList()

    print("Enter the value to be stored on linkedlist 2: ")
    for _ in range(llist2_count):
        llist2_item = input()
        llist2.insert_node(llist2_item)

    result = compare_lists(llist1.head, llist2.head)

    print('Result:', result)

    '''
    Explanation 1:
    ----------------------------------------------
    Input format:

    Number of nodes in LinkedList1: 2
    Enter the value to be stored on linkedlist 1:
    1
    2

    Number of nodes in LinkedList2: 2
    Enter the value to be stored on linkedlist 2:
    1
    2
    -------------------------------------------------
    Output:

    Result: Same
    --------------------------------------------------
    Explanation 2:
    ----------------------------------------------
    Input format:

    Number of nodes in LinkedList1: 2
    Enter the value to be stored on linkedlist 1:
    1
    2

    Number of nodes in LinkedList2: 2
    Enter the value to be stored on linkedlist 2:
    2
    1
    -------------------------------------------------
    Output:

    Result: Not Same
    --------------------------------------------------
    '''
