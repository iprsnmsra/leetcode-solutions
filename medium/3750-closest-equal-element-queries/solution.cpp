#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();

        int max_val = 0;
        for (int num : nums) {
            if (num > max_val) max_val = num;
        }

        vector<int> head(max_val + 1, -1);
        vector<int> next_idx(n, -1);

        for (int i = n - 1; i >= 0; --i) {
            next_idx[i] = head[nums[i]];
            head[nums[i]] = i;
        }

        vector<int> min_dist(n, -1);
        for (int v = 0; v <= max_val; ++v) {
            if (head[v] == -1) continue;          
            if (next_idx[head[v]] == -1) continue; 
            vector<int> p;
            for (int i = head[v]; i != -1; i = next_idx[i]) {
                p.push_back(i);
            }

            int M = p.size();
            for (int k = 0; k < M; ++k) {
                int curr = p[k];
                int prev = p[(k - 1 + M) % M];
                int next = p[(k + 1) % M];

                int dist_prev = abs(curr - prev);
                dist_prev = min(dist_prev, n - dist_prev);

                int dist_next = abs(curr - next);
                dist_next = min(dist_next, n - dist_next);
                min_dist[curr] = min(dist_prev, dist_next);
            }
        }
        vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            result[i] = min_dist[queries[i]];
        }

        return result;
    }
};