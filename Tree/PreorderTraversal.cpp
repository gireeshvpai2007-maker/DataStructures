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
vector<int> preorder(Node* root)
{
    vector<int>ans;
    if(root==NULL)
    {
        return ans;
    }
    ans.push_back(root->val);
    vector<int>left=preorder(root->left);
    vector<int>right=preorder(root->right);
    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
}
int main()
{
    vector<int> v = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};  
    Node * root = buildTree(v);
    vector<int> ans = preorder(root);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}