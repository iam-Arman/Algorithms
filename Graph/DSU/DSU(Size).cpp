class DSU{
public:
    vector<int> parent,size;
    int comp;

    DSU(int n)
    {
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        comp=n;
    }

    int find(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node]);
    }

    void unite(int u,int v)
    {
        int ulpar_u=find(u);
        int ulpar_v=find(v);
        if(ulpar_u==ulpar_v) return;
        if(size[ulpar_u] < size[ulpar_v]) swap(ulpar_u, ulpar_v);
        parent[ulpar_v] = ulpar_u;
        size[ulpar_u] += size[ulpar_v];
        comp--;
    }
};
