#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    vector<int> graph[n+1];

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> sz(n+1);

    vector<int> cent;
    
    function<void(int,int)> get_cent=[&](int node,int par)
    {
        bool ok=true;
        sz[node]=1;
        for(auto it : graph[node])
        {
            if(it==par) continue;
            get_cent(it,node);
            sz[node]+=sz[it];
            if(sz[it]*2>n) ok=false;
        }
        if(2*(n-sz[node])>n) ok=false;

        if(ok) cent.push_back(node);
    };

    get_cent(1,0);

    cout<<cent.size()<<endl;

}

int main()
{
    solve();
}
