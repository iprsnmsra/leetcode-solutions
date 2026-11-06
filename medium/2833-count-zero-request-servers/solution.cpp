#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        // Optimization: Fast I/O for execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // 1. Sort logs strictly by timestamp for chronological window sliding
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int q_size = queries.size();
        
        // 2. Offline Queries mapping: Store {query_time, original_index}
        vector<pair<int, int>> sorted_queries(q_size);
        for (int i = 0; i < q_size; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end()); // Sort queries chronologically

        vector<int> ans(q_size);
        
        // 3. Flat Frequency Array: Bypasses std::unordered_map overhead completely
        vector<int> freq(n + 1, 0);
        int active_servers = 0;
        
        int left = 0;
        int right = 0;
        int num_logs = logs.size();

        // 4. Two-Pointer Chronological Sweep
        for (int i = 0; i < q_size; ++i) {
            int q_time = sorted_queries[i].first;
            int q_idx = sorted_queries[i].second;

            int window_start = q_time - x;
            int window_end = q_time;

            // Expand window right edge to include new logs in [q - x, q]
            while (right < num_logs && logs[right][1] <= window_end) {
                int server_id = logs[right][0];
                if (freq[server_id] == 0) {
                    active_servers++;
                }
                freq[server_id]++;
                right++;
            }

            // Shrink window left edge to evict expired logs < q - x
            while (left < num_logs && logs[left][1] < window_start) {
                int server_id = logs[left][0];
                freq[server_id]--;
                if (freq[server_id] == 0) {
                    active_servers--;
                }
                left++;
            }

            // 5. Zero Request Servers = Total Servers - Active Servers in Window
            ans[q_idx] = n - active_servers;
        }

        return ans;
    }
};