#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
    unordered_map<string, unordered_map<string, double>> graph;

    double dfs(const string& current, const string& target, unordered_set<string>& visited) {

        if (current == target) return 1.0;

        visited.insert(current);

        for (const auto& neighbor : graph[current]) {
            const string& next_node = neighbor.first;
            double edge_weight = neighbor.second;

            if (visited.find(next_node) == visited.end()) {

                double result = dfs(next_node, target, visited);

                if (result != -1.0) {
                    return edge_weight * result; 
                }
            }
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        for (int i = 0; i < equations.size(); ++i) {
            const string& u = equations[i][0];
            const string& v = equations[i][1];
            double val = values[i];

            graph[u][v] = val;          
            graph[v][u] = 1.0 / val;     
        }

        vector<double> results;

        for (const auto& query : queries) {
            const string& start = query[0];
            const string& target = query[1];
            if (graph.find(start) == graph.end() || graph.find(target) == graph.end()) {
                results.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                results.push_back(dfs(start, target, visited));
            }
        }

        return results;
    }
};