#include<bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1139/
void solve()
{
    int n;
    cin>>n;

    vector<int> col(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>col[i];
    }

    vector<int> graph[n+1];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    vector<int> ans(n+1);

    set<int> sz[n+1];
    function<void(int,int)> merge=[&](int a,int b)
    {
        if(sz[b].size()>sz[a].size()) sz[a].swap(sz[b]);
        for(auto it : sz[b])
        {
            sz[a].insert(it);
        }
        sz[b].clear();
    };

    function<void(int,int)> rec=[&](int node,int par)
    {
        sz[node].insert(col[node]);
        for(auto it : graph[node])
        {
            if(it==par) continue;
            rec(it,node);
            merge(node,it);
        }

        ans[node]=sz[node].size();
    };

    rec(1,0);

    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<'\n';

}



int main()
{
    solve();
}
