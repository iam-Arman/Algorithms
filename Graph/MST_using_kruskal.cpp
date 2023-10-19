#include<bits/stdc++.h>
using namespace std;

class dsu
{
    vector<int> parent,size;
public:
    dsu(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        iota(parent.begin(),parent.end(),0);
    }

    int findpar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findpar(parent[node]);
    }

    void unionbysize(int u,int v)
    {
        int pu=findpar(u);
        int pv=findpar(v);

        if(pu==pv) return;

        int su=size[pu];
        int sv=size[pv];

        if(su>=sv)
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }

    void clear()
    {
        iota(parent.begin(),parent.end(),0);
        size.resize(parent.size(),1);
    }


};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int node,edge;
    cin>>node>>edge;

    dsu ds(node);

    vector<array<int,3> > edges;

    for(int i=0;i<edge;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }

    sort(edges.begin(),edges.end());

    int mstsum=0;
    vector<array<int,2> > mstedges;

    for(auto it : edges)
    {
        int w=it[0];
        int u=it[1];
        int v=it[2];

        if(ds.findpar(u)!=ds.findpar(v))
        {
            mstsum+=w;
            mstedges.push_back({u,v});
            ds.unionbysize(u,v);
        }
    }

    cout<<mstsum<<endl;
    for(auto it : mstedges)
    {
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    

}