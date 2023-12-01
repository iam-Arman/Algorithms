#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int par,int dis,vector<int> tree[],vector<int> &dist)
{
    dist[node]=dis;

    for(auto child : tree[node])
    {
        if(child!=par)
        {
            dfs(child,node,dis+1,tree,dist);
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
    vector<int> dist(node+1,0);

    dfs(root,-1,1,tree,dist);

    int mx=max_element(dist.begin(),dist.end())-dist.begin();

    dist.assign(node+1,0);

    dfs(mx,-1,1,tree,dist);

    cout<<"Diameter of tree is : "<<*max_element(dist.begin(),dist.end())<<endl;





}
