template<typename T>
struct WeightedDSU {
    vector<int> parent;
    vector<int> sz;
    vector<T> weight; // weight[i] = val[i] - val[parent[i]]

    WeightedDSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n + 1, 1);
        weight.assign(n + 1, 0);
    }

    // Returns {root, val[i] - val[root]}
    pair<int, T> find(int i) {
        if (parent[i] == i) {
            return {i, 0};
        }
        
        // Path compression
        pair<int, T> root_res = find(parent[i]);
        parent[i] = root_res.first;
        weight[i] += root_res.second; 
        
        return {parent[i], weight[i]};
    }

    // Unions u and v such that val[u] - val[v] = w
    // Returns true if successful, false if contradiction found
    bool unite(int u, int v, T w) {
        auto root_u = find(u);
        auto root_v = find(v);
        
        int ru = root_u.first;
        int rv = root_v.first;
        
        if (ru == rv) {
            return (root_u.second - root_v.second == w);
        }

        // Union by size
        if (sz[ru] < sz[rv]) {
            swap(ru, rv);
            swap(u, v);
            w = -w; // Update w for the swap: val[v] - val[u] = -w
            // Refresh cached weights after swap
            root_u = find(u);
            root_v = find(v);
        }

        // Attach rv to ru
        parent[rv] = ru;
        sz[ru] += sz[rv];
        
        // weight[rv] = val[rv] - val[ru]
        // Derived from: val[u] - val[v] = w
        weight[rv] = root_u.second - root_v.second - w;
        
        return true;
    }

    // Returns {true, val[u] - val[v]} if connected
    pair<bool, T> diff(int u, int v) {
        auto root_u = find(u);
        auto root_v = find(v);
        
        if (root_u.first != root_v.first) {
            return {false, 0};
        }
        
        return {true, root_u.second - root_v.second};
    }
};
