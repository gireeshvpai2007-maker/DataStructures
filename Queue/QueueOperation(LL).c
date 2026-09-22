/*Linked lists find applications in the implementation of queues using dynamic
memory allocation. To insert an item into the queue, we allocate memory for the
new node, store data in it, and add the node at the rear end of the existing queue.
To delete an item from the queue, the node at the front of the queue is removed.
Assume the typical function calls for enqueue() and dequeue() as
enqueue(&rear, &front, N); and dequeue(&front, &rear);, where N is the
element to be added. The structure definition of the node is as given.
// Self- referential structure
typedef struct node *queue; struct node{ int data; Nodeptr next; };
Develop the functions to implement linked implementation of enqueue() and
dequeue() operations.
(3)
Develop a C function that accepts a pointer to an array and the size of the array,
and reverses the elements of the array in place. Use pointer arithmetic and the
dereferencing operato*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int enqueue(struct node** front, struct node** rear, int data)
{
    struct node* newNode = createNode(data);
    if (*front == NULL)
    {
        *front = *rear = newNode;
        return 1;
    }
    (*rear)->next = newNode;
    *rear = newNode;
    return 1;
}
int dequeue(struct node** front, struct node** rear)
{
    if (*front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    struct node* temp = *front;
    int data = (*front)->data;
    *front = (*front)->next;
    free(temp);
    if (*front == NULL)
        *rear = NULL;
    return data;
}
int display(struct node* front)
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return 0;
    }
    struct node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 1;
}
int main()
{
    int choice, data;
    struct node* front = NULL;
    struct node* rear = NULL;
    while (1)
    {
        printf("1. Enqueue 2. Dequeue 3. Display 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be added: ");
            scanf("%d", &data);
            enqueue(&front, &rear, data);
            break;
        case 2:
            data = dequeue(&front, &rear);
            if (data != -1)
                printf("Deleted element is %d\n", data);
            break;
        case 3:
            display(front);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}