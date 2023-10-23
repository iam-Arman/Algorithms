#include<bits/stdc++.h>
using namespace std;


// 0 based indexing
int mstsum=0;
vector<array<int,2> > mst(vector<array<int,2> > vec[],int n)
{
    vector<array<int,2> > ans;

    priority_queue<array<int,3>,vector<array<int,3> >,greater<array<int,3> > > pq;

    vector<bool> vis(n+1,false);

    pq.push({0,0,-1});

    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        
        int node=it[1];
        int wt=it[0];
        int par=it[2];

        if(vis[node]) continue;
        mstsum+=wt;
        vis[node]=true;

        for(auto child : vec[node])
        {
            int newnode=child[0];
            int newwt=child[1];
            if(!vis[newnode])
            {
                pq.push({newwt,newnode,node});
            }
        }

        if(par!=-1)
        {
            ans.push_back({par,node});
        }

        
    }

    return ans;


}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int node,edge;
    cin>>node>>edge;

    vector<array<int,2> > ans[node+1];
    for(int i=0;i<edge;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ans[u].push_back({v,w});
        ans[v].push_back({u,w});
        
    }

    vector<array<int,2> > res=mst(ans,node);

    cout<<"MST sum : "<<mstsum<<endl;

    for(auto it : res)
    {
        cout<<it[0]<<" "<<it[1]<<endl;
    }



}
