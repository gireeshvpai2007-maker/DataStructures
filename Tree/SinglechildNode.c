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

int countSingleChildNodes(struct Node* root)
{
    if (root == NULL)
        return 0;

    int count = 0;

    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
    {   if(root->left != NULL)
            printf("Single child node: %d (left child)\n", root->val);
        else
            printf("Single child node: %d (right child)\n", root->val);
        count = 1;
    }

    return count + countSingleChildNodes(root->left) + countSingleChildNodes(root->right);
}
int main()
{
    int val;
    printf("Enter root value (-1 for no node): ");
    scanf("%d", &val);
    struct Node* root = buildTree(val);
    int singleChildCount = countSingleChildNodes(root);
    printf("Total number of single child nodes: %d\n", singleChildCount);
    return 0;
}