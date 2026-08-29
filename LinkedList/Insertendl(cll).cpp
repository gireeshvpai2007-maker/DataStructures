#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *last=NULL;
void insertend(int value)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(last==NULL)
    {
        newnode->data=value;
        newnode->next=newnode;
        last=newnode;
        return;
    }
    newnode->data=value;
    newnode->next=last->next;
    last->next=newnode;
    last=newnode;
}
int main()
{
    int value;
    printf("Enter the value to be inserted at the end: ");
    scanf("%d",&value);
    insertend(value);
    printf("Value %d inserted at the end of the circular linked list.\n", value);
    return 0;
}