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
vector<vector<int>> levelorder(Node* root)
{
   
   vector<vector<int>>ans;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    { int size=q.size();
        vector<int>level;
         for(int i=0;i<size;i++)
         {
        Node* temp = q.front();
        q.pop();
         level.push_back(temp->data);
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
        
    }
    ans.push_back(level);
}
 return ans;
}
int main()
{
    vector<int> v = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};  
    Node * root = buildTree(v);
    
    cout<<"Preorder Traversal:"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Inorder Traversal:"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Postorder Traversal:"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"Levelorder Traversal:"<<endl;
    vector<vector<int>>ans= levelorder(root);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
       cout<<endl;
    }

}