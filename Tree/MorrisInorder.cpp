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
static int i = 0;
Node* buildTree(const vector<int>& v)
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
vector<int> morrisInorder(Node* root)
{
    vector<int> ans;
    Node* curr = root;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            ans.push_back(curr->val);
            curr=curr->right;
        }
        else
        {
            Node* prev = curr->left;
            while(prev->right!=NULL && prev->right!=curr)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                prev->right=curr;
                curr=curr->left;
            }
            else
            {
                prev->right=NULL;
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> v = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};  
    Node * root = buildTree(v);
    vector<int> ans = morrisInorder(root);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}