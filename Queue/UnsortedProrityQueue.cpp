#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int front=-1,rear=-1;
struct queue
{
    int marks;
    char name[20];
    
};
int insert(struct queue **q,char name[20],int marks)
{
     *q=(struct queue*)realloc(*q,(rear+2)*sizeof(struct queue));
    
    if (*q == NULL)
    {
        printf("Memory allocation failed\n");
        return -1;
    }
     if(front==-1)
    {
        front=0;
        rear=0;
        (*q)[rear].marks=marks;
        strcpy((*q)[rear].name,name);
    }
    else
    {
        rear++;
        (*q)[rear].marks=marks;
        strcpy((*q)[rear].name,name);
    }
    return 0;
}
int dequeue(struct queue *q)
{
    if(front==-1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
        return 0;
    }
    else
    {
       int high=0;
         for(int i=front;i<=rear;i++)
          {
                if(q[i].marks>q[high].marks)
                {
                 high=i;
                }
          }
          printf("Dequeued student: %s with marks: %d\n",q[high].name,q[high].marks);
          for(int i=high;i<rear;i++)
          {
                q[i]=q[i+1];
          }
          rear--;
    }
    return 0;
}
int display(struct queue *q)
{
    if(front==-1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        printf("Students in the queue:\n");
        for(int i=front;i<=rear;i++)
        {
            printf("Name: %s, Marks: %d\n",q[i].name,q[i].marks);
        }
    }
    return 0;
}
int main()
{
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    int choice,marks;
    char name[20];
    do
    {
        printf("1. Insert\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter name: ");
                scanf("%s",name);
                printf("Enter marks: ");
                scanf("%d",&marks);
                insert(&q,name,marks);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                 free(q);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=4);
    return 0;
}
