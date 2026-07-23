#include <vector>
#include <unordered_map>
#include <numeric>
#include <iostream>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); 
    }
    
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX; 
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = source.size();
        UnionFind uf(n);

        for (const auto& swap : allowedSwaps) {
            uf.unite(swap[0], swap[1]);
        }

        unordered_map<int, unordered_map<int, int>> pool_inventory;
        
        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            pool_inventory[root][source[i]]++;
        }
        
        int hamming_distance = 0;

        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            int required_val = target[i];
            if (pool_inventory[root][required_val] > 0) {
                pool_inventory[root][required_val]--; 
            } else {
                hamming_distance++;
            }
        }
        
        return hamming_distance;
    }
};