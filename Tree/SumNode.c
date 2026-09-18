#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node *buildTree(int v)
{
    if(v == -1)
    {
        return NULL;
    }

    struct node *newNode = createNode(v);
    printf("Enter left child of %d (-1 for no child): ", v);
    scanf("%d", &v);
    newNode->left = buildTree(v);
    printf("Enter right child of %d (-1 for no child): ", v);
    scanf("%d", &v);
    newNode->right = buildTree(v);
    return newNode;
}
int sum(struct node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    return root->data + sum(root->left) + sum(root->right);
}
 
int main()
{
    int v;
    printf("Enter root value (-1 for no node): ");
    scanf("%d", &v);
    struct node *root = buildTree(v);
    int totalSum = sum(root);
    printf("Sum of all nodes in the tree: %d\n", totalSum);
    return 0;
}