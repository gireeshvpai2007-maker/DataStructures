#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};
 
struct Node* createNode(int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* buildTree(int val)
{
    if(val == -1)
    {
        return NULL;
    }
    struct Node* newNode = createNode(val);
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
void inorderTraversal(struct Node* root)
{
    struct Node* current = root;
    while(current != NULL || top != -1)
    {
        while(current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->val);
        current = current->right;
    }
}
int main()
{
    int val;
    printf("Enter root value (-1 for no node): ");
    scanf("%d", &val);
    struct Node* root = buildTree(val);
    printf("Inorder Traversal of the tree: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}