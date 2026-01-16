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
