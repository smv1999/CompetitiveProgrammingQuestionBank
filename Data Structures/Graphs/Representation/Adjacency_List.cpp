/* ADJACENCY LIST FOR REPRESENTING DIRECTED GRAPH
    It is a method of representing a digraph using 2 linked lists
        1. Node list
        2. Edge list corresponding to each node
    Edges arising from a node are stored in edge list of each node
*/

#include <bits/stdc++.h>
using namespace std;

/* Declare a structure for representing digraph with data and 2 links
 * link represents the edge between the parent node and next node (edge list)
 * pnext point to the next node from which new edges arise(node list)
 * g points to the graph
*/
typedef struct AdjacencyList
{
    int data;
    struct AdjacencyList *link, *pnext;
} AdjacencyList;
AdjacencyList *g;

//to insert into the graph
void insert_to_graph(AdjacencyList *g, int parent, int value)
{
    //ptr points to the first node in the graph
    AdjacencyList *ptr = g->link, *p;
    //Check if the graph is empty
    if (g->link == NULL)
    {
        // ptr stores the value of parent node
        ptr = new AdjacencyList;
        ptr->data = parent;
        ptr->pnext = NULL;
        ptr->link = NULL;
        g->link = ptr;
    }
    else
    {
        //Search for parent in the node list
        while (ptr != NULL && ptr->data != parent)
        {
            p = ptr;
            ptr = ptr->pnext;
        }
        //If parent is not found in the node list insert as last node
        if (ptr == NULL)
        {
            ptr = new AdjacencyList;
            ptr->data = parent;
            ptr->pnext = NULL;
            ptr->link = NULL;
            p->pnext = ptr;
        }
    }
    //insert value in the edge list of parent node
    AdjacencyList *node;
    node = new AdjacencyList;
    node->data = value;
    node->link = NULL;
    node->pnext = NULL;
    //Traverse till the end of the edge list
    while (ptr->link != NULL)
        ptr = ptr->link;
    //Insert value as the last node in the edge list
    ptr->link = node;
}

//To delete a node from the graph
void delete_from_graph(AdjacencyList *g, int value)
{
    //Set flag as 0 assuming value is not present in the graph
    int flag = 0;
    //If the graph is not empty
    if (g->link != NULL)
    {
        //ptr points to first node
        AdjacencyList *ptr = g->link, *p, *pre;
        //If the first node in the node list is value
        if (ptr->data == value)
        {
            g->link = ptr->pnext;
            flag = 1;
        }
        else
        {
            //Traverse the node list till value is found
            while (ptr->pnext != NULL && ptr->data != value)
            {
                p = ptr;
                ptr = ptr->pnext;
            }
            //If value is found delete node and entire edge list of the node
            if (ptr->data == value)
            {
                p->pnext = ptr->pnext;
                flag = 1;
            }
        }
        ptr = g->link;
        //Traverse till the end of the node list
        while (ptr != NULL)
        {
            p = ptr;
            //traverse the edge list of p till value is found
            while (p->link && p->data != value)
            {
                pre = p;
                p = p->link;
            }
            // If value is found in the edge list of p delete edge
            if (p->data == value)
            {
                pre->link = p->link;
                flag = 1;
            }
            ptr = ptr->pnext;
        }
    }
    //If flag is 0 value in not present in the graph
    if (flag == 0)
        printf("Node %d does not exist !\n", value);
}

//to print the graph
void print_graph(AdjacencyList *g)
{
    //Check if graph is empty
    if (g->link == NULL)
        printf("Graph Empty !\n");
    else
    {
        AdjacencyList *ptr = g->link, *p;
        //Traverse the node list
        while (ptr)
        {
            p = ptr;
            printf("%d ->", ptr->data);
            //traverse the edge list of p and print all the nodes
            while (p->link)
            {
                printf(" %d", p->link->data);
                p = p->link;
            }
            printf("\n");
            ptr = ptr->pnext;
        }
    }
}

int main()
{
    AdjacencyList *g = (AdjacencyList *)malloc(sizeof(AdjacencyList) * 10);
    g->link = NULL;
    //menu driven program to insert, delete and print graph according to choice
    printf("1. Insert into graph\n2. Delete from graph\n3. Display\n4. Exit\n\n");
    while (1)
    {
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int parent, value;
            printf("Enter parent and value: ");
            scanf("%d %d", &parent, &value);
            insert_to_graph(g, parent, value);
        }
        break;

        case 2:
        {
            int value;
            printf("Enter value: ");
            scanf("%d", &value);
            delete_from_graph(g, value);
        }
        break;

        case 3:
        {
            print_graph(g);
        }
        break;

        case 4:
        {
            return 0;
        }
        }
    }

    return 0;
}
/*
    Sample I/O:
        1. Insert into graph
        2. Delete from graph
        3. Display
        4. Exit
        Enter choice: 1
        Enter parent and value: 2 3
        Enter choice: 1
        Enter parent and value: 3 4
        Enter choice: 1
        Enter parent and value: 1 5
        Enter choice: 1
        Enter parent and value: 2 4
        Enter choice: 3
        2 -> 3 4
        3 -> 4
        1 -> 5
        Enter choice: 4

    TIME COMPLEXITY
        Insertion - O(n)
        Deletion - O(n^2)
        Print graph - O(n^2)
    Total time complexity of the program - O(n^2)
    SPACE COMPLEXITY- O(n)
*/