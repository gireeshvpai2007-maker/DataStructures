#include<stdlib.h>
#include<stdio.h>
struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};
static int i = 0;
struct Node* buildTree(const int* v, int size)
{
    if(i>=size||v[i]==-1)
    {
        i++;
        return NULL;
    }
    struct Node* root =(struct Node*)malloc(sizeof(struct Node));
    root->val = v[i++]; 
    root->left=buildTree(v, size);
    root->right=buildTree(v, size);
    return root;

}
int * morrisPostorder(struct Node* root, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int)*100);
    *returnSize = 0;
    struct Node* curr = root;
    while(curr!=NULL)
    {
        if(curr->right==NULL)
        {
            ans[(*returnSize)++] = curr->val;
            curr=curr->left;
        }
        else
        {
            struct Node* prev = curr->right;
            while(prev->left!=NULL && prev->left!=curr)
            {
                prev=prev->left;
            }
            if(prev->left==NULL)
            {
                prev->left=curr;
                ans[(*returnSize)++] = curr->val;
                curr=curr->right;
            }
            else
            {
                prev->left=NULL;
                curr=curr->left;
            }
        }
    }
    for(int l=0,r=*returnSize-1;l<r;l++,r--)
    {
        int temp = ans[l];
        ans[l] = ans[r];
        ans[r] = temp;
    }
    return ans;

}

int main()
{
    int v[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int size = sizeof(v)/sizeof(v[0]);
    struct Node* root = buildTree(v, size);
    int returnSize;
    int* ans = morrisPostorder(root, &returnSize);
    printf("The postorder traversal is : ");
    for(int i=0;i<returnSize;i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    free(ans);
    return 0;
}