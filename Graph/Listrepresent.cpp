#include<iostream>
#include<vector>
using namespace std;
int main()
{
    cout<<"enter the no of vertices in the graph : ";
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    cout<<"enter the no of edges in the graph : ";
    int m;  
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cout<<"enter the edge : ";
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"The adjacency list of the graph is : "<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" -> ";
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl ;
    }
    return 0;
}