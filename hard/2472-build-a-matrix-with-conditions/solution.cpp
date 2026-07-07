#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> row_order = topoSort(k, rowConditions);
        if (row_order.empty()) return {}; 

        vector<int> col_order = topoSort(k, colConditions);
        if (col_order.empty()) return {}; 
        vector<int> row_pos(k + 1);
        vector<int> col_pos(k + 1);
        
        for (int i = 0; i < k; ++i) {
            row_pos[row_order[i]] = i;
            col_pos[col_order[i]] = i;
        }
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int num = 1; num <= k; ++num) {
            matrix[row_pos[num]][col_pos[num]] = num;
        }

        return matrix;
    }

private:
    vector<int> topoSort(int k, const vector<vector<int>>& edges) {
        vector<vector<int>> adj(k + 1);
        vector<int> in_degree(k + 1, 0);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            in_degree[v]++;
        }
        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            for (int neighbor : adj[curr]) {
                if (--in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        if (order.size() == k) return order;
        return {};
    }
};