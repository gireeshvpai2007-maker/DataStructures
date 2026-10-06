#include<stdlib.h>
#include<stdio.h>
struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};
struct node * buildtree(struct Node* root,int val)
{
    if(root==NULL)
    {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val=val;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    if(val<root->val)
    {
        root->left=buildtree(root->left,val);
    }
    else
    {
        root->right=buildtree(root->right,val);
    }
    return root;
}
int countLeaf(struct Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    return countLeaf(root->left)+countLeaf(root->right);
}
int main()
{
    struct Node* root=NULL;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the values of nodes: ");
    for(int i=0;i<n;i++)
    {
        int val;
        scanf("%d",&val);
        root=buildtree(root,val);
    }
    int leafCount = countLeaf(root);
    printf("Number of leaf nodes: %d\n", leafCount);
    return 0;
}