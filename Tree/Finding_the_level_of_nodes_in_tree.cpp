#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int par,int lev,vector<int> tree[],vector<int> &level)
{
    level[node]=lev;
    for(auto child : tree[node])
    {
        if(child!=par)
        {
            dfs(child,node,lev+1,tree,level);
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
    vector<int> level(node+1,-1);
    dfs(root,-1,0,tree,level);

    for(int i=1;i<=node;i++)
    {
        cout<<i<<" "<<level[i]<<endl;
    }

    

}