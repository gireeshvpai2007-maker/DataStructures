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
    struct node *temp;
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
    last->next=temp->next;
    free(temp);
}
int main()
{
    int value;
    deletebegin();
    printf("Node deleted from the beginning of the circular linked list.\n");
    return 0;
}