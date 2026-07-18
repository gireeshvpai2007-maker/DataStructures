#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }

    
};
    static int i = 0;
    Node* buildTree(const vector<int>& v)
    {    
        if(i >= v.size() || v[i] == -1)
        {
            i++;
            return NULL;
        }

        Node* root = new Node(v[i++]);

        root->left = buildTree(v);
        root->right = buildTree(v);

        return root;
    }

void preorder(Node* root)
{
    if(root==NULL)
    {
       return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root)
{
    if(root==NULL)
    {
       return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root)
{
    if(root==NULL)
    {
       return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelorder(Node* root)
{
   
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
}
cout<<endl;
}
int main()
{
    vector<int> v = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};  
    Node * root = buildTree(v);
  
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
}