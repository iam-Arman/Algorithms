#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent,rank;
public:
    DSU(int n)
    {
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }

    int findUparent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }

        return parent[node]=findUparent(parent[node]);
    }

    void unionByrank(int u,int v)
    {
        int ulpar_u=findUparent(u);
        int ulpar_v=findUparent(v);

        if(ulpar_u==ulpar_v)
        {
            return;
        }
        if(rank[ulpar_v]==rank[ulpar_u])
        {
            parent[ulpar_v]=ulpar_u;
            rank[ulpar_u]++;
        }
        else if(rank[ulpar_u]>rank[ulpar_v])
        {
            parent[ulpar_v]=ulpar_u;

        }
        else
        {
            parent[ulpar_u]=ulpar_v;
        }
    }

};
void solve()
{
   int n,m;
   cin>>n>>m;
   DSU dsu(n);

   for(int i=0;i<m;i++)
   {
    int u,v;
    cin>>u>>v;
    dsu.unionByrank(u,v);
   }

   int q;
   cin>>q;
   while(q--)
   {
     int x,y;
     cin>>x>>y;
     if(dsu.findUparent(x)==dsu.findUparent(y))
     {
       cout<<"yes"<<endl;
     }
     else cout<<"no"<<endl;
   }


 

}

int main()
{
 
    clock_t q= clock();

   // test
    { 
      solve();
    }
 
    cerr << "Run Time : " <<((double)(clock() - q) / CLOCKS_PER_SEC)<<endl;
  
}
