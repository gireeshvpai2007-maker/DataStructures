#include<stdio.h>
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
};
struct Node *head=NULL;
int insertBegin(int data)
{
    Node* newNode=(Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=head;
    newNode->prev=NULL;
    if(head!=NULL)
    {
        head->prev=newNode;

    }
    head=newNode;
    return 0;
}
int main()
{
    insertBegin(10);
    insertBegin(20);
    insertBegin(30);
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}