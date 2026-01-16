
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

    int find(int node)
    {
        if(node==parent[node])
        {
            return node;
        }

        return parent[node]=find(parent[node]);
    }

    void unite(int u,int v)
    {
        int ulpar_u=find(u);
        int ulpar_v=find(v);

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
