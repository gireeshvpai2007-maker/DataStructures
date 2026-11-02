
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[50];
    int id;
    struct node *left, *right;
    struct node *next;
};

struct node *root = NULL;
struct node *top = NULL;

/* Create binary tree recursively in preorder */
struct node *create()
{
    int id;
    char name[50];

    printf("Enter station ID (-1 if absent): ");
    scanf("%d", &id);

    if (id == -1)
        return NULL;

    printf("Enter station name: ");
    scanf("%49s", name);

    struct node *a = malloc(sizeof(struct node));

    if (a == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    a->id = id;
    strcpy(a->name, name);

    a->left = a->right = NULL;
    a->next = NULL;

    printf("Enter left child of %d\n", id);
    a->left = create();

    printf("Enter right child of %d\n", id);
    a->right = create();

    return a;
}

/* Push into linked list stack */
void push(struct node *a)
{
    if (a == NULL)
        return;

    a->next = top;
    top = a;
}

/* Pop from linked list stack */
struct node *pop()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return NULL;
    }

    struct node *temp = top;

    top = top->next;
    temp->next = NULL;

    return temp;
}

/* 2. Preorder traversal using linked list stack */
void preorder(struct node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    top = NULL;
    push(root);

    printf("Preorder traversal:\n");

    while (top != NULL)
    {
        struct node *temp = pop();

        printf("%d ", temp->id);

        /* Push right first, then left */
        if (temp->right != NULL)
            push(temp->right);

        if (temp->left != NULL)
            push(temp->left);
    }

    printf("\n");
}

/* 3. Search station ID */
int searchTree(struct node *root, int key)
{
    if (root == NULL)
        return 0;

    if (root->id == key)
        return 1;

    return searchTree(root->left, key) ||
           searchTree(root->right, key);
}

/* 4. Delete only if the station is a leaf node */
struct node *deleteLeaf(struct node *root, int key,
                        int *found, int *notLeaf)
{
    if (root == NULL)
        return NULL;

    if (root->id == key)
    {
        *found = 1;

        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        *notLeaf = 1;
        return root;
    }

    root->left = deleteLeaf(root->left, key, found, notLeaf);

    if (*found == 0)
    {
        root->right = deleteLeaf(root->right, key, found, notLeaf);
    }

    return root;
}

/* Delete station using ID */
void DeleteStation()
{
    int key;
    int found = 0, notLeaf = 0;

    printf("Enter station ID to delete: ");
    scanf("%d", &key);

    root = deleteLeaf(root, key, &found, &notLeaf);

    if (found == 0)
        printf("Station not found\n");

    else if (notLeaf == 1)
        printf("Warning: Station is not a leaf node. Cannot delete.\n");

    else
        printf("Leaf station deleted successfully\n");
}

/* 5. Count leaf nodes */
int leaf(struct node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return leaf(root->left) + leaf(root->right);
}

/* Free entire tree */
void freeTree(struct node *root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}

/* Main menu */
int main()
{
    int choice, key;

    do
    {
        printf("\n1. Input Binary Tree");
        printf("\n2. Preorder Traversal");
        printf("\n3. Search Station");
        printf("\n4. Delete Leaf Station");
        printf("\n5. Count Leaf Nodes");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                freeTree(root);
                top = NULL;

                printf("\nEnter binary tree in preorder:\n");
                root = create();

                printf("Binary tree created successfully\n");
                break;

            case 2:
                preorder(root);
                break;

            case 3:
                printf("Enter station ID to search: ");
                scanf("%d", &key);

                if (searchTree(root, key))
                    printf("Station found\n");
                else
                    printf("Station not found\n");

                break;

            case 4:
                DeleteStation();
                break;

            case 5:
                printf("Number of leaf nodes = %d\n", leaf(root));
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 6);

    freeTree(root);

    return 0;
}
