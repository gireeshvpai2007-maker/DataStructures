#include<stdlib.h>
#include<stdio.h>
struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};
struct Node* buildTree(int val)
{
    if(val == -1)
    {
        return NULL;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    printf("Enter left child of %d (-1 for no child): ", val);
    scanf("%d", &val);
    newNode->left = buildTree(val);
    printf("Enter right child of %d (-1 for no child): ", val);
    scanf("%d", &val);
    newNode->right = buildTree(val);
    return newNode;
}
struct Node* stack[100];
int top = -1;
void preorderTraversal(struct Node* root)
{
    struct Node* current = root;
    while(current != NULL || top != -1)
    {
        while(current != NULL)
        {
            printf("%d ", current->val);
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        current = current->right;
    }
}
int main()
{
    int val;
    printf("Enter root value (-1 for no node): ");
    scanf("%d", &val);
    struct Node* root = buildTree(val);
    printf("Preorder Traversal of the tree: ");
    preorderTraversal(root);
    printf("\n");
    return 0;
}