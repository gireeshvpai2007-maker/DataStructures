#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
int insertend(int value)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(front==NULL)
    {
        newnode->next=newnode;
        front=newnode;
        return 0;
    }
    temp=front;
    while(temp->next!=front)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=front;
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