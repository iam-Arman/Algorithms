#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int par,vector<int> tree[],vector<int> &leaf_node)
{
    int cnt=0;
    for(auto child : tree[node])
    {
        if(child!=par)
        {
            dfs(child,node,tree,leaf_node);
            cnt++;
        }
    }

    if(cnt==0)
    {
        leaf_node.push_back(node);
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
    vector<int> leaf_node;

    dfs(root,-1,tree,leaf_node);

    sort(leaf_node.begin(),leaf_node.end());

    for(auto it : leaf_node)
    {
        cout<<it<<" ";
    }
    cout<<endl;



}