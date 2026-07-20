#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
class Node
{
    public:
    int data;
    Node * left;
    Node * right;
    Node(int a )
    {
        data=a;
        left=NULL;
        right=NULL;
    }
};
static int i=0;
Node* buildTree(const vector<int>&v)
{ 
    if(i>=v.size()||v[i]==-1)
    {   i++;
        return NULL;
        
    }
     Node* root=new Node(v[i++]);
    root->left=buildTree(v);
    root->right=buildTree(v);
    return root;
}
int Height(Node* root)
{
   if(root==NULL)
     return 0;
   return 1+max(Height(root->left),Height(root->right));  

}
int main()
{
    vector<int>v={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildTree(v);
    cout<<"Height of Tree"<<endl;
    cout<<Height(root);
    return 0;
}