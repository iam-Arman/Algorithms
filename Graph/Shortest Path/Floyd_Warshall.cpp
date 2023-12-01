#include<bits/stdc++.h>
using namespace std;

int inf=INT_MAX;

bool floyd_warshall(vector<vector<int> >& graph,int nodes)
{
    for(int k=1;k<=nodes;k++)
    {
        for(int i=1;i<=nodes;i++)
        {
            for(int j=1;j<=nodes;j++)
            {
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }

    for(int i=1;i<=nodes;i++)
    {
        if(graph[i][i]<0)  // if any node has negative weight cycle then it will be less than 0
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int node,edge;
    cin>>node>>edge;

    vector<vector<int> > graph(node+1,vector<int>(node+1,inf));

    for(int i=0;i<edge;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        graph[u][v]=wt;
    }

    for(int i=1;i<=node;i++)
    {
        graph[i][i]=0;
    }

    bool ok=floyd_warshall(graph,node);

    if(ok)
    {
        cout<<"Negative Cycle Found"<<endl;
    }

    else
    {
       for(int i=1;i<=node;i++)
       {
           for(int j=1;j<=node;j++)
           {
               cout<<graph[i][j]<<" ";
           }
           cout<<endl;
       }
    }
    
}
