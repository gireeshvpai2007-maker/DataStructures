#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *front=NULL;
int deletebegin()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("Circular linked list is empty\n");
        return -1;
    }
    temp=front;
    if(front->next==front)
    {
        front=NULL;
        free(temp);
        return 0;
    }
    while(temp->next!=front)
    {
        temp=temp->next;
    }
    temp->next=front->next;
    front=front->next;
    temp=front;
    free(temp);
}
int main()
{
    int value;
    deletebegin();
    printf("Node deleted from the beginning of the circular linked list.\n");
    return 0;
}