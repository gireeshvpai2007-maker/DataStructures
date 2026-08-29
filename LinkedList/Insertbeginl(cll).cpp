#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *last=NULL;
void insertbegin(int value)
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
}
int main()
{
    int value;
    printf("Enter the value to be inserted at the beginning: ");
    scanf("%d",&value);
    insertbegin(value);
    printf("Value %d inserted at the beginning of the circular linked list.\n", value);
    return 0;
}