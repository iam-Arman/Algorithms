
class RollbackDSU {
private:
    vector<int> parent;
    vector<int> sz;
    
    struct Operation {
        int child;
        int parent;
        int old_size; 
    };
    vector<Operation> history;
    
    int num_components;

public:

    RollbackDSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); 
        sz.assign(n + 1, 1);
        num_components = n;
    }

    int find(int i) const {
        if (parent[i] == i)
            return i;
        return find(parent[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j]) 
                swap(root_i, root_j);
            
            history.push_back({root_j, root_i, sz[root_i]});

            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
            num_components--;
            
            return true;
        }
        return false;
    }

    int snapshot() const {
        return history.size();
    }

    void rollback(int snapshot_time) {
        while (history.size() > snapshot_time) {
            Operation op = history.back();
            history.pop_back();

            int child = op.child;
            int parent_node = op.parent;
            int old_size_parent = op.old_size;

            parent[child] = child; 
            sz[parent_node] = old_size_parent; 
            num_components++;
        }
    }

    int countComponents() const {
        return num_components;
    }
    
    int getSize(int x) const {
        return sz[find(x)];
    }
};

void solve()
{
   int n,q;
   cin>>n>>q;

   RollbackDSU ds(n);

   vector<pair<int,int> > version_edge(q+5);
   vector<vector<int> > version_child(q+5);
   vector<vector<array<int,3>> > version_queries(q+5);
   vector<int> ans(q+5,-1);

   vector<int> type(q+1);
   for(int i=0;i<q;i++)
   {
        int t,k,u,v;
        cin>>t>>k>>u>>v;
        if(t==0)
        {
            version_child[k+1].pb(i);
            version_edge[i]={u,v};
        }
        else
        {
            version_queries[k+1].pb({u,v,i});
        }
   }


   auto rec=[&](auto &&self,int node)->void
   {
        int snap=ds.snapshot();

        if(node!=-1)
        {
            ds.unite(version_edge[node].ff,version_edge[node].ss);
        }

        for(auto it : version_queries[node+1])
        {
            int u=it[0];
            int v=it[1];
            int ind=it[2];
            if(ds.find(u)==ds.find(v))
            {
                ans[ind]=1;
            }
            else ans[ind]=0;
        }

        for(auto it : version_child[node+1])
        {
            self(self,it);
        }
        ds.rollback(snap);
   };

   rec(rec,-1);

   for(int i=0;i<q;i++)
   {
        if(ans[i]!=-1) cout<<ans[i]<<el;
   }
  
}
