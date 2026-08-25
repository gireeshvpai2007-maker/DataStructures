#include<iostream>
#include<stdio.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
};
struct Node* head = NULL;
int insertMiddle( int data, int position)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL || position == 0)
    {
        newNode->next = head;
        if (head != NULL)
        {
            (head)->prev = newNode;
        }
        head = newNode;
        return 0;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Position out of bounds" << endl;
        free(newNode);
        return -1;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    return 0;
}