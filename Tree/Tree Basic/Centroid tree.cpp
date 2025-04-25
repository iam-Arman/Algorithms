#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    vector<int> graph[n+1];
    vector<int> tree[n+1];
    vector<int> used(n+1);

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> sz(n+1);

    function<int(int,int)> get_size=[&](int node,int par)
    {
        sz[node]=1;
        for(auto it : graph[node])
        {
            if(it==par or used[it]) continue;
            sz[node]+=get_size(it,node);
        }

        return sz[node];
    };

    function<int(int,int,int)> centriod=[&](int node,int par,int s)
    {
        for(auto it : graph[node])
        {
            if(it==par or used[it]) continue;
            if(sz[it]>s/2) return centriod(it,node,s);
        }

        return node;
    };

    function<void(int,int)> add_edge=[&](int u,int v)
    {
        tree[u].push_back(v);
        tree[v].push_back(u);
    };

    function<void(int,int)> decompose=[&](int node,int par)
    {
        int size=get_size(node,0);
        int cen=centriod(node,0,size);
        used[cen]=1;

        if(par!=0) add_edge(cen,par);

        for(auto it : graph[cen])
        {
             if(it==par or used[it]) continue;
             decompose(it,cen);
        }
    };

    decompose(1,0);

}

int main()
{
    solve();
}
