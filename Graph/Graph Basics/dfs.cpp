#include<bits/stdc++.h>
using namespace std;
vector<int> df;
vector<int> vis(10000,0);

void dfs(vector<int> vec[],int top)
{
   vis[top]=1;
   df.push_back(top);
   for(auto it: vec[top])
   {
    if(!vis[it])
    {
        dfs(vec,it);
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

    dfs(graph,parent);
   for(auto it: df)
   {
    cout<<it<<' ';
   }
   cout<<endl;



    
}
