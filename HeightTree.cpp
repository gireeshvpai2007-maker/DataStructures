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
    queue<Node*>q;
    if(root == NULL)
     return 0;
    q.push(root);
    q.push(NULL);
    int height=0;
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {    height++;
            if(!q.empty())
            {
               q.push(NULL);
            }
            continue;
        }
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }  

    }
    return height;

}
int main()
{
    vector<int>v={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildTree(v);
    cout<<"Height of Tree"<<endl;
    cout<<Height(root);
    return 0;
}