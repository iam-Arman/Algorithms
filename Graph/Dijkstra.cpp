#include<bits/stdc++.h>
using namespace std;

vector<int> path;

void dijkstra(int &source,int &destination,vector<array<long long,2> > graph[])
{
   
    priority_queue<array<long long,2>,vector<array<long long,2> >,greater<array<long long,2> > > pq;

    int n=destination+1;

    vector<long long> dist(n,LONG_LONG_MAX);
    vector<int> parent(n);
    iota(parent.begin(),parent.end(),0);

    pq.push({0,source});
    dist[source]=0;

    while(!pq.empty())
    {
        int node=pq.top()[1];
        long long wt=pq.top()[0];

        pq.pop();

        if(wt>dist[node]) continue;

        for(auto it : graph[node])
        {
            int newnode=it[0];
            long long newwt=it[1];

            if(dist[node]+newwt<dist[newnode])
            {
                dist[newnode]=dist[node]+newwt;
                pq.push({dist[newnode],newnode});
                parent[newnode]=node;
            }
        }
    }

    if(dist[destination]==LONG_LONG_MAX)
    {
        cout<<"-1"<<endl;
        return;
    }

    cout<<"Cost of shortest path is : "<<dist[destination]<<endl;

    cout<<"Shortest path is : ";
    int node=destination;
    while(node!=source)
    {
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(source);

    reverse(path.begin(),path.end());

    for(auto it : path)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    int node,edge;
    cin>>node>>edge;

    vector<array<long long,2> > graph[node+1];

    for(int i=0;i<edge;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});

    }

    int source;
     cin>>source;

    int destination;
    cin>>destination;

    dijkstra(source,destination,graph);



}