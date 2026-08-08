#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> adj(n);
        for (const auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<char> contaminated(n, 0);
        vector<int> stack;
        stack.reserve(n); 
        
        stack.push_back(k);
        contaminated[k] = 1;

        while (!stack.empty()) {
            int curr = stack.back();
            stack.pop_back();

            for (int next_node : adj[curr]) {
                if (!contaminated[next_node]) {
                    contaminated[next_node] = 1;
                    stack.push_back(next_node);
                }
            }
        }
        bool containment_breached = false;
        for (const auto& edge : invocations) {
            if (!contaminated[edge[0]] && contaminated[edge[1]]) {
                containment_breached = true;
                break;
            }
        }
        vector<int> result;
        result.reserve(n);
        
        if (containment_breached) {
            for (int i = 0; i < n; ++i) {
                result.push_back(i);
            }
        } else {
            for (int i = 0; i < n; ++i) {
                if (!contaminated[i]) {
                    result.push_back(i);
                }
            }
        }

        return result;
    }
};