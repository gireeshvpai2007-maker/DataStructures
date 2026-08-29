#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
int deleteend()
{
    struct node *temp,*lastnode;
    if(front==NULL)
    {
        printf("Circular linked list is empty\n");
        return -1;
    }
    temp=front;
    while(temp->next->next!=front)
    {
        temp=temp->next;
        lastnode=temp->next->next;
    }
    temp->next=front;
    free(lastnode);
    return 0;
}
int main()
{
    int value;
    deleteend();
    printf("Node deleted from the end of the circular linked list.\n");
    return 0;
}