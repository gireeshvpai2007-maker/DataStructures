#include<iostream>
#include<vector>    
using namespace std;
class Node
{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    
    }
};
static int i=0;
Node* buildTree(const std::vector<int>& v)
{
    if(i>=v.size()||v[i]==-1)
    {
        i++;
        return NULL;
    }
    Node* root =new Node(v[i++]);
    root->left=buildTree(v);
    root->right=buildTree(v);
    return root;

}
int getnum(Node* root,int curr)
{
     if(root==NULL)
       return 0;
       curr=curr*10+root->val;
       if(root->left==NULL && root->right==NULL)
         return curr;
         return getnum(root->left,curr)+getnum(root->right,curr);
}
int Sum(Node* root)
{
     return getnum(root,0);   
}
int main()
{
    std::vector<int> v = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};  
    Node * root = buildTree(v);
    int ans = Sum(root);
    cout<<"Sum of all root to leaf numbers is: ";
    cout<<ans;
    return 0;
}
