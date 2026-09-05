#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;

void reverseStack(int i, int j)
{
    if (i >= j)
    {
        return;
    }

    // Swap stack[i] and stack[j]
    int temp = stack[i];
    stack[i] = stack[j];
    stack[j] = temp;

    // Move towards the middle
    reverseStack(i + 1, j - 1);
}

int main()
{
    int n;

    printf("Enter the size of the stack: ");
    scanf("%d", &n);

    stack = (int *)calloc(n, sizeof(int));

    if (stack == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the elements of stack:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", stack + i);
    }

    top = n - 1;

    printf("Original Stack:\n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", *(stack + i));
    }

    reverseStack(0, top);

    printf("\nReverse Stack:\n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", *(stack + i));
    }

    free(stack);

    return 0;
}