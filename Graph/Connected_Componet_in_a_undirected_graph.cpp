#include<bits/stdc++.h>
using namespace std;

const int mx=2e5+10;
vector<int> graph[mx];
vector<int> vis(mx,0);
void dfs(int node)
{
    vis[node]=1;
    for(auto x: graph[node])
    {
        if(vis[x]==0) dfs(x);
    }
}

int main()
{
    int node,vertice;
    cin>>node>>vertice;

    for(int i=0;i<vertice;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int cnt=0;
    for(int i=1;i<=node;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
            cnt++;
        }
    }

    cout<<"Number of connected component is "<<cnt<<endl;
}