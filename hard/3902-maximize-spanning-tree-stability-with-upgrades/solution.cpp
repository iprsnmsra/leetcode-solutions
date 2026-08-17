#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;
class DSU {
public:
    vector<int> parent, rank;
    int components;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); 
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
            components--;
            return true; 
        }
        return false;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<pair<int, int>> mandatory;
        vector<pair<int, pair<int, int>>> optional; 
        
        int min_mandatory_val = 2e9; 
        DSU initial_dsu(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], s = edge[2], must = edge[3];
            if (must == 1) {
                if (!initial_dsu.unite(u, v)) {
                    return -1;
                }
                mandatory.push_back({u, v});
                min_mandatory_val = min(min_mandatory_val, s);
            } else {
                optional.push_back({s, {u, v}});
            }
        }
        DSU check_dsu = initial_dsu;
        for (const auto& opt : optional) {
            check_dsu.unite(opt.second.first, opt.second.second);
        }
        if (check_dsu.components > 1) {
            return -1;
        }
        int low = 1, high = 200000;
        int max_stability = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid > min_mandatory_val) {
                high = mid - 1;
                continue;
            }

            DSU dsu(n);
            for (const auto& edge : mandatory) {
                dsu.unite(edge.first, edge.second);
            }

            int upgrades_used = 0;
            for (const auto& opt : optional) {
                if (opt.first >= mid) {
                    dsu.unite(opt.second.first, opt.second.second);
                }
            }
            for (const auto& opt : optional) {
                if (opt.first < mid && opt.first * 2 >= mid) {
                    if (dsu.unite(opt.second.first, opt.second.second)) {
                        upgrades_used++;
                    }
                }
            }
            if (dsu.components == 1 && upgrades_used <= k) {
                max_stability = mid; 
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }

        return max_stability;
    }
};