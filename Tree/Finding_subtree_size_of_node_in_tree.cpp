#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int par,vector<int> tree[],vector<int> &subtree_size)
{
    subtree_size[node]=1;

    for(auto child : tree[node])
    {
        if(child!=par)
        {
            dfs(child,node,tree,subtree_size);
            subtree_size[node]+=subtree_size[child];
        }
    }
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int node;
    cin>>node;

    vector<int> tree[node+1];

    for(int i=0;i<node-1;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int root=1;

    vector<int> subtree_size(node+1,1);

    dfs(root,-1,tree,subtree_size);

    for(int i=1;i<=node;i++)
    {
        cout<<i<<" "<<subtree_size[i]<<endl;
    }

    

}