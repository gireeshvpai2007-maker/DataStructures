// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#define  max 5
int Queue[max];
int front=-1,rear=-1;
int enqueue(int a)
{
    if((rear+1)%max==front)
    {
        printf("Queue is Full\n");
        return 0;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
        Queue[rear]=a;
        printf("%d is inserted successfully\n",a);
    }
    else
    {
       rear=(rear+1)%max;
        Queue[rear]=a;
        printf("%d inserted successfully",a);
    }
    return 0;
}
int dequeue()
{
    int del;
    if(front==-1)
    {
        printf("Queue is Empty\n");
       
        
    }
    else if(front==rear)
    {
         del=Queue[front];
        front=-1;rear=-1;
        return del;
    }
    else 
    {
        del=Queue[front];
        front=(front+1)%max;
        return del;
       
    }
    return -1;
}
int display()
{
    if(front == -1)
    {
        printf("Queue is Empty\n");
        return -1;
    }

    printf("Queue:\n");


    for(int i=front;i!=rear;i=(i+1)%max)
    {
        printf("%d ", Queue[i]);

    }
printf("%d ",Queue[rear]);
    printf("\n");

    return 0;
}

int peek()
{
    if(front == -1)
    {
        printf("Queue is Empty\n");
        return -1;
    }

    return Queue[front];
}
int main() {
    int choice;
       do
       {
           
           printf("1.enque 2.dequeue 3. display 4.peek 5.exit\n");
          
           printf("Enter your choice\n");
           scanf("%d",&choice);
           switch(choice)
               {
                   case 1:printf("Enter the element to be inserted\n");int a;
                   scanf("%d",&a);
                   enqueue(a);break;
                   case 2: int del=dequeue();
                   if(del!=-1)
                   {
                       printf("Element dequeued is %d\n",del);
                   }
                   break;
                   case 3:display();break;
                   case 4: printf("Peek element is %d\n",peek());break;
                   case 5:printf("exiting...");break;
                   default:printf("Invalid choice");
               }
           
       }while(choice!=5);
    

    return 0;
}