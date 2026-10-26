//Display and Count the number of nodes in a given range in a binary tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node* buildtree(int data)
{
    struct node * new= (struct node *)malloc(sizeof(struct node));
    if(data==-1)
        return NULL;
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    
    printf("Enter the left child of %d (-1 for no child)\n",new->data);
    scanf("%d",&data);
    new->left=buildtree(data);
     printf("Enter the right child of %d (-1 for no child)\n",new->data);
    scanf("%d",&data);
    new->right=buildtree(data);
    return new;
}
int nodeinrange(struct node * root,int l, int r)
{
    int count =0;
    if(root==NULL)
    {
        return 0;
    }
    if((root->data)>=l && (root->data)<=r)
    {
        printf("%d is in range\n",root->data);
        count=1;
    }
    return count + nodeinrange(root->left,l,r)+nodeinrange(root->right,l,r);
    
}
int main()
{
    struct node * root;
    printf("Enter the root node or -1 if absent\n");
    int data;
    scanf("%d",&data);
    root=buildtree(data);
    printf("Enter the range of node\n");
    int l,r;
    scanf("%d%d",&l,&r);
    int count=nodeinrange(root,l,r);
    printf("No of Nodes in range=%d",count);
    return 0;
}
