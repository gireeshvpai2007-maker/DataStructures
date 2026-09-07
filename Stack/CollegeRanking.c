/*Create a structure for a college, with fields for college name, college code, city and ranking in the last 5 years. (use integer array of length 5 for ranking)

Take input for 5 colleges and display all of them. also display average ranking for all colleges.

B) Create a stack for the colleges. 
- Push the colleges with the highest and lowest average rank.
- Pop one college.
- Display the stack after each operation.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct college
{
    char name[20];
    int code;
    char city[15];
    int ranking[5];
};

void display(struct college c)
{
    printf("Name: %s\n", c.name);
    printf("Code: %d\n", c.code);
    printf("City: %s\n", c.city);

    printf("Ranking in last 5 years: ");
    for (int j = 0; j < 5; j++)
    {
        printf("%d ", c.ranking[j]);
    }

    printf("\n");
}

void push(struct college c[], int avg[])
{
    struct college stack[2];
    int top = -1;
    int high = 0;
    int low = 0;

    // Find highest and lowest average ranking
    for (int i = 1; i < 5; i++)
    {
        if (avg[i] > avg[high])
        {
            high = i;
        }

        if (avg[i] < avg[low])
        {
            low = i;
        }
    }

    // Push college with highest average rank
    stack[++top] = c[high];

    printf("\nAfter pushing college with highest average rank:\n");
    display(stack[top]);

    // Push college with lowest average rank
    stack[++top] = c[low];

    printf("\nAfter pushing college with lowest average rank:\n");

    for (int i = top; i >= 0; i--)
    {
        display(stack[i]);
        printf("\n");
    }

    // Pop one college
    printf("Popped college:\n");
    display(stack[top]);

    top--;

    // Display stack after pop
    printf("\nStack after pop:\n");

    for (int i = top; i >= 0; i--)
    {
        display(stack[i]);
        printf("\n");
    }
}

int main()
{
    struct college c[5];
    int avg[5];

    // Input
    for (int i = 0; i < 5; i++)
    {
        printf("\nEnter the name, code, city:\n");
        scanf("%s %d %s", c[i].name, &c[i].code, c[i].city);

        printf("Enter the ranking in last 5 years:\n");

        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &c[i].ranking[j]);
        }
    }

    // Display colleges and calculate average
    printf("\n===== COLLEGE DETAILS =====\n");

    for (int i = 0; i < 5; i++)
    {
        int sum = 0;

        printf("\nName: %s\n", c[i].name);
        printf("Code: %d\n", c[i].code);
        printf("City: %s\n", c[i].city);

        printf("Ranking in last 5 years: ");

        for (int j = 0; j < 5; j++)
        {
            sum += c[i].ranking[j];
            printf("%d ", c[i].ranking[j]);
        }

        avg[i] = sum / 5;

        printf("\nAverage ranking: %d\n", avg[i]);
    }

    // Stack operations
    push(c, avg);

    return 0;
}