
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int id;
    char dest[100];
    struct node *left, *right;
};

struct node **stack = NULL;
struct node *root = NULL;
int top = -1;

/* Separate push function */
void push(struct node *a)
{
    struct node **temp = realloc(
        stack, (top + 2) * sizeof(struct node *)
    );

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    stack = temp;
    stack[++top] = a;
}

/* Separate pop function */
struct node *pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return NULL;
    }

    return stack[top--];
}

/* Search for an ID in the pending stack */
int isDuplicateStack(int id)
{
    for (int i = 0; i <= top; i++)
    {
        if (stack[i]->id == id)
            return 1;
    }

    return 0;
}

/* Search for an ID in the dispatched BST */
int searchBST(struct node *root, int key)
{
    if (root == NULL)
        return 0;

    if (root->id == key)
        return 1;

    if (key < root->id)
        return searchBST(root->left, key);

    return searchBST(root->right, key);
}

/* Insert a dispatched package into the BST */
struct node *insertBST(struct node *root, struct node *a)
{
    if (root == NULL)
        return a;

    if (a->id < root->id)
        root->left = insertBST(root->left, a);
    else if (a->id > root->id)
        root->right = insertBST(root->right, a);

    return root;
}

/* 1. AddPackage */
void AddPackage()
{
    int id;
    char destination[100];

    printf("Enter package ID and destination:\n");

    if (scanf("%d %99s", &id, destination) != 2)
    {
        printf("Invalid input\n");
        return;
    }

    if (isDuplicateStack(id) || searchBST(root, id))
    {
        printf("Package ID already exists\n");
        return;
    }

    struct node *a = malloc(sizeof(struct node));

    if (a == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    a->id = id;
    strcpy(a->dest, destination);
    a->left = a->right = NULL;

    push(a);

    printf("Package added successfully\n");
}

/* 2. DispatchPackage */
void DispatchPackage()
{
    struct node *a = pop();

    if (a == NULL)
    {
        printf("No package available for dispatch\n");
        return;
    }

    root = insertBST(root, a);

    printf("Package %d dispatched successfully\n", a->id);
}

/* 3. DisplayPendingPackages */
void DisplayPendingPackages()
{
    if (top == -1)
    {
        printf("No pending packages\n");
        return;
    }

    printf("\nPending packages (top to bottom):\n");

    for (int i = top; i >= 0; i--)
    {
        printf("ID: %d | Destination: %s\n",
               stack[i]->id, stack[i]->dest);
    }
}

/* 4. SearchDispatchedPackages */
void SearchDispatchedPackages()
{
    int key;

    printf("Enter package ID to search:\n");
    scanf("%d", &key);

    if (searchBST(root, key))
        printf("Package %d is dispatched\n", key);
    else
        printf("Package %d not found in dispatched packages\n", key);
}

/* 5. DisplayDispatchedPackages */
void DisplayDispatchedPackages(struct node *root)
{
    if (root == NULL)
        return;

    DisplayDispatchedPackages(root->left);

    printf("ID: %d | Destination: %s\n",
           root->id, root->dest);

    DisplayDispatchedPackages(root->right);
}

/* Free all BST nodes */
void freeBST(struct node *root)
{
    if (root == NULL)
        return;

    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

/* Main menu */
int main()
{
    int choice;

    do
    {
        printf("\n1. AddPackage");
        printf("\n2. DispatchPackage");
        printf("\n3. DisplayPendingPackages");
        printf("\n4. SearchDispatchedPackages");
        printf("\n5. DisplayDispatchedPackages");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                AddPackage();
                break;

            case 2:
                DispatchPackage();
                break;

            case 3:
                DisplayPendingPackages();
                break;

            case 4:
                SearchDispatchedPackages();
                break;

            case 5:
                if (root == NULL)
                    printf("No dispatched packages\n");
                else
                    DisplayDispatchedPackages(root);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 6);

    /* Free remaining pending packages */
    while (top != -1)
        free(pop());

    free(stack);
    freeBST(root);

    return 0;
}

