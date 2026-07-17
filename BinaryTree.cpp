#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    static int i;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }

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
};

int Node::i = 0;

int main()
{
    vector<int> v = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node helper(0);

    Node* root = helper.buildTree(v);

    cout << root->data << endl;
    cout << root->left->data << endl;
    cout << root->right->data << endl;
    cout << root->right->left->data << endl;
}