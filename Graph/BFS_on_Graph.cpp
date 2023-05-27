#include<bits/stdc++.h>
using namespace std;

int main()
{
    int vertice,edge;
    cin>>vertice>>edge;

    vector<int> graph[vertice+1];

    for(int i=0;i<edge;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x); // if non directed graph;
    }

    int parent=0;
    //cin>>parent;

    bool vis[vertice+1];

    vector<int> bfs;

    queue<int> store;

    store.push(parent);

    bfs.push_back(parent);

    while(!store.empty())
    {
        int top=store.front();
        store.pop();
        vis[top]=1;
        for(int i=0;i<graph[top].size();i++)
        {
            if(vis[graph[top][i]]) continue;
            store.push(graph[top][i]);
            bfs.push_back(graph[top][i]);
            vis[graph[top][i]]=1;
        }

    }

    for(auto x: bfs)
    {
        cout<<x<<' ';
    }
    cout<<endl;
   

    
}