#include<bits/stdc++.h>
using namespace std;

vector<bool> vis(1000,0);
vector<int> bf;
void bfs(vector<int> graph[],int parent)
{
    queue<int> store;
    store.push(parent);
    vis[parent]=1;
    bf.push_back(parent);
    while(!store.empty())
    {
        int top=store.front();
        store.pop();
        vis[top]=1;
        for(int i=0;i<graph[top].size();i++)
        {
            if(vis[graph[top][i]]) continue;
            bf.push_back(graph[top][i]);
            store.push(graph[top][i]);
            vis[graph[top][i]]=1;
        }
    }
}



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

    int parent=1;
    cin>>parent;// if parent is not fixed every time

    bfs(graph,parent);

    for(auto it : bf)
    {
        cout<<it<<' ';
    }
    cout<<endl;

   

    
}
