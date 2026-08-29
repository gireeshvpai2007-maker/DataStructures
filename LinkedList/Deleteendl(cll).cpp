#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *last=NULL;
int deletebegin()
{
    struct node *temp,*lastnode;
    if(last==NULL)
    {
        printf("Circular linked list is empty\n");
        return -1;
    }
    temp=last->next;
    if(last->next==last)
    {
        last=NULL;
        free(temp);
        return 0;
    }
    while(temp->next!=last)
    {
        temp=temp->next;
        lastnode=temp->next->next;
    }
    temp->next=last->next;
    last=temp;
    free(lastnode);
}