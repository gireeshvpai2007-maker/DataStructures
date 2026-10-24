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
void postorderTraversal(struct Node* root)
{
    if(root == NULL)
        return;

    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while(top1 != -1)
    {
        struct Node* curr = stack1[top1--];

        stack2[++top2] = curr;

        if(curr->left != NULL)
            stack1[++top1] = curr->left;

        if(curr->right != NULL)
            stack1[++top1] = curr->right;
    }

    while(top2 != -1)
    {
        printf("%d ", stack2[top2--]->val);
    }
}
int main()
{
    int val;
    printf("Enter root value (-1 for no node): ");
    scanf("%d", &val);
    struct Node* root = buildTree(val);
    printf("Postorder Traversal of the tree: ");
    postorderTraversal(root);
    printf("\n");
    return 0;
}