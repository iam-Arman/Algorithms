#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> graph[],vector<int> &vis,stack<int> &st)
{
    vis[node]=1;
    for(auto child : graph[node])
    {
        if(!vis[child]) dfs(child,graph,vis,st);
    }

    st.push(node);

}

int main()
{
    int nodes,edges; 
    cin>>nodes>>edges;

    vector<int> graph[nodes+1];

    for(int i=0;i<edges;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }

    vector<int> vis(nodes+1,0);
    stack<int> st;

    for(int i=1;i<=nodes;i++)
    {
        if(!vis[i]) dfs(i,graph,vis,st);
    }

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

}