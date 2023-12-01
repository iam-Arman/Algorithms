#include<bits/stdc++.h>
using namespace std;

void spfa(vector<array<int,2> > graph[],int node)
{
    int inf=INT_MAX;
    vector<int> dis(node+1,inf);

    queue<int> q;
    vector<int> count(node+1,0);
    vector<bool> inqueue(node+1,false);

    dis[1]=0;
    q.push(1);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        inqueue[node]=false;

        for(auto it : graph[node])
        {
            int newnode=it[0];
            int wt=it[1];

            if(dis[newnode]>dis[node]+wt)
            {
                dis[newnode]=dis[node]+wt;
                if(!inqueue[newnode])
                {
                    q.push(newnode);
                    inqueue[newnode]=true;
                    count[newnode]++;
                    if(count[newnode]>node)
                    {
                        cout<<"Negative Cycle Found"<<endl;
                        return;
                    }
                }
            }

        }
    }

    cout<<"No Negative Cycle Found"<<endl;


}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int node,edge;
    cin>>node>>edge;

    vector<array<int,2> > graph[node+1];

    for(int i=0;i<edge;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
    }

    spfa(graph,node);
}
