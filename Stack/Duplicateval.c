#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* top = NULL;
int insertinsort( int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL||head->data < data)
    {
        newNode->next = head;
        head = newNode;
        return 0;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data < data)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    top=temp;
    return 0;
}
int removeDuplicate()
{
    struct Node* temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            struct Node* duplicateNode = temp->next;
            temp->next = temp->next->next;
            free(duplicateNode);
        }
        else
        {
            temp = temp->next;
        }
    }
    return 0; // No duplicates
}
int main()
{
    int n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements in sorted order:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insertinsort(data);
    }
    removeDuplicate();
    printf("List after removing duplicates:\n");
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}