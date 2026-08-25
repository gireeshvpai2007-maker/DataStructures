#include <stdio.h>
#include <stdlib.h>

struct node
{
    char name[20];
    int age;
    int priority;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter patient name: ");
    scanf("%s", newnode->name);

    printf("Enter age: ");
    scanf("%d", &newnode->age);

    printf("Enter priority: ");
    scanf("%d", &newnode->priority);

    newnode->next = NULL;

    /* First patient or highest priority */
    if (front == NULL || newnode->priority < front->priority)
    {
        newnode->next = front;
        front = newnode;

        if (rear == NULL)
            rear = newnode;

        return;
    }

    /* Find correct position */
    temp = front;

    while (temp->next != NULL &&
           temp->next->priority <= newnode->priority)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    if (newnode->next == NULL)
        rear = newnode;
}

void dequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("\nPatient being treated:\n");
    printf("Name: %s\n", front->name);
    printf("Age: %d\n", front->age);
    printf("Priority: %d\n", front->priority);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void display()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("\nPatient Queue:\n");

    while (temp != NULL)
    {
        printf("Name: %s | Age: %d | Priority: %d\n",
               temp->name, temp->age, temp->priority);

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            enqueue();

        else if (choice == 2)
            dequeue();

        else if (choice == 3)
            display();

        else if (choice == 4)
            printf("Exiting...\n");

        else
            printf("Invalid choice\n");

    } while (choice != 4);

    return 0;
}