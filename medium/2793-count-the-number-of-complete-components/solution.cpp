class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); 
        }

        vector<bool> visited(n, false);
        int complete_count = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int vertices = 0;
                int degree_sum = 0;
                dfs(i, adj, visited, vertices, degree_sum);
                if (degree_sum == vertices * (vertices - 1)) {
                    complete_count++;
                }
            }
        }

        return complete_count;
    }

private:
    void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited, int& vertices, int& degree_sum) {
        visited[u] = true;
        vertices++;
        degree_sum += adj[u].size(); 
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited, vertices, degree_sum);
            }
        }
    }
};