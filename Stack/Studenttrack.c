#include <stdio.h>
#include <stdlib.h>

struct student
{
    int regno;
    char name[20];
    int marks;
};

int top = -1;

int push(struct student *s, struct student *stack, int size)
{
    if (top == size - 1)
    {
        printf("Stack Overflow\n");
        return -1;
    }

    top++;
    stack[top] = *s;

    return 0;
}

int pop(struct student *s, struct student *stack)
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    *s = stack[top];
    top--;

    return 0;
}

int display(struct student *stack)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }

    for (int i = top; i >= 0; i--)
    {
        printf("Regno: %d\tName: %s\tMarks: %d\n",
               stack[i].regno,
               stack[i].name,
               stack[i].marks);
    }

    return 0;
}

int count(struct student *stack, int minmarks, int top)
{
    if (top == -1)
    {
        return 0;
    }

    if (stack[top].marks >= minmarks)
    {
        return 1 + count(stack, minmarks, top - 1);
    }
    else
    {
        return count(stack, minmarks, top - 1);
    }
}

int main()
{
    int size;

    printf("Enter the size of stack: ");
    scanf("%d", &size);

    struct student *stack =
        (struct student *)calloc(size, sizeof(struct student));

    if (stack == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    struct student s;
    int choice;

    do
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Count students by marks\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter regno: ");
                scanf("%d", &s.regno);

                printf("Enter name: ");
                scanf("%19s", s.name);

                printf("Enter marks: ");
                scanf("%d", &s.marks);

                push(&s, stack, size);
                break;

            case 2:
                if (pop(&s, stack) == 0)
                {
                    printf("Popped student:\n");
                    printf("Regno: %d\tName: %s\tMarks: %d\n",
                           s.regno, s.name, s.marks);
                }
                break;

            case 3:
                display(stack);
                break;

            case 4:
            {
                int minmarks;

                printf("Enter minimum marks: ");
                scanf("%d", &minmarks);

                int countresult = count(stack, minmarks, top);

                printf("Number of students with marks greater than "
                       "or equal to %d: %d\n",
                       minmarks, countresult);
                break;
            }

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    free(stack);

    return 0;
}