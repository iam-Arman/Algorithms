#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class BipartiteDSU {
private:
    vector<int> parent;
    vector<int> len; 
    vector<int> sz; 
    bool bipartite_flag;

public:
    BipartiteDSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        len.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        bipartite_flag = true;
    }

    pair<int, int> get(int a) {
        if (parent[a] == a)
            return {a, 0};
        
        pair<int, int> root_info = get(parent[a]);
        
        parent[a] = root_info.first;
        len[a] = (len[a] + root_info.second) % 2; 
        return {parent[a], len[a]};
    }

    bool unite(int u, int v) {
        pair<int, int> root_u = get(u);
        pair<int, int> root_v = get(v);

        int rootA = root_u.first;
        int rootB = root_v.first;
        int parity_u = root_u.second;
        int parity_v = root_v.second;

        if (rootA == rootB) {
            if (parity_u == parity_v) {
                bipartite_flag = false;
                return false; 
            }
            return true;
        }

        if (sz[rootA] < sz[rootB]) swap(rootA, rootB);
        
        parent[rootB] = rootA;
        sz[rootA] += sz[rootB];
        
        len[rootB] = (parity_u + parity_v + 1) % 2;
        
        return true;
    }

    bool isBipartite() const {
        return bipartite_flag;
    }
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    BipartiteDSU dsu(n);
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (!dsu.unite(u, v)) {
            cout << "Graph stops being bipartite at edge " << i << endl;
        }
    }

    if (dsu.isBipartite()) {
        cout << "Graph is bipartite" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
