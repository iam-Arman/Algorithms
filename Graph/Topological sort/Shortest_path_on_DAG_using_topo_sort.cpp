#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<pair<int,int> > graph[],vector<int> &vis,stack<int> &st)
{
    vis[node]=1;
    for(auto child : graph[node])
    {
        if(!vis[child.first]) dfs(child.first,graph,vis,st);
    }

    st.push(node);

}

int main()
{
    int node,edge,source;
    cin>>node>>edge;
    cin>>source;

    vector<pair<int,int> > graph[node+1];

    for(int i=0;i<edge;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back({y,w});
    }

    vector<int> vis(node+1,0);

    stack<int> st;
    dfs(source,graph,vis,st);   

    vector<int> dis(node+1,1e9);
    dis[source]=0;

    while(!st.empty())
    {
        int node=st.top();
        st.pop();

        for(auto child : graph[node])
        {
            if(dis[child.first]>dis[node]+child.second)
            {
                dis[child.first]=dis[node]+child.second;
            }
        }
    }

    for(int i=1;i<=node;i++)
    {
        cout<<dis[i]<<" ";
    }
    cout<<endl;


}