#include<stdlib.h>
#include <stdio.h>
struct node
{
   int data;
    struct node* next;
    
};
struct node* createnode(int val)
{
    struct node* a=(struct node *)malloc(sizeof(struct node));
    a->data=val;
    a->next=NULL;
    return a;
}
int  insert(struct node** head,struct node** tail,int val)
{
    struct node * a = createnode(val);
    if(*head==NULL)
    {
        *head=*tail=a;
        (*tail)->next= *head;
        (*head)->next=*tail;
    }
    else 
    {
        a->next=*head;
        (*tail)->next=a;
        *tail=a;
    }

}
int rotateclock(struct node** head, struct node** tail)
{
    printf("Enter the no of steps\n");

    int k, count=1;
    scanf("%d",&k);

    if(*head==NULL)
        return 0;

    struct node *temp=*head;

    while(temp->next != *head)
    {
        count++;
        temp=temp->next;
    }

    k=k%count;

    for(int i=0;i<(count-k);i++)
    {
       
        *tail=(*tail)->next;
         *head=(*head)->next;
    }

    return 0;
}
int display(struct node**head)
{
    struct node *temp=*head;
      do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != *head);
    
}
int main() {
printf("Enter the no of Entries\n");
    int n;
    scanf("%d",&n);
    struct node *head=NULL,*tail=NULL;
    for(int i=0;i<n;i++)
        {
            int val;
            scanf("%d",&val);
           insert(&head,&tail,val)  ; 
        }
    rotateclock(&head,&tail);
    printf("List after Rotation\n");
    display(&head);
    return 0;
}