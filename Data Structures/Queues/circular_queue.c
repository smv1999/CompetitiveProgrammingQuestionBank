#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX],rear=-1,front=-1;
void enqueue()
{
    int val;
    printf("Enter value to be inserted: ");
    scanf("%d",&val);
  if (front == 0 && rear == MAX-1)

    {
        printf("\nQueue is Full");
    }

    else if (front == -1)
    {
        front = rear = 0;
        queue[rear] = val;
    }

    else if (rear == MAX-1 && front != 0)
    {
        rear = 0;
        queue[rear] = val;
    }

    else
    {
        rear++;
        queue[rear] = val;
    }
}
void dequeue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
    }

    else if(front>MAX-1)
    {
        front=0;
        printf("\nnumber deleted is %d\t",queue[front]);
        front++;

    }
    else
    {
        printf("\nnumber deleted is %d\t",queue[front]);
        front++;
    }
}
void display()
{
    int i;
    if(rear>=front)
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
    else
    {
        {
        for (i = front; i < MAX; i++)
            printf("%d\t", queue[i]);

        for (i = 0; i <= rear; i++)
            printf("%d\t", queue[i]);
    }
    }
}

int main()
{
    int c;
    while(1)
    {
    printf("\nChoose operation to perform\t1.Insert\t2.Delete\t3.Display\t4.Exit:\n");
    scanf("%d",&c);

    switch(c)
    {
        case 1: enqueue();
        break;
        case 2: dequeue();
        break;
        case 3: display();
        break;
        case 4: exit(0);
    }

}
}
