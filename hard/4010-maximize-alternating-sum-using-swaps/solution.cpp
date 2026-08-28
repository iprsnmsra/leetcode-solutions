#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        auto find = [&](auto& self, int i) -> int {
            int root = i;
            while (root != parent[root]) {
                parent[root] = parent[parent[root]]; 
                root = parent[root];
            }
            return root;
        };
        for (const auto& swap : swaps) {
            int u = find(find, swap[0]);
            int v = find(find, swap[1]);
            if (u != v) {
                parent[u] = v;
            }
        }
        vector<int> head(n, -1);
        vector<int> next_node(n, -1);
        vector<int> even_count(n, 0);

        for (int i = 0; i < n; ++i) {
            int root = find(find, i);

            next_node[i] = head[root];
            head[root] = i;
            if ((i & 1) == 0) {
                even_count[root]++;
            }
        }

        long long max_sum = 0;
        vector<int> buffer;
        buffer.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (head[i] != -1) {
                buffer.clear();
                int curr = head[i];
                while (curr != -1) {
                    buffer.push_back(nums[curr]);
                    curr = next_node[curr];
                }
                sort(buffer.begin(), buffer.end(), greater<int>());
                
                int E = even_count[i];
                for (int j = 0; j < buffer.size(); ++j) {
                    if (j < E) {
                        max_sum += buffer[j];
                    } else {
                        max_sum -= buffer[j];
                    }
                }
            }
        }

        return max_sum;
    }
};