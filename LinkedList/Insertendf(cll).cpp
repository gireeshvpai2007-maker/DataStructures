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