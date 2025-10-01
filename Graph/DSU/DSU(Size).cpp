#include<bits/stdc++.h>
using namespace std;


class DSU{
public:
    vector<int> parent,size;
    vector<ll> mx;
    int comp;

    DSU(int n)
    {
        parent.resize(n+1,0);
        size.resize(n+1,0);
        mx.resize(n+1,LLONG_MIN);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
        comp=n;
    }

    int findUpar(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }

    void unionBysize(int u,int v)
    {
        int ulpar_u=findUpar(u);
        int ulpar_v=findUpar(v);
        if(ulpar_u==ulpar_v) return;
        if(size[ulpar_u] < size[ulpar_v]) swap(ulpar_u, ulpar_v);
        parent[ulpar_v] = ulpar_u;
        size[ulpar_u] += size[ulpar_v];
        mx[ulpar_u] = max(mx[ulpar_u], mx[ulpar_v]);
        comp--;
    }

    ll get(int x)
    {
        return mx[findUpar(x)];
    }
};
void solve()
{
   int n,m;
   cin>>n>>m;
   DSU dsu(n);  // creating object of DSU class

   for(int i=0;i<m;i++)
   {
    int u,v;
    cin>>u>>v;
    dsu.unionBysize(u,v);  // calling unionBysize function to make union of u and v
   }

   int q;
   cin>>q;
   while(q--)
   {
     int x,y;
     cin>>x>>y;
     if(dsu.findUpar(x)==dsu.findUpar(y))  // if ultimate parent of x and y is same then they are in same component
     {
       cout<<"yes"<<endl;
     }
     else cout<<"no"<<endl;
   }


 

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
    clock_t q= clock();

    solve();
 
    cerr << "Run Time : " <<((double)(clock() - q) / CLOCKS_PER_SEC)<<endl;
  
}
