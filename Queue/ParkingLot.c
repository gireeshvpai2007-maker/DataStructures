/*Write a C program to simulate a Car Parking System (CPS) with a maximum
capacity of N parking slots, where no more than N-1 cars can be parked at a
time. Each car is identified by its registration number and the owner's Aadhar
ID. Vehicles enter the parking lot in order of their arrival and leave in the same
order. If the parking lot is full when a new vehicle arrives, the system should
notify that the parking lot is full. When all vehicles have exited, the system
should indicate that the parking lot is empty. Cars can enter the parking lot if
space becomes available due to the departure of other vehicles.*/
#include <stdio.h>
#include <stdlib.h>
struct Car
{
    int regNo;
    int aadharID;
};
int front = -1;
int rear = -1;
int arrive(struct Car* car,int regNo, int aadharID,int n)
{
    if((rear + 1) % n == front){
        printf("Parking lot is full.\n");
        return 0;
    }
    else
    {
        if(front == -1)
            front = 0;
        rear = (rear + 1) % n;
        car[rear].regNo = regNo;
        car[rear].aadharID = aadharID;
        return 1;
    }
}
int depart(struct Car* car,int n)
{
    if(front == -1)
    {
        printf("Parking lot is empty.\n");
        return 0;
    }
    if(front == rear)
    {
        printf("Car with registration number %d and Aadhar ID %d has departed.\n", car[front].regNo, car[front].aadharID);
        front = -1;
        rear = -1;
        return 1;
    }
    else
    {
        printf("Car with registration number %d and Aadhar ID %d has departed.\n", car[front].regNo, car[front].aadharID);
        front = (front + 1) % n;
        return 1;
    }
}
int display(struct Car* car,int n)
{
    if(front == -1 || front > rear)
    {
        printf("Parking lot is empty.\n");
        return 0;
    }
    else
    {
        printf("Cars in the parking lot:\n");
        for(int i = front; i <= rear; i++)
        {
            printf("Registration Number: %d, Aadhar ID: %d\n", car[i].regNo, car[i].aadharID);
        }
        return 1;
    }
}
int display(struct Car* car,int n)
{
    if(front == -1 || front > rear)
    {
        printf("Parking lot is empty.\n");
        return 0;
    }
    else
    {
        printf("Cars in the parking lot:\n");
        int x = front;
        while(1)
        {
            printf("Registration Number: %d, Aadhar ID: %d\n", car[x].regNo, car[x].aadharID);
            if(x == rear)
                break;
            x = (x + 1) % n;
        }
        return 1;
    }
}
int main()
{
    int N,choice;
    printf("Enter the maximum capacity of parking slots: ");
    scanf("%d", &N);
    struct Car* car = (struct Car*)malloc(N * sizeof(struct Car));
    do
    {
        printf("\nCar Parking System Menu:\n");
        printf("1. Arrive\n");
        printf("2. Depart\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                {
                    int regNo, aadharID;
                    printf("Enter registration number: ");
                    scanf("%d", &regNo);
                    printf("Enter Aadhar ID: ");
                    scanf("%d", &aadharID);
                    arrive(car, regNo, aadharID, N);
                }
                break;
            case 2:
                depart(car, N);
                break;
            case 3:
                display(car, N);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while (choice != 4);
    return 0;
}