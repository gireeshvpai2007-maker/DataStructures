#include<iostream>
#include<stdio.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
struct Node * head=NULL;
int insertBegin(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=head;
    head=newNode;
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