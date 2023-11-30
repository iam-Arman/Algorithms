#include<bits/stdc++.h>
using namespace std;

inline void file() {
#ifndef ONLINE_JUDGE  
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

using ll = long long;
const ll inf=1e15;

vector<int> shortest_path;
vector<int> negative_cycle;
vector<int> complete(1e5,0);
vector<ll> dis(2e5,inf);

bool bellman_ford(vector<array<ll,2> > graph[],int nodes,int edges,int src,int dest)
{
  
   dis[src]=0; // distance of source node is 0
   
   vector<int> par(nodes+1,-1); 

   for(int i=0;i<nodes;i++)
   {
    bool ok=true;
     for(int j=1;j<=nodes;j++)
     {
        for(auto it : graph[j])
        {
            int u=j;
            int v=it[0];
            ll wt=it[1];
            if(dis[u]!=inf  and dis[u]+wt<dis[v])  // if distance of u is not inf and distance of u + weight of edge is less than distance of v then update distance of v
            {
                par[v]=u;
                dis[v]=dis[u]+wt;
                ok=false;
            }
        
        }
        if(ok) break; // if no updation in any iteration then break
     }
   }
    bool found=false;
    int neg=0;
 
    for(int i=1;i<=nodes;i++)  // if there is any updation in nth iteration then there is negative cycle
    {
          for(auto it : graph[i])
          {
                int u=i;
                int v=it[0];
                ll wt=it[1];
                if(dis[u]!=inf  and dis[u]+wt<dis[v])
                {
                     neg=v;
                     par[v]=u;
                     found=true;
                      break;
                }
          
          }
    }

    if(found)  // if negative cycle found then backtrack to find negative cycle
    {
        for(int i=1;i<=nodes;i++)
        {
            neg=par[neg];
        }

        for(int curr=neg;curr!=neg or complete[curr]==0;curr=par[curr])
        {
            negative_cycle.push_back(curr);
            complete[curr]=1;
        }
        negative_cycle.push_back(neg);
        reverse(negative_cycle.begin(),negative_cycle.end());
        

       return true;
    }
    
     if(dis[dest]==inf) return false;
    else  // if no negative cycle then backtrack to find shortest path
    {
        for(int curr=dest;curr!=-1;curr=par[curr])
        {
            shortest_path.push_back(curr);
        }
        reverse(shortest_path.begin(),shortest_path.end());
    }

    return false;
}

int main()
{
   file();

    int nodes,edges;
    cin>>nodes>>edges;

    vector<array<ll,2> > graph[nodes+1];

    for(int i=0;i<edges;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
    }

    bool ok=bellman_ford(graph,nodes,edges,1,nodes);
    if(ok) 
    {
        cout<<"Negative Cycle Found"<<"\n";
        cout<<"Negative Cycle is : ";
        for(auto it : negative_cycle)
        {
            cout<<it<<" ";
        }
        cout<<"\n";
        negative_cycle.clear();
    }
    else 
    {
        if(shortest_path.size()==0) cout<<"No Path Found"<<"\n";
        else
        {
            cout<<"Shortest Path is : ";
            for(auto it : shortest_path)
            {
                cout<<it<<" ";
            }
            cout<<"\n";
        }
    }
    

}