#include<bits/stdc++.h>
using namespace std;

#define  all(v) v.begin(),v.end()
class dsu
{
    vector<int> parent,size,mx,mn;
public:
    dsu(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        mx.resize(n+1);
        mn.resize(n+1);
        iota(all(parent),0);
        iota(all(mx),0);
        iota(all(mn),0);
    }

    int findpar(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=findpar(parent[node]);
    }

    void unionby(int u,int v)
    {
       int pu=findpar(u);
       int pv=findpar(v);
       if(pu==pv) return;
       int su=size[pu];
       int sv=size[pv];

       if(su>=sv)
       {
              parent[pv]=pu;
              size[pu]+=sv;
              mx[pu]=max(mx[pu],mx[pv]);
              mn[pu]=min(mn[pu],mn[pv]);
       }
       else
       {
              parent[pu]=pv;
              size[pv]+=su;
              mx[pv]=max(mx[pu],mx[pv]);
              mn[pv]=min(mn[pu],mn[pv]);
       }


    }

     int getsize(int node)
    {
        return size[findpar(node)];
    }

    int getmax(int node)
    {
        return mx[findpar(node)];
    }
    
    int getmin(int node)
    {
        return mn[findpar(node)];
    }

};
int main()
{
    int node,edges;
    cin>>node>>edges;

    dsu ds(node);

    for(int i=0;i<edges;i++)
    {
       int x,y;
       cin>>x>>y;
       if(ds.findpar(x)!=ds.findpar(y))
       {
        ds.unionby(x,y);
       }
    } 

    cout<<ds.findpar(2)<<endl;
    cout<<ds.getmax(2)<<endl;
    cout<<ds.getmin(2)<<endl;
}