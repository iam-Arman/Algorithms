#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * Weighted DSU (Disjoint Set Union)
 * * Supports:
 * 1. Path Compression (Operations are nearly O(1))
 * 2. Maintaining relative weights (distance) to the root.
 * 3. Handling constraints like: val[u] - val[v] = w
 * * T: The type of the weight (e.g., int, long long).
 */
template<typename T>
class WeightedDSU {
private:
    vector<int> parent;
    vector<int> sz;      // Size for union by rank/size
    vector<T> weight;    // weight[i] = val[i] - val[parent[i]]

public:
    // Constructor
    WeightedDSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // Fill 0, 1, 2...
        sz.assign(n + 1, 1);
        weight.assign(n + 1, 0); // Identity value (0 for sum, 0 for XOR)
    }

    // Returns {root, dist_to_root} where dist_to_root = val[i] - val[root]
    pair<int, T> find(int i) {
        if (parent[i] == i)
            return {i, 0};

        pair<int, T> root_info = find(parent[i]);
        
        parent[i] = root_info.first; // Path Compression
        
        // Update weight to be directly relative to the new root
        // For Sum: val[i] - val[root] = (val[i] - val[old_p]) + (val[old_p] - val[root])
        weight[i] = weight[i] + root_info.second; 
        
        // For XOR problems, use: weight[i] = weight[i] ^ root_info.second;
        
        return {parent[i], weight[i]};
    }

    // Adds constraint: val[u] - val[v] = w
    // Returns false if this contradicts existing information.
    bool unite(int u, int v, T w) {
        pair<int, T> root_u = find(u);
        pair<int, T> root_v = find(v);

        int ra = root_u.first;
        int rb = root_v.first;
        T dist_u = root_u.second; // val[u] - val[ra]
        T dist_v = root_v.second; // val[v] - val[rb]

        // Case 1: Already in the same component
        if (ra == rb) {
            // Check consistency: (val[u] - val[ra]) - (val[v] - val[ra]) should equal w
            // i.e., dist_u - dist_v == w
            if (dist_u - dist_v != w) {
                return false; // Contradiction!
            }
            return true;
        }

        // Case 2: Merge components
        // Attach smaller tree (ra) to larger tree (rb) to keep height small
        if (sz[ra] < sz[rb]) {
            swap(ra, rb);
            // If we swap roots, we must adjust the equation.
            // We wanted val[u] - val[v] = w.
            // Now we are conceptually effectively checking val[v] - val[u] = -w
            swap(u, v);
            w = -w; 
            swap(dist_u, dist_v);
        }

        // Attach rb to ra
        parent[rb] = ra;
        sz[ra] += sz[rb];
        
        // We need to set weight[rb] (which is val[rb] - val[ra])
        // Derivation:
        // 1. val[u] - val[v] = w
        // 2. val[u] = val[ra] + dist_u
        // 3. val[v] = val[rb] + dist_v
        // Substitute: (val[ra] + dist_u) - (val[rb] + dist_v) = w
        // val[ra] - val[rb] = w - dist_u + dist_v
        // val[rb] - val[ra] = dist_u - dist_v - w
        
        weight[rb] = dist_u - dist_v - w;
        // For XOR: weight[rb] = dist_u ^ dist_v ^ w;

        return true;
    }

    // Helper: Get diff (val[u] - val[v])
    // Only valid if u and v are in the same component
    T diff(int u, int v) {
        return find(u).second - find(v).second;
    }
};
