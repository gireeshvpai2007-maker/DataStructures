
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *buildtree(int data)
{
    if (data == -1)
        return NULL;

    struct node *newnode = malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newnode->data = data;

    printf("Enter left child of %d (-1 for no child): ",
           newnode->data);
    scanf("%d", &data);
    newnode->left = buildtree(data);

    printf("Enter right child of %d (-1 for no child): ",
           newnode->data);
    scanf("%d", &data);
    newnode->right = buildtree(data);

    return newnode;
}

/* Iterative inorder: Left, Root, Right */
int inorder(struct node *root)
{
    struct node *stack[100];
    int top = -1;
    struct node *temp = root;

    printf("Inorder: ");

    while (top != -1 || temp != NULL)
    {
        while (temp != NULL)
        {
            stack[++top] = temp;
            temp = temp->left;
        }

        temp = stack[top--];
        printf("%d ", temp->data);
        temp = temp->right;
    }

    printf("\n");
    return 0;
}

/* Iterative preorder: Root, Left, Right */
int preorder(struct node *root)
{
    if (root == NULL)
    {
        printf("Preorder: \n");
        return 0;
    }

    struct node *stack[100];
    int top = -1;

    stack[++top] = root;
    printf("Preorder: ");

    while (top != -1)
    {
        struct node *temp = stack[top--];
        printf("%d ", temp->data);

        if (temp->right != NULL)
            stack[++top] = temp->right;

        if (temp->left != NULL)
            stack[++top] = temp->left;
    }

    printf("\n");
    return 0;
}

/* Iterative postorder using two stacks */
int postorder(struct node *root)
{
    if (root == NULL)
    {
        printf("Postorder: \n");
        return 0;
    }

    struct node *s1[100], *s2[100];
    int top1 = -1, top2 = -1;

    s1[++top1] = root;
    printf("Postorder: ");

    while (top1 != -1)
    {
        struct node *temp = s1[top1--];
        s2[++top2] = temp;

        if (temp->left != NULL)
            s1[++top1] = temp->left;

        if (temp->right != NULL)
            s1[++top1] = temp->right;
    }

    while (top2 != -1)
        printf("%d ", s2[top2--]->data);

    printf("\n");
    return 0;
}

/* BST search */
struct node *searchBinary(struct node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key > root->data)
        return searchBinary(root->right, key);

    return searchBinary(root->left, key);
}

/* Minimum node in a BST */
struct node *low(struct node *root)
{
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

/* Maximum node in a BST */
struct node *high(struct node *root)
{
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

/* Find and print parent of a key in a binary tree */
int parent(struct node *root, int key)
{
    if (root == NULL)
        return 0;

    if ((root->left != NULL && root->left->data == key) ||
        (root->right != NULL && root->right->data == key))
    {
        printf("Parent of %d is %d\n", key, root->data);
        return 1;
    }

    if (parent(root->left, key))
        return 1;

    return parent(root->right, key);
}

/* Print ancestors from root to the parent of key */
int ancestor(struct node *root, int key)
{
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    if (ancestor(root->left, key) ||
        ancestor(root->right, key))
    {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

/* Count and print internal nodes */
int internalnode(struct node *root)
{
    if (root == NULL)
        return 0;

    int count = 0;

    if (root->left != NULL || root->right != NULL)
    {
        printf("%d ", root->data);
        count = 1;
    }

    return count + internalnode(root->left)
                 + internalnode(root->right);
}

/* Sum of nodes at a given level; root is level 0 */
int levelsum(struct node *root, int level)
{
    if (root == NULL || level < 0)
        return 0;

    struct node *q[100];
    int front = 0, rear = -1;
    int currentLevel = 0, sum = 0;

    q[++rear] = root;

    while (front <= rear)
    {
        int size = rear - front + 1;

        for (int i = 0; i < size; i++)
        {
            struct node *temp = q[front++];

            if (currentLevel == level)
                sum += temp->data;

            if (temp->left != NULL && rear < 99)
                q[++rear] = temp->left;

            if (temp->right != NULL && rear < 99)
                q[++rear] = temp->right;
        }

        if (currentLevel == level)
            return sum;

        currentLevel++;
    }

    return 0;
}

/* Free all allocated nodes */
void freeTree(struct node *root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void)
{
    struct node *root;
    int data, key, level;

    printf("Enter root node (-1 if tree is empty): ");
    if (scanf("%d", &data) != 1)
        return 1;

    root = buildtree(data);

    inorder(root);
    preorder(root);
    postorder(root);

    printf("\nEnter node to search: ");
    if (scanf("%d", &key) != 1)
    {
        freeTree(root);
        return 1;
    }

    struct node *temp = searchBinary(root, key);

    if (temp != NULL)
        printf("Node found: %d\n", temp->data);
    else
        printf("Node not found\n");

    if (parent(root, key) == 0)
        printf("Parent not found (node may be root or absent)\n");

    printf("Ancestors: ");
    if (!ancestor(root, key))
        printf("Node not found");
    printf("\n");

    printf("Internal nodes: ");
    int count = internalnode(root);
    printf("\nNumber of internal nodes: %d\n", count);

    printf("Enter level for sum (root is level 0): ");
    if (scanf("%d", &level) == 1)
        printf("Level sum: %d\n", levelsum(root, level));

    /* These two operations assume the input is a BST */
    struct node *minimum = low(root);
    struct node *maximum = high(root);

    if (minimum != NULL)
        printf("Minimum (BST): %d\n", minimum->data);

    if (maximum != NULL)
        printf("Maximum (BST): %d\n", maximum->data);

    freeTree(root);
    return 0;
}

