#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct node
{
    int coeff;int exp;
    struct node *next;
};
void create(int coeff, int exp, struct node **head)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->exp=exp;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        struct node *temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }

}
struct node *addpoly(struct node *head1, struct node *head2)
{
    struct node *result=NULL;
    struct node *temp1=head1;
    struct node *temp2=head2;
    while(temp1!=NULL && temp2!=NULL)
    {
       if(temp1->exp==temp2->exp)
       {
           if(temp1->coeff+temp2->coeff!=0)
           {
               create(temp1->coeff+temp2->coeff,temp1->exp,&result);
           }
           temp1=temp1->next;
           temp2=temp2->next;
       }
       else if(temp1->exp>temp2->exp)
       {
           create(temp1->coeff,temp1->exp,&result);
           temp1=temp1->next;
       }
       else
       {
           create(temp2->coeff,temp2->exp,&result);
           temp2=temp2->next;
       }
    }
    while(temp1!=NULL)
    {
        create(temp1->coeff,temp1->exp,&result);
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        create(temp2->coeff,temp2->exp,&result);
        temp2=temp2->next;
    }
    return result;
}
int main()
{
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *result=NULL;
    create(5,2,&head1);
    create(4,1,&head1);
    create(2,0,&head1);
    create(3,3,&head2);
    create(2,2,&head2);
    create(1,0,&head2);
    result=addpoly(head1,head2);
    struct node *temp=result;

while(temp != NULL)
{   if(temp->exp == 0)
    {  if(temp->coeff != 0)
        printf("%d", temp->coeff);
       else
        printf("(%d)", temp->coeff);
    }
    else if(temp->coeff > 0)
    {
        printf("%dx^%d", temp->coeff, temp->exp);
    }
    else if(temp->coeff < 0)
    {
        printf("(%d)x^%d", temp->coeff, temp->exp);
    }
   

    if(temp->next != NULL)
    {
        printf(" + ");
    }
   
    temp = temp->next;
}
    return 0;
}               