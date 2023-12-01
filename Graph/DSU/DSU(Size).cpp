#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent,size;  // parent and size
    int comp; // number of component
public:
    DSU(int n)
    {
        parent.resize(n+1,0); // resizing parent
        size.resize(n+1,1); // resizing size
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;  // initializing parent of every node itself
        }
        comp=n;  // initially number of component is n
    }

    int findUpar(int node)
    {
        if(node==parent[node])
        {
            return node;  // if parent of that node it itself returns
        }

        return parent[node]=findUpar(parent[node]);  // compress the path makes ultimate parent as parent to every connected node was traverse during finding ultimate parent
    }

    void unionBysize(int u,int v)
    {
        int ulpar_u=findUpar(u);  // finding ultimate parent of u and v
        int ulpar_v=findUpar(v);

        if(ulpar_u==ulpar_v)  // if both are in same componet then return
        {
            return;
        }
        if(size[ulpar_u]>=size[ulpar_v])  // if size of ultimate parent of u is greater than or equal to  v then make ultimate parent of v as u
        {
            parent[ulpar_v]=ulpar_u;
            size[ulpar_u]+=size[ulpar_v];  // increase the size of ultimate parent of u by adding size of ultimate parent of v
        }
        else  // else make ultimate parent of u as v
        {
            parent[ulpar_u]=ulpar_v;
            size[ulpar_v]+=size[ulpar_u];
        }

        comp--;  // decrease the number of component
       
    }

    int getComp()
    {
        return comp;  // return number of component
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
